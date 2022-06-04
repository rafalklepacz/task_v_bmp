#pragma once

#include "pch.h"
#include <iostream>

struct ColorsRGB {
    char R;
    char G;
    char B;
};

struct PictureHeader {
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
    ColorsRGB rgb;
};

struct FileHeader {
    short bfType;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
    PictureHeader picture;
};


FileHeader readBmpFile(std::string filePath);