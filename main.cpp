#include <string.h>
#include <stdio.h>
#include <iostream>
#include "fitsio.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){   
    fitsfile *fptr;   /* FITS file pointer, defined in fitsio.h */
    fptr = (fitsfile*)malloc(100000);
    int hdunums = 0;
    int status = 0;   /* CFITSIO status value MUST be initialized to zero! */

    int bitpix, naxis, ii, anynul;
    long naxes[2] = {1,1}, fpixel[2] = {1,1};
    double *pixels;
    char format[20], hdformat[20];


    if (!fits_open_file(&fptr, "/home/gustavo/Documents/MakeImage/STRIPE82-0003_R_swp.fz", READONLY, &status))
    
        fits_get_num_hdus(fptr, &hdunums, &status);
        cout << "number of HDUs:";cout << hdunums << endl;

        //current HDU
        int currhdu = 0;
        fits_get_hdu_num(fptr, &currhdu);
        cout << "Current HDU:";cout << currhdu <<endl;

        //Go to different HDU
        int *hdutype = NULL;
        int nmove = 1;
        fits_movrel_hdu(fptr, nmove, hdutype, &status);

        fits_get_hdu_num(fptr, &currhdu);
        cout << "Current HDU:";cout << currhdu <<endl;

    {
        if (!fits_get_img_param(fptr, 2, &bitpix, &naxis, naxes, &status) )
        {
          if (naxis > 2 || naxis == 0)
             printf("Error: only 1D or 2D images are supported\n");
          else
          {
            /* get memory for 1 row */
            pixels = (double *) malloc(naxes[0] * sizeof(double));

            if (pixels == NULL) {
                printf("Memory allocation error\n");
                return(1);
            }

            if (bitpix > 0) {  /* set the default output format string */
               strcpy(hdformat, " %7d");
               strcpy(format,   " %7.0f");
            } else {
               strcpy(hdformat, " %15d");
               strcpy(format,   " %15.5f");
            }

            printf("\n      ");          /* print column header */
            for (ii = 1; ii <= naxes[0]; ii++)
               printf(hdformat, ii);
            printf("\n");                /* terminate header line */

            /* loop over all the rows in the image, top to bottom */
            for (fpixel[1] = naxes[1]; fpixel[1] >= 1; fpixel[1]--)
            {
               if (fits_read_pix(fptr, TDOUBLE, fpixel, naxes[0], NULL,
                    pixels, NULL, &status) )  /* read row of pixels */
                  break;  /* jump out of loop on error */

                 /* print row number */
            //    for (ii = 0; ii < naxes[0]; ii++)
            //       printf(format, pixels[ii]);   /* print each value  */
            //    printf("\n");                    /* terminate line */
                for (ii = 0; ii < naxes[0]; ii++)
                    printf(format, pixels[ii]); 
                printf("\n");     
            }
            free(pixels);
          }
        }
        fits_close_file(fptr, &status);
    } 

    if (status) fits_report_error(stderr, status); /* print any error message */
    return(status);
}
