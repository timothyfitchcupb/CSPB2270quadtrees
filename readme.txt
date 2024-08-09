// Timothy Fitch
// CSPB 2270 Final Project
// Quadtree Image Processing Project


While my original project proposal was less a proposal and more grandiose ramblings about quadtrees and image processing and an app I'd (still) like to build one day,
I believe I was able to pare it down into a project that more accurately fits the constructs of our class and demonstrates what I have learned about quadtrees. 

Quadtrees are a data structure that uses recursion to divide two dimensional space into four quadrants. The headnode of a quadtree represents the entire two dimensional "image" or space.
Each childnode in a quadtree has four children, each child representing an area of two dimensional space (top left, bottom left, etc). 
This quadtree structure allows us to store image data in an efficient way by subdividing the image into regions that can be processed at different levels of detail.
Areas that conform with each other and have low levels of detail are processed faster than areas with higher levels of detail. 
This approach saves memory and computation time by simplifying the areas that have the same color.

I have learned a lot about quadtrees and have tried to implement a project that effectively shows this through a simple c++ greyscale image processing program.
The program looks at our greyscale values, and if colors are similar, we stop, and the node is left as a leaf node.
If they are not, we keep on recursing. 

// Steps of Program in Simple Terms
    1. Define 4x4 greyscale image (in Main.cpp) where each pixel is defined with a color value
    2. QuadTree constructor initializes root node covering entire image.
    3. Subdivision happens via the subdivide function. The function recursively divides regions based on how similar their color values are.
        a. If the color values are similar, it is determined to be homogenous and left a lead node
        b. If the color values are not similar, we keep recursing until they are.
    4. Use tests to confirm the above is working correctly

// Components of Quadtree Project 

    QuadTree.h: The header file contains the declarations of the QuadTreeNode and QuadTree classes.

    QuadTree.cpp: This file defines the functionality of the QuadTreeNode and QuadTree classes.

    Main.cpp: Main file demonstrating the creation and basic operation of a quadtree on sample greyscale image.

    Test file: Created simple tests to verify the correctness of the quadtrees construction and operations.



/// Setup and Compilation

1. First download from my Github repository
    https://github.com/timothyfitchcupb/CSPB2270quadtrees.git

2. Compile the code 
    g++ -o test QuadTree.cpp test.cpp

3. Run the tests
    ./test