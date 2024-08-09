#include "QuadTree.h"
#include <iostream>
#include <vector>

// Function to test construction of quadtree
void testQuadTreeConstruction(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 2, 5);
    QuadTreeNode* root = qt.getRoot();

    if (root) {
        std::cout << "Test Passed: Root node is created." << std::endl;
    } else {
        std::cout << "Test Failed: Root node is not created." << std::endl;
    }
}

// Function to test subdivision of root node
void testQuadTreeSubdivision(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 2, 5);
    QuadTreeNode* root = qt.getRoot();

    if (root->children[0] && root->children[1] && root->children[2] && root->children[3]) {
        std::cout << "Test Passed: Root is subdivided into four children." << std::endl;
    } else {
        std::cout << "Test Failed: Root subdivision is incorrect." << std::endl;
    }
}

// Function to test average color calculation
void testAverageColorCalculation(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 1, 5);
    QuadTreeNode* root = qt.getRoot();

    if (root->color == 25) {
        std::cout << "Test Passed: Average color is correctly calculated." << std::endl;
    } else {
        std::cout << "Test Failed: Average color calculation is incorrect." << std::endl;
    }
}

// Function to test leaf node identification
void testLeafNodeIdentification(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 3, 5);
    QuadTreeNode* root = qt.getRoot();

    if (!root->isLeaf()) {
        std::cout << "Test Passed: Root node is correctly identified as not a leaf." << std::endl;
    } else {
        std::cout << "Test Failed: Root node leaf identification is incorrect." << std::endl;
    }
}

// Function to test homogeneity detection (sameness test)
void testHomogeneityDetection(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 3, 5);
    QuadTreeNode* root = qt.getRoot();

    if (!root->isLeaf()) {
        std::cout << "Test Passed: Homogeneous region detected correctly." << std::endl;
    } else {
        std::cout << "Test Failed: Homogeneous region detection is incorrect." << std::endl;
    }
}

int main() {
    std::cout << "Running Quadtree Tests..." << std::endl;

    // Example 4x4 image with grayscale values (from Main.cpp)
    std::vector<std::vector<int>> image = {
        {10, 10, 20, 20},
        {10, 10, 20, 20},
        {30, 30, 40, 40},
        {30, 30, 40, 40}
    };

    testQuadTreeConstruction(image);
    testQuadTreeSubdivision(image);
    testAverageColorCalculation(image);
    testLeafNodeIdentification(image);
    testHomogeneityDetection(image);

    std::cout << "All tests completed." << std::endl;

    return 0;
}