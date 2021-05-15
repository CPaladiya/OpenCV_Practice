#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;


//---------------------------Project 1 : Realtime Marker Detection ------------------//

// we will have multiple masks for multiple colors we want to detect, for multiple colors we will use vector

//vector of Hmin,Hmax,Smin,Smax,Vmin,Vmanx values for two different colors
vector<vector<int>> myColors {{72,89,114,212,101,255},{90,109,208,255,172,255}}; //bright green and blue here

vector<Scalar> defColors{{255,0,0},{0,255,0}}; //BGR color definition for blue and green - colors to be displayed on the marker tip

void getContours(Mat &imgDil, Mat &img){

    //here is how to define vectors of countours, they are list of points within list so a vector inside a vector of a Points
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy; //besically 4 integer values. However we have not used this here much in this example

    findContours(imgDil, contours, hierarchy,RETR_LIST,CHAIN_APPROX_SIMPLE);

    //this will be exacly like contours, but it will only have corner points
    vector<vector<Point>> conPoly(contours.size());
    //creating a bounding box point values using conPoly
    vector<Rect> boundRect(contours.size()); //note the data type here

    for (int i = 0; i< contours.size(); i++){
        
        double area = contourArea(contours[i]);
        cout << "Area of the i "<< i << " contour : "<< area << endl;
        //next we can create a filter where we only identify area if it is more than 1000

        //object type
        string objType;

        if (area > 1000){
            
            float peri = arcLength(contours[i], true); //this will be the bounding box around the object

            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);

            //to get the idea of number of contours and size
            cout << "Number of contor on i " << i << " :" << conPoly[i].size() << endl;

            //these two line will help us draw the square contour around the object we identified
            boundRect[i] = boundingRect(conPoly[i]);
            drawContours(img,conPoly,i,Scalar(255,0,255),1);
            //creating bounding box around the detected contour
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0,0,0),3);


        }
    }

}

void findColors(Mat &img){

    Mat imgHSV, mask;

    cvtColor(img, imgHSV, COLOR_BGR2HSV);


    for(int i = 0; i<myColors.size(); i++){

    Scalar lower(myColors[i][0], myColors[i][2], myColors[i][4]); //format Hmin, Smin, Vmin
    Scalar upper(myColors[i][1],myColors[i][3], myColors[i][5]); //format Hmax, Smax, Vmax
    //now here we are creating mask
    inRange(imgHSV,lower,upper,mask); 
    //imshow(to_string(i), mask);
    getContours(mask,img);

    }
}

int main(){

    VideoCapture vdo(0); 
    Mat img; 
    
    while(true){
    
        vdo.read(img); 

        //funciton to find the colors
        findColors(img);

        imshow("Main Frame", img); 
        waitKey(1); 
    }

}
