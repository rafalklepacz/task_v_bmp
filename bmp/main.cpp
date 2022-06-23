#include "pch.h"
#include "bmpReader.h"
#include "bmpWriter.h"

#include <iostream>

void printSeparator()
{
    std::cout << std::string(40, '=') << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << "sizeof(FileHeader)=" << sizeof(FileHeader) << std::endl;
    std::cout << "sizeof(PictureHeader)=" << sizeof(PictureHeader) << std::endl;
    std::cout << "sizeof(ColorsRGB)=" << sizeof(ColorsHeader) << std::endl;

    std::string filePath(argv[1]);
    std::ifstream bmpFile(filePath, std::ios::binary);

    if (!bmpFile)
    {
        std::cerr << "The specified file cannot be opened: " << filePath << std::endl;
        return -1;
    }

    std::cout << "File '" << filePath << "' opened!" << std::string(2, '\n');

    auto fileHeader = readFileHeader(bmpFile);
    std::cout << "INFORMACJE O BITMAPIE!" << std::endl;
    std::cout << "Typ: " << std::hex << fileHeader.type << std::endl;
    std::cout << "Rozmiar pliku: " << std::dec << fileHeader.size << " bajtow" << std::endl;
    std::cout << "Zarezerwowane1: " << std::dec << fileHeader.reserved1 << std::endl;
    std::cout << "Zarezerwowane2: " << std::dec << fileHeader.reserved2 << std::endl;
    std::cout << "Pozycja danych obrazkowych: " << fileHeader.offset << std::endl << std::endl;

    printSeparator();

    auto pictureHeader = readPictureHeader(bmpFile);
    std::cout << "Wielkosc naglowka informacyjnego: " << std::dec << pictureHeader.size << std::endl;
    std::cout << "Szerokosc: " << std::dec << pictureHeader.width << " pikseli" << std::endl;
    std::cout << "Wysokosc: " << std::dec << pictureHeader.height << " pikseli" << std::endl;
    std::cout << "Liczba platow: " << std::dec << pictureHeader.planes << std::endl;
    std::cout << "Liczba bitow na piksel: " << std::dec << pictureHeader.bitCount << " (1, 4, 8, or 24)" << std::endl;
    std::cout << "Kompresja: " << std::dec << pictureHeader.compression << " (0=none, 1=RLE-8, 2=RLE-4)" << std::endl;
    std::cout << "Rozmiar samego rysunku: " << std::dec << pictureHeader.sizeImage << std::endl;
    std::cout << "Rozdzielczosc pozioma: " << std::dec << pictureHeader.xPixelsPerMeter << std::endl;
    std::cout << "Rozdzielczosc pionowa: " << std::dec << pictureHeader.yPixelsPerMeter << std::endl;
    std::cout << "Liczba kolorow w palecie: " << std::dec << pictureHeader.colorsUsed << std::endl;
    std::cout << "Wazne kolory w palecie: " << std::dec << pictureHeader.colorsImportant << std::endl;

    printSeparator();

    std::cout << "Trwa tworzenie negatywu..." << std::endl;
    createNegative(bmpFile);
    std::cout << "Utworzono negatyw!" << std::endl;

    bmpFile.close();

    return 0;
}
