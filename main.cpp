#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;

//---------------------------Chapter 2 : Basic functions to operate on image ------------------//

int main(){

    string path = "sample.jpg"; 
    string path_hand = "Hand.jpg";
    Mat img = imread(path); 
    Mat img_hand = imread(path_hand); 
    Mat imgGray; // here we are defining the output image since we are not modifying the source image
    Mat imgBlurr, imgBlurr_hand; //to create a blurred image later on
    Mat imgEdge, imgEdge_hand; //to detect edge later on
    Mat imgDil, imgEro; //image dialation and image erosion

    //-------------1.to covert image in grayscale, we can use command down below

    cvtColor(img, imgGray, COLOR_BGR2GRAY);

    //this commands will only show one window at a time
    imshow("sample image", img);
    imshow("sample image", imgGray); 

    //to show both image in a single window,follow this link,
    //https://www.programmersought.com/article/51853081107/

    //---------------2.now lets blurr the image

    GaussianBlur(img_hand, imgBlurr_hand, Size(3,3),0,0);
    GaussianBlur(img, imgBlurr, Size(3,3),0,0);
    imshow("sample image", imgBlurr_hand); 

    //---------------3. Edge detection with kenney edge detector
    
    //normally its a common practice to blur image before using edge detection to only find hard edges
    Canny(imgBlurr, imgEdge, 50, 50);
    Canny(imgBlurr_hand, imgEdge_hand, 75, 75);
    imshow("sample image", imgEdge_hand); 

    //--------------4.Dialate and erode, meaning decreasing or increasing thickness of edges, if they are too thin or too thick

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3)); //we are making a karnel - or a small matrix that will be used
    //in dialation of the image, with bigger size we will have much more dialation. Always use odd numbers to make kernel
    dilate(imgEdge_hand, imgDil, kernel); //increase the edge thickness
    imshow("sample image", imgDil); 

    erode(imgDil, imgEro, kernel); //decrease the edge thickness
    imshow("sample image", imgEro);

    waitKey(0);

}
