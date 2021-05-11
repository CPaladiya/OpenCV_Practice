//#include <opencv2/opencv.hpp> 

//we can include this file and we then dont have to include any other opencv header files
// however this makes it slower and takes lot of time to compile since cmake has to go and paste entire code here that wont be useful

//so since we only need few header files from opencv we can mention those only here

#include <opencv2/imgcodecs.hpp> //this is for reading files
#include <opencv2/highgui.hpp> //this is for basic gui
#include <opencv2/imgproc.hpp> //for image processing
#include <iostream>



using namespace cv;
using namespace std;

//---------------------------Chapter 1 : reading images ----------------------------------//

// this part is for reading/importing the image //

/*
int main(){

    string path = "sample.jpg"; //path to the image
    Mat img = imread(path); //Mat is the matrix of numbers, img is the name of that variable and imread will read the image

    //to show the image we can use the command imshow - imageshow
    //namedWindow("Sample Image", WINDOW_AUTOSIZE); - this window will match the size of the image itself
    imshow("sample image", img); //this will now show the image but it will close automatically. 
    //to give it some delay we need to enter the following line

    waitKey(0);//this will make sure that window only closes when we press the close button

}
*/

//---------------------------Chapter 2 : reading the video ----------------------------------//

int main(){

    //first like image we need to make a video object
    string path = "Gossip.mp4"; //path to the video
    VideoCapture vdo(path); //mew cap
    Mat img; //here we are initiating the image object that will be stored in while loop with vdo content
    
    
    //since videos are series of frames we need to save all the frames and then play it one by one. 
    while(true){
    
        vdo.read(img); 
        imshow("Gossip", img); //now one by one we will read frame and show it here on imshow,
        //note we are not using waitKey(0) since we dont want to pause just play the whole video at one go
        waitKey(50); //by changing the delay value we can change how fast or slow the video is being played
    }

}