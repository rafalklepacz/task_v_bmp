#include "pch.h"
#include "bmpReader.h"

#include <iostream>

void printSeparator()
{
    std::cout << std::string(40, '=') << std::endl;
}

int main(int arc, char* argv[])
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

    FileHeader fileHeader = readFileHeader(bmpFile);
    std::cout << "INFORMACJE O BITMAPIE!" << std::endl;
    std::cout << "Typ: " << std::hex << fileHeader.type << std::endl;
    std::cout << "Rozmiar pliku: " << std::dec << fileHeader.size << " bajtow" << std::endl;
    std::cout << "Zarezerwowane1: " << std::dec << fileHeader.reserved1 << std::endl;
    std::cout << "Zarezerwowane2: " << std::dec << fileHeader.reserved2 << std::endl;
    std::cout << "Pozycja danych obrazkowych: " << std::dec << fileHeader.offset << std::endl << std::endl;

    printSeparator();

    PictureHeader pictureHeader = readPictureHeader(bmpFile);
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

    // FILE* w = fopen("negative.bmp", "wb");
    // if (w == nullptr)
    // {
    //     printf("\n\n Can't open the file");
    //     return -1;
    // }
    // else
    // {
    //     printf("\n\n File w opened!");
    // }

    // fseek(w, 0, SEEK_SET);
    // fwrite(&BmpFile.bfType, sizeof(BmpFile.bfType), 1, w);
    // fwrite(&BmpFile.bfSize, sizeof(BmpFile.bfSize), 1, w);
    // fwrite(&BmpFile.bfReserved1, sizeof(BmpFile.bfReserved1), 1, w);
    // fwrite(&BmpFile.bfReserved2, sizeof(BmpFile.bfReserved2), 1, w);
    // fwrite(&BmpFile.bfOffBits, sizeof(BmpFile.bfOffBits), 1, w);

    // fseek(w, 14, SEEK_SET);
    // fwrite(&Picture.biSize, sizeof(Picture.biSize), 1, w);
    // fwrite(&Picture.biWidth, sizeof(Picture.biWidth), 1, w);
    // fwrite(&Picture.biHeight, sizeof(Picture.biHeight), 1, w);
    // fwrite(&Picture.biPlanes, sizeof(Picture.biPlanes), 1, w);
    // fwrite(&Picture.biBitCount, sizeof(Picture.biBitCount), 1, w);
    // fwrite(&Picture.biCompression, sizeof(Picture.biCompression), 1, w);
    // fwrite(&Picture.biSizeImage, sizeof(Picture.biSizeImage), 1, w);
    // fwrite(&Picture.biXPelsPerMeter, sizeof(Picture.biXPelsPerMeter), 1, w);
    // fwrite(&Picture.biYPelsPerMeter, sizeof(Picture.biYPelsPerMeter), 1, w);
    // fwrite(&Picture.biClrUsed, sizeof(Picture.biClrUsed), 1, w);
    // fwrite(&Picture.biClrImportant, sizeof(Picture.biClrImportant), 1, w);

    // fseek(w, sizeof(BmpFile.bfOffBits), SEEK_SET);

    // int bmpImg;
    // for (int i = BmpFile.bfOffBits; i < BmpFile.bfSize; i++)
    // {
    //     fseek(f, i, SEEK_SET);
    //     fseek(w, i, SEEK_SET);
    //     fread(&bmpImg, 3, 1, f);
    //     bmpImg = INT_MAX - bmpImg; //Tworzymy negatyw
    //     fwrite(&bmpImg, 3, 1, w);
    // }

    printf("\n");
    bmpFile.close();
    //fclose(w);

    return 0;
}
