#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>

using namespace cv;
using namespace std;


//---------------------------Chapter 7 : Shape detection ------------------//

//there are two arguments, first image is the feed image that has been dilated and processed
//second argument is image that we want to write on,- where we will write shape name
void getContours(Mat &imgDil, Mat &img){

    //here is how to define vectors of countours, they are list of points within list so a vector inside a vector of a Points
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy; //besically 4 integer values. However we have not used this here much in this example


    findContours(imgDil, contours, hierarchy,RETR_LIST,CHAIN_APPROX_SIMPLE);

    //this is an OCV function to draw contours - we will be writing on our main img
    //drawContours(img,contours,-1,Scalar(255,0,255),7); //-1 says draw all contours, otherwise we can give number of which one we want to be drawn

    //next we want to find area of the contour, sometimes we want to make sure the area is only 
    //detected if it has some number of area, smaller area migh be the noise
    //so to remove the noise of small areas we will run for loop througfh all the contours

    for (int i = 0; i< contours.size(); i++){
        
        double area = contourArea(contours[i]);
        cout << "Area of the i "<< i << " contour : "<< area << endl;
        //next we can create a filter where we only identify area if it is more than 1000

        //this will be exacly like contours, but it will only have corner points
        vector<vector<Point>> conPoly(contours.size());
        //creating a bounding box point values using conPoly
        vector<Rect> boundRect(contours.size()); //note the data type here

        //object type
        string objType;

        if (area > 1000){
            
            float peri = arcLength(contours[i], true); //this will be the bounding box around the object

            //now we will find a howmany corners do they have, if its 3 - triange, 4 - rect , alot - circle
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);
            
            //this will draw the contour
            //drawContours(img,contours,i,Scalar(255,0,255),7);//now, it will only draw the ith contour, instead of all
            //instead of writing contours we can now draw conPoly!
            drawContours(img,conPoly,i,Scalar(255,0,255),1);

            //to get the idea of number of contours and size
            cout << "Number of contor on i " << i << " :" << conPoly[i].size() << endl;

            //these two line will help us draw the square contour around the object we identified
            boundRect[i] = boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0,0,0),2);

            //now we will identify which object is which
            int objCor = (int)conPoly[i].size(); //converting number of total corners

            if (objCor == 3) {objType = "Tri";}
            else if (objCor == 4) {objType = "Rect";}
            else {objType = "Multi-angle";}

            //adding the text on the bounding box
            putText(img, objType, {boundRect[i].x, boundRect[i].y-5}, FONT_HERSHEY_DUPLEX, 0.50, Scalar(0,0,0), 1);

        }
    }

}

int main(){

    string path = "Shapes2.png";
    Mat img = imread(path);
    Mat imgGray, imgBlurr, imgEdge, imgDil;

    //------------------- preprocessing of the image -----------------------//

    //to detect shape first we will conver the image to gray scale, then  blurr the image, then we will do the edge detection
    //then we will count the countour on that edges to find shape
    
    cvtColor(img,imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlurr, Size(3,3),3,0);
    Canny(imgBlurr,imgEdge,25,75);

    //dialation of the edge detected image, this will fill the void within shape corners and joints for ease of shape detection
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(imgEdge, imgDil, kernel);

    getContours(imgDil,img);

    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blurr", imgBlurr);
    imshow("Image Dialated", imgDil);
    imshow("Image Edge detected", imgEdge);

    waitKey(0); // here we have to change it to 1 since it will be changing  real time
    

}
