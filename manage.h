#ifndef manage_h
#define manage_h

using namespace std;

std::string bands[12] = { "R", "G", "I", "U", "Z", "F378", "F395", "F410", "F430", "F515", "F660", "F861" };

struct files{
    std::string filename[12];
    std::string band[12];
    fitsfile *fits;
    int naxes0;
    int naxes1;
};  


#endif /* manage_h */