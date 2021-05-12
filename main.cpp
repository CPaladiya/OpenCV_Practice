#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;

float w = 250; //width of the real card
float h = 350; // height of the real card

//---------------------------Chapter 6 : Color detection ------------------//

int main(){

    string path = "Hand.jpg";
    Mat img = imread(path);
    Mat imgHSV,mask;
    
    //lets first - convert in HSV color space
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    //since it is very hard to change 6 values of Scalar bounds, it is good idea to have track bars
    //to change this values in real time to see how it is affecting the masks

    //Here once we have converted image to HSV space, we will then use while loop to impelemt 
    //track bar functionality

    while(true){

    //we will use inRange function to collect the color
    //first we will define the HSV bound
    int hmin = 0, smin = 110, vmin = 153;
    int hmax = 19, smax = 240, vmax = 255;

    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax,smax, vmax);

    inRange(imgHSV,lower,upper,mask); //upper and lower is the bound of color we are interested in



    imshow("Mask",mask);
    waitKey(0);
    }

}
