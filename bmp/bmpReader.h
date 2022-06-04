#pragma once

#include "pch.h"
#include <fstream>

struct ColorsRGB {
    char R, G, B;
} __attribute__((__packed__));

struct PictureHeader {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
    ColorsRGB rgb;
} __attribute__((__packed__));

struct FileHeader {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
    PictureHeader Picture;
} __attribute__((__packed__));


FileHeader readBmpFile(std::ifstream &bmpFile);
