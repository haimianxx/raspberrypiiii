#include<iostream>
#include<stdio.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "face.h"
using namespace cv;
using namespace std;
using namespace aip;

string app_id="42783714";
string api_key="N0nLGFprRXBcPR3VaEvCjaNI";
string secret_key = "WFVs1U98e0h5EbhfxPsGrVWfARqXdDiY";



Face client(app_id,api_key,secret_key);

void blank(void)
{
	options["liveness_control"] = "LOW";
	result=client.face_search_v3 (Base64Face,"BASE64","xmy",options);
	cout << result << endl;
}

int main()
{
	wiringPiSetup();
	pullUpDnControl(button,PUD_UP);
	delay(100);
	wiringPiISR(button,INT_EDGE_FALLING,&blank);
	VideoCapture cap;
	cap.open(0,CAP_ANY);
	cap.set(CAP_PROP_FRAME_WIDTH,1080);
	cap.set(CAP_PROP_FRAME_HEIGHT,480);
	//cap.set(CAP_PROP_FPS,30);
	if(!cap.isOpened())
	{
		cout << "not face" << endl;
		return -1;
	}
	CascadeClassifier Classifier("/usr/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml");

	Mat ColorImage;
	Mat GrayImage;
	Mat BaiduFace;
	vector<Rect> ALLFace;
	vector<uchar> JpgFace;
	//string JsonResult;
	Json::Value options;
	std::string Base64Face;
	Json::Value result;
	options["liveness_control"] = "LOW";
	while(1)
	{
		cap.read(ColorImage);
		cvtColor(ColorImage,GrayImage,COLOR_BGR2GRAY);
		equalizeHist(GrayImage,GrayImage);
		Classifier.detectMultiScale(GrayImage,ALLFace);
		if(ALLFace.size())
		{
			rectangle(GrayImage,ALLFace[0],Scalar(255,0,0));
			BaiduFace=GrayImage(ALLFace[0]); 
			imencode(".jpg",GrayImage,JpgFace);
			Base64Face=base64_encode((char*)JpgFace.data(),JpgFace.size());
			result=client.face_search_v3 (Base64Face,"BASE64","xmy",options);
			cout << result << endl;
		}
	    imshow("video",GrayImage);
		waitKey(2);
	}
	return 0;
}
