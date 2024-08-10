#include "QuadTree.h"  // Include our QuadTree header
#include "ImageData.h" // Include the image data header
#include <iostream>

int main() {
    // Get the 4x4 image with grayscale values
    std::vector<std::vector<int>> image = getImageData();

    QuadTree qt(image, 3, 5); // Create example quadtree with a depth of 3 and a threshold of 5
    std::cout << "Quadtree created with root covering entire image." << std::endl;
    return 0;
}