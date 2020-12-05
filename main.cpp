#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <CCfits>
#include <iostream>

//CCfits documentation
//https://heasarc.gsfc.nasa.gov/fitsio/CCfits/html/cookbook.html

//sudo update-alternatives --config gcc


using namespace std;
using namespace CCfits;

int readImage(){

    std::unique_ptr<FITS> pInfile(new FITS("/home/gustavo/Documents/MakeImage/STRIPE82-0003_R_swp.fz",Read,true));

    PHDU& image = pInfile->pHDU(); 

    std::valarray<unsigned long>  contents;

    // read all user-specifed, coordinate, and checksum keys in the image
    image.readAllKeys();
    image.read(contents);

    // this doesn't print the data, just header info.
    std::cout << image << std::endl;

    cout << "salve" << endl;
    std::cout << std::endl;
    return 0;   
}

int main(){
    
    readImage();

    cout << "test" << endl;
    return 0;
}
