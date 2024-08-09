// Timothy Fitch
// CSPB 2270 Final Project
// Quadtree Image Processing Project


While my original project proposal was less a proposal and more grandiose ramblings about quadtrees and image processing and an app I'd (still) like to build one day,
I believe I was able to pare it down into a project that more accurately fits the constructs of our class and demonstrates what I have learned about quadtrees. 

Quadtrees are a data structure that uses recursion to divide two dimensional space into four quadrants. 
The quadtree structure allows us to store image data in an efficient way by subdividing the image into regions that can be processed at different levels of detail. 
This approach saves memory and computation time by simplifying areas with the same color.

My project implements a quadtree data structure for a few different simple image processing tasks that focus on this implementation of image compression and segmentation. 
I have learned a lot about quadtrees and have tried to implement a project that effectively shows this through a simple c++ greyscale image processing program. .

// Components of Quadtree Project 

- QuadTree.h: The header file contains the declarations of the QuadTreeNode and QuadTree classes.

- QuadTree.cpp: This file defines the functionality of the QuadTreeNode and QuadTree classes.

- Main.cpp: Main file demonstrating the creation and basic operation of a quadtree on sample greyscale image.

- Test file: Created simple tests to verify the correctness of the quadtrees construction and operations.



/// Setup and Compilation

1. First download from my Github repository

2. Compile the code 
    g++ -o test QuadTree.cpp test.cpp

3. Run the tests
    ./test