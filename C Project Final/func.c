#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma pack(1)                                   //This is used for reading byte by byte (padding)
#include "icoheader.h"
#include "bmpheader.h"
void convert(char *t,int x){
    int i,j,a,b,k=0,p=0,q;                        //Defining necessary variable
    char y[100],z[100];
    for(;k<x;k+=1){
        y[k]=*(t+k);
    }
    FILE *fp=fopen(y,"rb");                       //Opening of ICO file
    struct ico_header header;                     //Defining "header" as ico header
    fread(&header,6,1,fp);                        //Reading the ico file header
    struct icondirentory idr;                     //Defining "idr" as icon direntry
    fread(&idr,16,1,fp);                          //Reading the ico file icon direntry
    struct DIB_header dibheader;                  //Defining "dibheader" as DIB header
    fread(&dibheader,40,1,fp);                    //Reading the dib header
    if(idr.width==0)                              /*When width(height) is negative or zero 256 is added, if it is positive it is passed on*/
        a=256;                                                              
    if(idr.width>0)
        a=idr.width;
    if(idr.width<0)
        a=256+idr.width;
    if(idr.height==0)
        b=256;
    if(idr.height>0)
        b=idr.height;
    if(idr.height<0)
        b=256+idr.height;
    dibheader.height=b;
    dibheader.width=a;
    unsigned char Pixel[b][a][4];                   //Defining the pixel array which stores the ICO file data in which each pixel has four component, namely RGBA
    unsigned char Pixel24[b][a][3];                 //Defining the pixel array which stores the data that is to be given to the BMP file in which each pixel has three components namely RGB
    for(i=0;i<b;i++){                               //We are writing RGB component of Pixel array in Pixel24 array
        for(j=0;j<a;j++){
            fread(Pixel[i][j], 1, 4, fp);
            Pixel24[i][j][0]=Pixel[i][j][0];        //This gives Blue colour
            Pixel24[i][j][1]=Pixel[i][j][1];        //This gives Green colour
            Pixel24[i][j][2]=Pixel[i][j][2];        //This gives Red colour
        };
    };
    q=strlen(y);
    y[q-1]='p';
    y[q-2]='m';
    y[q-3]='b';
    FILE *f1=fopen(y,"wb");                         //Opening or formation of the created BMP file
    struct BITMAP_header header1;                   //Defining the BITMAP header
    header1.name1='B';
    header1.name2='M';
    header1.size=idr.size;
    header1.garbage=0;
    header1.image_offset=54;
    fwrite(&header1, 14, 1, f1);                    //Writing on header of BMP file
    dibheader.bitsperpixel=24;                      //Defining the bits per pixel of BMP file
    fwrite(&dibheader, 40, 1, f1);                  //Writing on DIB header of BMP file
    fwrite(Pixel24, b*a*3, 1, f1);                  //Writing in body of BMP file using data stored in Pixel24
    fclose(fp);                                     //Closing of the ICO file opened
    fclose(f1);                                     //Closing of the BMP file opened/created
    return;
};