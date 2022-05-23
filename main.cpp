#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
    Mat image;
    // imread("data/images/fechado.png");


    VideoCapture frame("data/images/video.mp4");
    

//     if (!frame.isOpened()){ //Error message if video source is not found//
//       cout << "Couldn't load video from the source. Make sure your camera is working properly." << endl;
//       system("pause");
//       return 0;
//    }

    // loading haarcascade file
    CascadeClassifier face_cascade, eyes_cascade, mouth_cascade;
    face_cascade.load("data/haarcascade_frontalface_default.xml");
    eyes_cascade.load("data/haarcascade_eye.xml");
    mouth_cascade.load("data/mouth.xml");

    // Error message if XML file is not found
    if(face_cascade.empty()) {cout << "face XML file not loaded" << endl; return 0;}
    if(eyes_cascade.empty()) {cout << "face XML file not loaded" << endl; return 0;}
    if(mouth_cascade.empty()) {cout << "face XML file not loaded" << endl; return 0;}

    vector<Rect> faces;
    vector<Rect>eyes;
    vector<Rect> mouth;
    while(true)
    {
        frame.read(image);

        // face_cascade.detectMultiScale(image, faces, 1.1, 10);

        eyes_cascade.detectMultiScale(image, eyes, 1.1, 100, 0);

        // mouth_cascade.detectMultiScale(image, mouth, 1.1, 200, 0);

        cout << eyes[0] << endl;
        
        for (int i = 0; i < faces.size(); i++)
        { //for locating the face
            rectangle(image, faces[i].tl(), faces[i].br(), Scalar(255,0,255), 2);
            
         }
        for (size_t j = 0; j < mouth.size(); j++)
        { //for locating eyes//
            rectangle(image, mouth[j].tl(), mouth[j].br(), Scalar(0,0,0), 2);
            //Point center(faces[i].x + eyes[j].x + eyes[j].width * 0.5, faces[i].y + eyes[j].y + eyes[j].height * 0.5);//getting the centers of both eyes//
        }
        for (size_t k = 0; k < eyes.size(); k++)
        { //for locating eyes//
            rectangle(image, eyes[k].tl(), eyes[k].br(), Scalar(0,0,255), 2);
            //Point center(faces[i].x + eyes[j].x + eyes[j].width * 0.5, faces[i].y + eyes[j].y + eyes[j].height * 0.5);//getting the centers of both eyes//
        }
        
        imshow("image", image);
        waitKey(1);
    }

    return 0;
}