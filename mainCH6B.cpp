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

    
    
    VideoCapture vdo(0); 
    Mat img; 
    

    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 255, vmax = 255;

    namedWindow("HSVTrackBars", (640,200)); //creating new windwow with size
    createTrackbar("Hue Min", "HSVTrackBars",  &hmin, 179); //for hue it is max 179, for sat and val it is 255
    createTrackbar("Hue Max", "HSVTrackBars",  &hmax, 179);
    createTrackbar("Sat Min", "HSVTrackBars",  &smin, 255);
    createTrackbar("Sat Max", "HSVTrackBars",  &smax, 255);
    createTrackbar("Val Min", "HSVTrackBars",  &vmin, 255);
    createTrackbar("Val Max", "HSVTrackBars",  &vmax, 255);
    
    //since videos are series of frames we need to save all the frames and then play it one by one. 
    while(true){
    
    vdo.read(img); 
    imshow("Gossip", img); 

    Mat imgHSV,mask;
    
    //lets first - convert in HSV color space
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax,smax, vmax);

    inRange(imgHSV,lower,upper,mask); //upper and lower is the bound of color we are interested in

    imshow("Mask",mask);
    waitKey(1); // here we have to change it to 1 since it will be changing  real time
    }

}
