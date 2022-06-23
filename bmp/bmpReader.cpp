#include "pch.h"
#include "bmpReader.h"

#include <fstream>

FileHeader readFileHeader(std::ifstream &bmpFile)
{
    FileHeader fileHeader;

    bmpFile.seekg(0, bmpFile.beg);
    bmpFile.read((char*)&fileHeader.type, sizeof(fileHeader.type));
    bmpFile.read((char*)&fileHeader.size, sizeof(fileHeader.size));
    bmpFile.read((char*)&fileHeader.reserved1, sizeof(fileHeader.reserved1));
    bmpFile.read((char*)&fileHeader.reserved2, sizeof(fileHeader.reserved2));
    bmpFile.read((char*)&fileHeader.offset, sizeof(fileHeader.offset));

    return fileHeader;
}

PictureHeader readPictureHeader(std::ifstream &bmpFile)
{
    PictureHeader pictureHeader;

    bmpFile.seekg(sizeof(FileHeader), std::ios::beg);

    bmpFile.read((char*)&pictureHeader.size, sizeof(pictureHeader.size));
    bmpFile.read((char*)&pictureHeader.width, sizeof(pictureHeader.width));
    bmpFile.read((char*)&pictureHeader.height, sizeof(pictureHeader.height));
    bmpFile.read((char*)&pictureHeader.planes, sizeof(pictureHeader.planes));
    bmpFile.read((char*)&pictureHeader.bitCount, sizeof(pictureHeader.bitCount));
    bmpFile.read((char*)&pictureHeader.compression, sizeof(pictureHeader.compression));
    bmpFile.read((char*)&pictureHeader.sizeImage, sizeof(pictureHeader.sizeImage));
    bmpFile.read((char*)&pictureHeader.xPixelsPerMeter, sizeof(pictureHeader.xPixelsPerMeter));
    bmpFile.read((char*)&pictureHeader.yPixelsPerMeter, sizeof(pictureHeader.yPixelsPerMeter));
    bmpFile.read((char*)&pictureHeader.colorsUsed, sizeof(pictureHeader.colorsUsed));
    bmpFile.read((char*)&pictureHeader.colorsImportant, sizeof(pictureHeader.colorsImportant));

    return pictureHeader;
}

ColorsHeader readColorsHeader(std::ifstream &bmpFile)
{
    ColorsHeader colorsHeader;

    bmpFile.seekg(sizeof(FileHeader), std::ios::beg);

    //bmpFile.read((char*)&pictureHeader.size, sizeof(pictureHeader.size));

    return colorsHeader;
}
