#include "QuadTree.h"
#include <cmath>

// QuadTreeNode constructor
QuadTreeNode::QuadTreeNode(int x, int y, int size, int color)
    : x(x), y(y), size(size), color(color) {
    for (int i = 0; i < 4; ++i) children[i] = nullptr;
}

// QuadTreeNode destructor
QuadTreeNode::~QuadTreeNode() {
    for (int i = 0; i < 4; ++i) delete children[i];
}

// Check if node is leaf
bool QuadTreeNode::isLeaf() const {
    return children[0] == nullptr;
}

// QuadTree constructor
QuadTree::QuadTree(const std::vector<std::vector<int>>& image, int depth, int threshold)
    : maxDepth(depth), threshold(threshold) {
    int size = image.size();
    root = new QuadTreeNode(0, 0, size, getAverageColor(0, 0, size, image));
    subdivide(root, 0, image);
}

// QuadTree destructor
QuadTree::~QuadTree() {
    delete root;
}

// Get root node
QuadTreeNode* QuadTree::getRoot() {
    return root;
}

// Subdivide node into quadrants 
void QuadTree::subdivide(QuadTreeNode* node, int level, const std::vector<std::vector<int>>& image) {
    if (level >= maxDepth || isHomogeneous(node, image)) return;

    int newSize = node->size / 2;
    node->children[0] = new QuadTreeNode(node->x, node->y, newSize, getAverageColor(node->x, node->y, newSize, image)); // Top left (NW)
    node->children[1] = new QuadTreeNode(node->x + newSize, node->y, newSize, getAverageColor(node->x + newSize, node->y, newSize, image)); // Top right (NE)
    node->children[2] = new QuadTreeNode(node->x, node->y + newSize, newSize, getAverageColor(node->x, node->y + newSize, newSize, image)); // Bottom left (SW)
    node->children[3] = new QuadTreeNode(node->x + newSize, node->y + newSize, newSize, getAverageColor(node->x + newSize, node->y + newSize, newSize, image)); // Bottom right (SE)

    for (int i = 0; i < 4; ++i) {
        subdivide(node->children[i], level + 1, image);
    }
}

// Calculate average color for region
int QuadTree::getAverageColor(int x, int y, int size, const std::vector<std::vector<int>>& image) const {
    int sum = 0;
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            sum += image[i][j];
        }
    }
    return sum / (size * size);
}

// Check if region is homogeneous (sameness test)
bool QuadTree::isHomogeneous(QuadTreeNode* node, const std::vector<std::vector<int>>& image) const {
    int avgColor = getAverageColor(node->x, node->y, node->size, image);
    for (int i = node->y; i < node->y + node->size; ++i) {
        for (int j = node->x; j < node->x + node->size; ++j) {
            if (std::abs(image[i][j] - avgColor) > threshold) {
                return false;
            }
        }
    }
    return true;
}