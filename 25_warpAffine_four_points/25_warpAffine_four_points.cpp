// 25_warpPerspective_four_points.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//读取本地的一张图片，投影变换，并显示出来
	cv::Mat dstMat;
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/推文/1.jpg");
	if (srcMat.empty())return-1;

	//
	const cv::Point2f pts1[] = {
		cv::Point2f(200,200),
		cv::Point2f(250,200),
		cv::Point2f(200,100),
		cv::Point2f(350,150)
	};
	//
	const cv::Point2f pts2[] = {
		cv::Point2f(300,100),
		cv::Point2f(300,50),
		cv::Point2f(200,100),
		cv::Point2f(340,180)
	};
	//
	const cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	//
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());

	imshow("src", srcMat);
	imshow("dst", dstMat);
	//等待用户按键
	waitKey(0);
	return 0;
}
