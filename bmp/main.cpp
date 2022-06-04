#include "pch.h"
#include "bmpReader.h"

#include <iostream>

int main(int arc, char* argv[])
{
    std::string filePath(argv[1]);
    std::ifstream bmpFile(filePath, std::ios::binary);

    if (!bmpFile)
    {
        std::cerr << "The specified file cannot be opened: " << filePath << std::endl;
        return -1;
    }

    std::cout << "File '" << filePath << "' opened!" << std::string(2, '\n');

    FileHeader bmpFileInfo = readBmpFile(bmpFile);

    std::cout << "INFORMACJE O BITMAPIE!" << std::endl;
    std::cout << "Typ: " << std::hex << bmpFileInfo.type << std::endl;
    std::cout << "Rozmiar pliku: " << std::dec << bmpFileInfo.size << " bajtow" << std::endl;
    std::cout << "Zarezerwowane1: " << std::dec << bmpFileInfo.reserved1 << std::endl;
    std::cout << "Zarezerwowane2: " << std::dec << bmpFileInfo.reserved2 << std::endl;
    std::cout << "Pozycja danych obrazkowych: " << std::dec << bmpFileInfo.offset << std::endl << std::endl;
    std::cout << "Wielkosc naglowka informacyjnego: " << std::dec << bmpFileInfo.Picture.biSize << std::endl;
    std::cout << "Szerokosc: " << std::dec << bmpFileInfo.Picture.biWidth << " pikseli" << std::endl;
    std::cout << "Wysokosc: " << std::dec << bmpFileInfo.Picture.biHeight << " pikseli" << std::endl;
    std::cout << "Liczba platow: " << std::dec << bmpFileInfo.Picture.biPlanes << std::endl;
    std::cout << "Liczba bitow na piksel: " << std::dec << bmpFileInfo.Picture.biBitCount << " (1, 4, 8, or 24)" << std::endl;
    std::cout << "Kompresja: " << std::dec << bmpFileInfo.Picture.biCompression << " (0=none, 1=RLE-8, 2=RLE-4)" << std::endl;
    std::cout << "Rozmiar samego rysunku: " << std::dec << bmpFileInfo.Picture.biSizeImage << std::endl;
    std::cout << "Rozdzielczosc pozioma: " << std::dec << bmpFileInfo.Picture.biXPelsPerMeter << std::endl;
    std::cout << "Rozdzielczosc pionowa: " << std::dec << bmpFileInfo.Picture.biYPelsPerMeter << std::endl;
    std::cout << "Liczba kolorow w palecie: " << std::dec << bmpFileInfo.Picture.biClrUsed << std::endl;
    std::cout << "Wazne kolory w palecie: " << std::dec << bmpFileInfo.Picture.biClrImportant << std::endl;

    std::cout << std::endl << std::string(25, '*') << std::endl;

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
