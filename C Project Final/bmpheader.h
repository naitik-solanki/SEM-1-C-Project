struct BITMAP_header{                         //This is the bitmap header
    char name1,name2;                         //name1 and name2 represents the file type, for BMP these are always 'B' and 'M' repectively
    unsigned int size;                        //This is the size of the BMP image (excluding BITMAP header)
    int garbage;                              //These are the reserved values and are of no use to us
    unsigned int image_offset;                //This the address of starting of image body data
};

struct DIB_header{                            
	unsigned int header_size;                 //Size of DIB header (always 12)
	unsigned int width;                       //Bitmap width in pixels
	unsigned int height;                      //Bitmap height in pixels
	unsigned short int colorplanes;           //Number of colour planes in BMP image (must be 1)
	unsigned short int bitsperpixel;          //Number of bits per pixel in BMP image (must be 24 in our case)
	unsigned int compression;                 //Compression method being used (0 for non compressed image)
	unsigned int image_size;                  //This is the size of the raw bitmap data
    double garbage1;                          //These values depend on the image formation method being used and are of no use to us 
    double garbage2;
};