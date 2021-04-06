struct ico_header{                            //This structure stores the ico file header
    short int reserved;                       //Reserved is always 0
    short int specifier;                      //specifier is 1 for ico images 2 for cur images
    short int number;                         //number represents number of images in ico file(png or bmp)
};

struct icondirentory{                         //This is the icon direntry
    char width;                               //This gives the width of the image
    char height;                              //This gives the height of the image
    char color;                               //Specifies number of colors in the color palette
    char reserved;                            //This is a reserved value and is always 0
    short int si1;                            //This signifies number of colour planes. As this is a 2D image so number of colour planes will be one
    short int bpp;                            //This gives bits per pixel. This is always 32 for ICO images.
    int size;                                 //This is the size of ICO image (excluding icon direntry and ico header)
    int offset;                               //This the address of starting of image body data
};