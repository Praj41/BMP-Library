#include <fstream>

#include "bitmap_img.h"

bitmap_img::bitmap_img(uint32_t height, uint32_t width, uint8_t **bitmap)
        : data(bitmap), _height(height), _width(width), _size(122 + (height * width * 4)), _imgSize(height * width * 4) {

    BMPHeader = (unsigned char*)calloc(14, 1);
    BMPInfoHeader = (unsigned char*)calloc(108, 1);
}

void bitmap_img::setBmpHeader() {
    BMPHeader[0] = 'B', BMPHeader[1] = 'M',
    BMPHeader[2] = (unsigned char)(_size), BMPHeader[3] = (unsigned char)(_size >> 8),
    BMPHeader[4] = (unsigned char)(_size >> 16), BMPHeader[5] = (unsigned char)(_size >> 24),
    BMPHeader[10] = 122;
}

void bitmap_img::setBmpInfoHeader() {
    BMPInfoHeader[0] = 108,
    BMPInfoHeader[4] = (unsigned char)(_width), BMPInfoHeader[5] = (unsigned char)(_width >> 8),
    BMPInfoHeader[6] = (unsigned char)(_width >> 16), BMPInfoHeader[7] = (unsigned char)(_width >> 24),
    BMPInfoHeader[8] = (unsigned char)(_height), BMPInfoHeader[9] = (unsigned char)(_height >> 8),
    BMPInfoHeader[10] = (unsigned char)(_height >> 16), BMPInfoHeader[11] = (unsigned char)(_height >> 24),
    BMPInfoHeader[12] = 1, BMPInfoHeader[14] = 32, BMPInfoHeader[16] = 3,
    BMPInfoHeader[20] = (unsigned char)(_imgSize), BMPInfoHeader[21] = (unsigned char)(_imgSize >> 8),
    BMPInfoHeader[22] = (unsigned char)(_imgSize >> 16), BMPInfoHeader[23] = (unsigned char)(_imgSize >> 24),
    BMPInfoHeader[42] = BMPInfoHeader[45] = BMPInfoHeader[48] = BMPInfoHeader[55] = 0xFF,
    BMPInfoHeader[56] = 0x20, BMPInfoHeader[57] = 0x6E, BMPInfoHeader[58] = 0x69, BMPInfoHeader[59] = 0x57;
}

void bitmap_img::write() {

    std::ofstream img("img.bmp", std::ios::binary);

    setBmpHeader(), setBmpInfoHeader();

    img.write((char *)BMPHeader, 14);
    img.write((char *)BMPInfoHeader, 108);

    img.write((char *)(*data), _imgSize);

    img.close();
}

uint32_t bitmap_img::getImgSize() const {
    return _imgSize;
}
