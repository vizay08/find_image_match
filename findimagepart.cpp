///takes 2 images as input and find the similar image to the first image in the second image......

#include<opencv2\opencv.hpp>
#include<iostream>

int somefunction()  //to perform the operation to find the image parts
{

	cv::Mat srcImage,targetImage,matchedImage;
	char* s =(char*)malloc(sizeof(char)*30);

	cout<<"Enter the source image"<<endl;
	gets(s);
	srcImage = cv::imread(s);
	

	if(!srcImage.empty())
	{
		cout<<"src x "<<srcImage.rows<<":: y "<<srcImage.cols<<endl;
	}

	cout<<"Enter the target Image"<<endl;
	gets(s);
	targetImage = cv::imread(s);

	if(!targetImage.empty())
	{
		cout<<"target x "<<targetImage.rows<<":: y "<<targetImage.cols<<endl;
	}

	int resultCols =  targetImage.cols - srcImage.cols + 1;
	int resultRows =  targetImage.rows - srcImage.rows + 1;

	matchedImage.create(resultCols, resultRows, CV_32FC1);


	cv::matchTemplate(targetImage,srcImage,matchedImage,CV_TM_SQDIFF_NORMED);
	cv::normalize(matchedImage,matchedImage,0,1,cv::NORM_MINMAX,-1,cv::Mat());

	double minVal,maxVal;
	cv::Point minPoint , maxPoint, matchPoint;
	if(!targetImage.empty())
		cout<<"done upto here"<<endl;

	

	
	cv::minMaxLoc(targetImage,&minVal,&maxVal,&minPoint,&maxPoint,cv::Mat());

	matchPoint = minPoint ;

	
	cv::rectangle(targetImage,matchPoint,cv::Point(matchPoint.x + srcImage.cols, matchPoint.y + srcImage.rows),cv::Scalar(255,0,0));

	cv::imshow("matched portions",targetImage);

	cv::waitKey();
	return 0;
}