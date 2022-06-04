#include "pch.h"
#include "bmpReader.h"

#include <fstream>

FileHeader readBmpFile(std::string filePath)
{
    FileHeader fileHeader;
    std::ifstream bmp(filePath, std::ios::binary);

    if (!bmp)
    {
        // throw
    }
    bmp.read((char*)&fileHeader.bfType, sizeof(fileHeader.bfType));
    bmp.read((char*)&fileHeader.bfSize, sizeof(fileHeader.bfSize));
    bmp.read((char*)&fileHeader.bfReserved1, sizeof(fileHeader.bfReserved1));
    bmp.read((char*)&fileHeader.bfReserved2, sizeof(fileHeader.bfReserved2));
    bmp.read((char*)&fileHeader.bfOffBits, sizeof(fileHeader.bfOffBits));

    //fread(&File.bfType, sizeof(File.bfType), 1, f);

    return fileHeader;
}