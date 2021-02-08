#ifndef BITMAPIMAGE_BITMAP_IMG_H
#define BITMAPIMAGE_BITMAP_IMG_H

#include <cstdint>

class bitmap_img {

    uint8_t **data;
    uint32_t _height, _width, _size, _imgSize;
    unsigned char *BMPInfoHeader, *BMPHeader;

public:
    bitmap_img(uint32_t height,uint32_t width, uint8_t **bitmap = nullptr);

    void setData(uint8_t **pixels) { bitmap_img::data = pixels;}

    void setBmpInfoHeader();

    void setBmpHeader();

    void write();

    uint32_t getImgSize() const;

};

#endif //BITMAPIMAGE_BITMAP_IMG_H
