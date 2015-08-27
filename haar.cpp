#include "opencv2/opencv.hpp"
#include "stdio.h"
using namespace std;
using namespace cv;
int main()
{
Mat frame,gframe;//objects frame and gframe
vector<Rect> faces;//vector 
CascadeClassifier face_detect;//create new cascade clasidier objetc 
string haar_file= "/root/opencv/haar/haarcascade_frontalface_alt_tree.xml";//file name including location of haar file
VideoCapture cap(0);//creape video capture medium
namedWindow("display");//create a window named display
face_detect.load(haar_file);//load haar file needed
/*
code bellow verifies whether te haar file has been loaed 
*/
if(face_detect.load(haar_file))
{
printf("haar file loaded");
}
else if (!face_detect.load(haar_file))
{
printf("failed to load haar file");
}
else
{
printf("system error!!!!!!");
}
for(;;)
{
cap.read(frame);//read from cam and store in frames
cvtColor(frame,gframe,CV_BGR2GRAY);
equalizeHist(gframe,gframe);
face_detect.detectMultiScale(gframe,faces,1.3,3);
if (faces.size()>0)
rectangle(frame,faces[0],Scalar(0,0,255),2,8,0);
imshow("display",frame);//display frames in display window
if (waitKey(30)>=27)
{
break;
}
}
return 0;
}
