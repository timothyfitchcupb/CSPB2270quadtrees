#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>

struct QuadTreeNode {
    int x, y;  // Position of quadrant
    int size;  // Size of quadrant
    int color; // Average color of region
    QuadTreeNode* children[4];  // Pointers to child quadrants

    QuadTreeNode(int x, int y, int size, int color);
    ~QuadTreeNode();

    bool isLeaf() const;
};

class QuadTree {
private:
    QuadTreeNode* root;
    int maxDepth;  // Maximum depth of tree
    int threshold; // Color difference threshold for subdivision

    void subdivide(QuadTreeNode* node, int level, const std::vector<std::vector<int>>& image);
    int getAverageColor(int x, int y, int size, const std::vector<std::vector<int>>& image) const;
    bool isHomogeneous(QuadTreeNode* node, const std::vector<std::vector<int>>& image) const;

public:
    QuadTree(const std::vector<std::vector<int>>& image, int depth, int threshold);
    ~QuadTree();

    QuadTreeNode* getRoot();
};

#endif // QUADTREE_H