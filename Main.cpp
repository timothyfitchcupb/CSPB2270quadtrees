#include "QuadTree.h"  // Include our QuadTree header
#include <iostream>
#include <vector>

int main() {
    // Example 4x4 image with grayscale values
    std::vector<std::vector<int>> image = {
        {10, 10, 20, 20},
        {10, 10, 20, 20},
        {30, 30, 40, 40},
        {30, 30, 40, 40}
    };

    QuadTree qt(image, 3, 5); // Create quadtree variable with a depth of 3 and a threshold of 5 (passed to constructor)
    std::cout << "Quadtree created with root covering entire image." << std::endl;
    return 0;
}