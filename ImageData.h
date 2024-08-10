#ifndef IMAGE_DATA_H
#define IMAGE_DATA_H

#include <vector>

// Values represent intensity of pixel

std::vector<std::vector<int>> getImageData() {
    return {
        {10, 10, 20, 20},
        {10, 10, 20, 20},
        {30, 30, 40, 40},
        {30, 30, 40, 40}
    };
}

#endif // IMAGE_DATA_H
