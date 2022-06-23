#include "pch.h"
#include "bmpInfo.h"
#include "bmpReader.h"
#include "bmpWriter.h"

#include <fstream>
#include <iostream>

void createNegative(std::ifstream& bmpFile)
{
    auto fileHeader = readFileHeader(bmpFile);
    auto pictureHeader = readPictureHeader(bmpFile);

    std::ofstream negativeFile("negative.bmp", std::ios::binary);

    if (!negativeFile)
    {
        std::cerr << "Cannot create negative file!" << std::endl;
        return;
    }

    negativeFile.seekp(0, std::ios::beg);
    negativeFile.write((const char*)&fileHeader, sizeof(fileHeader));
    negativeFile.write((const char*)&pictureHeader, sizeof(pictureHeader));
    negativeFile.seekp(sizeof(fileHeader.offset), std::ios::beg);

    int bmpImg;
    for (int i = fileHeader.offset; i < fileHeader.size; i++)
    {
        bmpFile.seekg(i, std::ios::beg);
        negativeFile.seekp(i, std::ios::beg);
        bmpFile.read((char*)&bmpImg, 1);
        bmpImg = INT_MAX - bmpImg;
        negativeFile.write((char*)&bmpImg, 1);
    }

    negativeFile.close();
}