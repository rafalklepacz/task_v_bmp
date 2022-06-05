#pragma once

#include "pch.h"
#include <fstream>

//#pragma pack(push, 1)
struct ColorsHeader {
    char r, g, b;
} __attribute__((__packed__));

struct PictureHeader {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} __attribute__((__packed__));

struct FileHeader {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} __attribute__((__packed__));

//#pragma pack(pop)


FileHeader readFileHeader(std::ifstream &bmpFile);
PictureHeader readPictureHeader(std::ifstream &bmpFile);
ColorsHeader readColorsHeader(std::ifstream &bmpFile);
