#include "image.h"
#include "Matrix.h"
#include "processing.h"
#include <cassert>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    if (argc > 5 || argc < 4)
    {
        cout << "Invalid number of arguments" << endl;
        return 1;
    }
    string arg1, arg2, arg3, arg4;
    arg1 = argv[1];
    arg2 = argv[2];
    
    ifstream input(arg1);

    if(!input.is_open())
    {
        cout << "Error opening file: " << arg1 << endl;
        return 1;
    }
    Image *img = new Image;
    Image_init(img, input);

    int newWidth = atoi(argv[3]);
    int newHeight;

    if (argc == 4)
    {
        newHeight = Image_height(img);
    }
    else
    {
        newHeight = atoi(argv[4]);
    }

    if (newHeight < 0 || newHeight > Image_height(img) || newWidth < 0 || newWidth > Image_width(img))
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    }
    
    
    seam_carve_width(img, newWidth);
    seam_carve_height(img, newHeight);

    ofstream output(arg2);
    
    Image_print(img, output);
}