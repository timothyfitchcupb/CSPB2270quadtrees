#include "QuadTree.h"
#include "ImageData.h" 
#include <iostream>

// Function to test construction of quadtree
void testQuadTreeConstruction(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 2, 5);
    QuadTreeNode* root = qt.getRoot();

    if (root) {
        std::cout << "Test Passed: Root node created." << std::endl;
    } else {
        std::cout << "Test Failed: Root node not created." << std::endl;
    }
}

// Function to test subdivision of root node
void testQuadTreeSubdivision(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 2, 5);
    QuadTreeNode* root = qt.getRoot();

    if (!root) {
        std::cerr << "Error: Root node is nullptr." << std::endl;
        return;
    }

    if (root->children[0] && root->children[1] && root->children[2] && root->children[3]) {
        std::cout << "Test Passed: Root subdivided into four children." << std::endl;
    } else {
        std::cout << "Test Failed: Root subdivision is incorrect." << std::endl;
    }
}

// Function to test average color calculation
void testAverageColorCalculation(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 1, 5);
    QuadTreeNode* root = qt.getRoot();

    if (!root) {
        std::cerr << "Error: Root node is nullptr." << std::endl;
        return;
    }

    if (root->color == 25) {
        std::cout << "Test Passed: Average color correctly calculated." << std::endl;
    } else {
        std::cout << "Test Failed: Average color calculation incorrect." << std::endl;
    }
}

// Function to test leaf node identification
void testLeafNodeIdentification(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 3, 5);
    QuadTreeNode* root = qt.getRoot();

    if (!root) {
        std::cerr << "Error: Root node is nullptr." << std::endl;
        return;
    }

    if (!root->isLeaf()) {
        std::cout << "Test Passed: Root node correctly identified as not a leaf." << std::endl;
    } else {
        std::cout << "Test Failed: Root node leaf identification incorrect." << std::endl;
    }
}

// Function to test homogeneity detection (sameness test)
void testHomogeneityDetection(const std::vector<std::vector<int>>& image) {
    QuadTree qt(image, 3, 5);
    QuadTreeNode* root = qt.getRoot();

    if (!root) {
        std::cerr << "Error: Root node is nullptr." << std::endl;
        return;
    }

    if (!root->isLeaf()) {
        std::cout << "Test Passed: Homogeneous region detected correctly." << std::endl;
    } else {
        std::cout << "Test Failed: Homogeneous region detection incorrect." << std::endl;
    }
}

int main() {
    std::cout << "Running Quadtree Tests..." << std::endl;

    // Get the 4x4 image with grayscale values
    std::vector<std::vector<int>> image = getImageData();

    testQuadTreeConstruction(image);
    testQuadTreeSubdivision(image);
    testAverageColorCalculation(image);
    testLeafNodeIdentification(image);
    testHomogeneityDetection(image);

    std::cout << "All tests completed." << std::endl;

    return 0;
}