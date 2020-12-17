#include <string.h>
#include <stdio.h>
#include <iostream>
#include "fitsio.h"
#include <stdlib.h>
#include <vector> 

#include "manage.h"

using namespace std;

int main(int argc, char *argv[]){   
    files arr;
    
    string *path;
    path = (string*)malloc(120);  
    *path = "/Users/oliveira/MakeImage/SPLUS-cuts/SPLUS-s24s32-48.753343--30.708032-300";

    files *newfile;
    newfile = (files*)malloc(1024);   

    string *append_path; append_path = (string*)malloc(120); 

    fitsfile *fptr; 
    int status = 0;

    for(int i = 0; i < 12; i++){
        *append_path = *path + "_" + bands[i] + ".fits.fz";

        newfile -> band[i] = bands[i];
        newfile -> filename[i] = *append_path;

        cout << newfile -> filename[i] << " " << newfile -> band[i] << endl;

        char *cstr = new char[newfile -> filename[i].length() + 1];
        strcpy(cstr, newfile -> filename[i].c_str());

        fits_open_file(&fptr, cstr, READONLY, &status);
        newfile -> fits[i] = *fptr;
    }

    open_file(newfile -> filename[1], *newfile);

    return 0;
}
