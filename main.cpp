#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;

//---------------------------Chapter 3 : resize, crop and other basic function ------------------//

int main(){

    string path_hand = "Hand.jpg";
    Mat img = imread(path_hand); 
    Mat ResizeImg, CropImg;
    
    cout<< img.size()<<endl; //to know the size of existing image
    
    // -------------------------- resize -------------------------//
    resize(img,ResizeImg, Size(640,480)); //this might make image croocked since we are just resizing it without
    //concerning with aspect ratio

    //if we just want to scale it down instead then we can do something like this
    //resize(img,ResizeImg, 0.5,0.5); this will reduce in terms of percentage over x and y axis
    
    imshow("Resize Image",ResizeImg);

    // ----------------------------- cropping image - ROI region of interest -------------------------//
    
    Rect roi(400,200,300,300); //rect here is a rectangle data type, x,y and width and height are four parameters
    // we will put this roi object into our image as the following line suggests
    //first two is the starting point of the crop and then next two is the diagonal end point

    CropImg = img(roi); //in this way we will be able to crop our image
    
    imshow("Crop Image",CropImg);

    waitKey(0);

}
