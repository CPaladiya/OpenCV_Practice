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

    int hmin = 0, smin = 110, vmin = 153;
    int hmax = 19, smax = 240, vmax = 255;

    //since it is very hard to change 6 values of Scalar bounds, it is good idea to have track bars
    //to change this values in real time to see how it is affecting the masks

    //Here once we have converted image to HSV space, we will then use while loop to impelemt 
    //track bar functionality

    //also we dont need to create a space bar again so defined out of the while loop

    namedWindow("HSVTrackBars", (640,200)); //creating new windwow with size
    createTrackbar("Hue Min", "HSVTrackBars",  &hmin, 179); //for hue it is max 179, for sat and val it is 255
    createTrackbar("Hue Max", "HSVTrackBars",  &hmax, 179);
    createTrackbar("Sat Min", "HSVTrackBars",  &smin, 255);
    createTrackbar("Sat Max", "HSVTrackBars",  &smax, 255);
    createTrackbar("Val Min", "HSVTrackBars",  &vmin, 255);
    createTrackbar("Val Max", "HSVTrackBars",  &vmax, 255);

    while(true){

    //we will use inRange function to collect the color
    //first we will define the HSV bound

    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax,smax, vmax);

    inRange(imgHSV,lower,upper,mask); //upper and lower is the bound of color we are interested in

    imshow("Mask",mask);
    waitKey(1); // here we have to change it to 1 since it will be changing  real time
    }

}
