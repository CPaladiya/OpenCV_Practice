#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;

//---------------------------Chapter 4 : Drawings shape on image and adding texts ------------------//

int main(){

    //--------------creating blank image ------------------------//

    //Here 512 X 512 is the resolution of the image, CV_8UC3 means 8-bit color value unsinged of that would than very
    //from 0 to  255. Here if it is 8S - signed -127 to 128 approx. and 3C means 3 Channed B, G and R
    Mat img(512,512, CV_8UC3, Scalar(255,255,255)); //0 means no color and 255 means color with full intensity

    //------creating circle on existing image -----------------//
    circle(img, Point(256,256), 155, Scalar(255,0,0), FILLED); //first point object is center, second is radius, third is color, and
    //fourth is thickness of the line itself. instead of thickness we can write FILLED keyword to get it filled

    //------creating rectanlge --------------------------//
    rectangle(img, Point(10,10), Point(100,100), Scalar(255,0,0), 3); // here first and second point is xy of first point
    //xy of diagonal point. This is different than Rect  object we saw before //Rect roi(400,200,300,300);

    //---------------draw a line -----------------------//
    line(img,Point(124,54), Point(245,54), Scalar(0,255,255),5); //for line we just have ending and starting point

    //------- Adding Characters/texts------------------//

    imshow("Image",img);
    waitKey(0);

}
