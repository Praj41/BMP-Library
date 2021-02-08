#include <iostream>

#include "bitmap_img.h"

int main() {

    bitmap_img image(512, 512);

    auto *pixelBitMap = (uint8_t *)(malloc(image.getImgSize()));

    uint16_t ctrs[4] = {511, 511, 511, 511};

    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            pixelBitMap[(i + j * 512) * 4 + 0] = ctrs[0] % 256;
            pixelBitMap[(i + j * 512) * 4 + 1] = ctrs[1] % 256;
            pixelBitMap[(i + j * 512) * 4 + 2] = ctrs[2] % 256;
            pixelBitMap[(i + j * 512) * 4 + 3] = ctrs[3] % 256;
            ctrs[0]--, ctrs[3]--;

        }
        ctrs[0] = 511, ctrs[3] = 511;
        ctrs[1]--, ctrs[2]--;
    }

    image.setData(&pixelBitMap);

    image.write();

    free(pixelBitMap);

    return 0;
}
