#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;

float w = 250; //width of the real card
float h = 350; // height of the real card
Mat matrix, imgWarp;

//---------------------------Chapter 6 : Color detection ------------------//

int main(){

    string path = "Hand.jpg";
    Mat img = imread(path);

    imshow("Image",img);
    waitKey(0);

}
