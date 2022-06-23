#pragma once

#include "pch.h"

#pragma pack(push, 1)

struct ColorsHeader {
    char r, g, b;
};

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
};

struct FileHeader {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
};

#pragma pack(pop)
