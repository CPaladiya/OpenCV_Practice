#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;

float w = 250; //width of the real card
float h = 350; // height of the real card
Mat matrix, imgWarp;

//---------------------------Chapter 5 : Warp image ------------------//

int main(){

    string path = "Warp.png"; 
    Mat img = imread(path); 

    //we are going to use a function that uses a floating points, here we will have group of four points of cards
    Point2f srcPoints[4] = { {591,309},{823,349}, {518,569}, {772,626}}; // this is where currently our image is

    //so we have to define a new place where each consicutive point, will be placed at a conse. new location 
    Point2f dstPints[4] = { {0.0f,0.0f},{w,0.0f}, {0.0f,h}, {w,h}}; // this is the destination points
    // notice above we write 0.0f since its a floating point and also, w - width and h for height

    // we need a transformation matrix to find the ward. Here we will use that matrix

    matrix = getPerspectiveTransform(srcPoints, dstPints); //this way we will get a matrix, that can help compute the warping of 
    //image from one position to another

    warpPerspective(img, imgWarp, matrix,Point(w,h));//source, dest and size of the output image

    //if there is any issues, here we can add four circles on the points we selected in source files
    for(int i = 0; i<4 ; i++){
        circle(img, srcPoints[i], 10, Scalar(0,0,0), 5);
    }

    imshow("Image",img);
    //imshow("Image",imgWarp);
    waitKey(0);

}
