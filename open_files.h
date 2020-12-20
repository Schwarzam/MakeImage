#ifndef open_files_h
#define open_files_h

using namespace std;

fitsfile *hduR; 
fitsfile *hduG; 
fitsfile *hduI; 
fitsfile *hduU; 
fitsfile *hduZ; 
fitsfile *hduF378; 
fitsfile *hduF395; 
fitsfile *hduF410; 
fitsfile *hduF430; 
fitsfile *hduF515;
fitsfile *hduF660; 
fitsfile *hduF861; 


int open_files(string path, files newfile){

    char *cstr = new char[path.length() + 1];
    strcpy(cstr, path.c_str());

    fitsfile *fptr;   /* FITS file pointer, defined in fitsio.h */
    int hdunums = 0;
    int status = 0;   /* CFITSIO status value MUST be initialized to zero! */

    //char p = "/Users/oliveira/MakeImage/SPLUS-cuts/SPLUS-s24s32-48.753343--30.708032-300_G.fits.fz";
    //if (!fits_open_file(&fptr, "/home/gustavo/Documents/MakeImage/STRIPE82-0003_R_swp.fz", READONLY, &status))
    fits_open_file(&fptr, cstr, READONLY, &status);

    fits_get_num_hdus(fptr, &hdunums, &status);
    int currhdu;
    fits_get_hdu_num(fptr, &currhdu);

    if (hdunums == 2 & currhdu == 1){
        int *hdutype = NULL;
        int nmove = 1;
        fits_movrel_hdu(fptr, nmove, hdutype, &status);
        fits_get_hdu_num(fptr, &currhdu);
        }

    if (status) fits_report_error(stderr, status); /* print any error message */
    return(status);
}


#endif /* open_files_h */
