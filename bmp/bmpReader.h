#pragma once

#include "pch.h"
#include "bmpInfo.h"
#include <fstream>




FileHeader readFileHeader(std::ifstream &bmpFile);
PictureHeader readPictureHeader(std::ifstream &bmpFile);
ColorsHeader readColorsHeader(std::ifstream& bmpFile);