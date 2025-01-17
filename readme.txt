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
If they are not, we keep on recursing. Destructors are important to properly remove childnodes and eliminate memory leaks.

// Steps of Program in Simple Terms
    1. Define 4x4 greyscale image (in ImageData.h) where each pixel is defined with a color intensity value (I made one, feel free to edit values)
    2. Set depth and threshold parameters (in Main.cpp) (Also set up an example please feel free to edit)
        Depth parameter sets max levels a quadtree can have 
        Threshold parameter sets allowable difference in pixel intensity to be considered homogenous / same
    3. QuadTree constructor initializes root node covering entire image.
    4. Subdivision happens via the subdivide function. The function recursively divides regions based on how similar their color values are.
        a. If the color values are similar, it is determined to be homogenous and left a leaf node
        b. If the color values are not similar, we keep recursing until they are.
    5. Use tests to confirm the above is working correctly



// Components of Quadtree Project 
    1. QuadTree.h: Header file contains the declarations of the QuadTreeNode and QuadTree classes.

    2. ImageData.h: Header file contains values of images, originally had in Main but header allows us to pull image values easier

    3. QuadTree.cpp: Defines the functionality of the QuadTreeNode and QuadTree classes.

    4. Main.cpp: Main file demonstrates the creation and operation of a quadtree on sample greyscale image.
             
    5. Test file: Simple tests to verify the correctness of the quadtrees construction and operations.



// Setup and Compilation
    1. First download / clone from my Github repository
        git clone https://github.com/timothyfitchcupb/CSPB2270quadtrees.git

    2. Navigate to cloned project directory
        cd CSPB2270quadtrees

    3. Compile the code and test
        g++ -o quadtree Main.cpp QuadTree.cpp
        g++ -o test QuadTree.cpp test.cpp

    4. Run the program
        ./quadtree

    5. Run the tests
        ./test
