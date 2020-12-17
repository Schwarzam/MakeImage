#include <string.h>
#include <stdio.h>
#include <iostream>
#include "fitsio.h"
#include <stdlib.h>
#include "manage.h"

using namespace std;

int main(int argc, char *argv[]){   

    string *path;
    path = (string*)malloc(120);  
    *path = "/Users/oliveira/MakeImage/SPLUS-cuts/SPLUS-s24s32-48.753343--30.708032-300";
    
    files *newfile;
    newfile = (files*)malloc(1024);   

    string *append_path; append_path = (string*)malloc(120);  
    
    for(int i = 0; i < 12; i++){
        *append_path = *path + "_" + bands[i] + ".fits.fz";

        newfile -> band[i] = bands[i];
        newfile -> filename[i] = *append_path;

        cout << newfile -> filename[i] << " " << newfile -> band[i] << endl;
    }

    open_file(newfile -> filename[1]);

    return 0;
}
