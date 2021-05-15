#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;


//---------------------------Project 1 : Realtime Marker Detection ------------------//
void findColors(Mat img){

    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    
    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax,smax, vmax);

    inRange(imgHSV,lower,upper,mask);

    

}

int main(){

    VideoCapture vdo(0); 
    Mat img; 
    
    while(true){
    
        vdo.read(img); 

        //funciton to find the colors
        findColors(img);

        imshow("Gossip", img); 
        waitKey(1); 
    }

}
