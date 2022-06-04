//#pragma pack(1)

#include "pch.h"
#include "bmpReader.h"

#include <fstream>

FileHeader readBmpFile(std::ifstream &bmpFile)
{
    FileHeader fileHeader;

    bmpFile.read((char*)&fileHeader.type, sizeof(fileHeader.type));
    bmpFile.read((char*)&fileHeader.size, sizeof(fileHeader.size));
    bmpFile.read((char*)&fileHeader.reserved1, sizeof(fileHeader.reserved1));
    bmpFile.read((char*)&fileHeader.reserved2, sizeof(fileHeader.reserved2));
    bmpFile.read((char*)&fileHeader.offset, sizeof(fileHeader.offset));

    bmpFile.seekg(14, std::ios::beg);

    bmpFile.read((char*)&fileHeader.Picture.biSize, sizeof(fileHeader.Picture.biSize));
    bmpFile.read((char*)&fileHeader.Picture.biWidth, sizeof(fileHeader.Picture.biWidth));
    bmpFile.read((char*)&fileHeader.Picture.biHeight, sizeof(fileHeader.Picture.biHeight));
    bmpFile.read((char*)&fileHeader.Picture.biPlanes, sizeof(fileHeader.Picture.biPlanes));
    bmpFile.read((char*)&fileHeader.Picture.biBitCount, sizeof(fileHeader.Picture.biBitCount));
    bmpFile.read((char*)&fileHeader.Picture.biCompression, sizeof(fileHeader.Picture.biCompression));
    bmpFile.read((char*)&fileHeader.Picture.biSizeImage, sizeof(fileHeader.Picture.biSizeImage));
    bmpFile.read((char*)&fileHeader.Picture.biXPelsPerMeter, sizeof(fileHeader.Picture.biXPelsPerMeter));
    bmpFile.read((char*)&fileHeader.Picture.biYPelsPerMeter, sizeof(fileHeader.Picture.biYPelsPerMeter));
    bmpFile.read((char*)&fileHeader.Picture.biClrUsed, sizeof(fileHeader.Picture.biClrUsed));
    bmpFile.read((char*)&fileHeader.Picture.biClrImportant, sizeof(fileHeader.Picture.biClrImportant));

    return fileHeader;
}