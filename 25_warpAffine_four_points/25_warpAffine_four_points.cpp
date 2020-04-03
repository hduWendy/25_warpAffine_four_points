// 25_warpPerspective_four_points.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ��ͶӰ�任������ʾ����
	cv::Mat dstMat;
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/����/1.jpg");
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
	//�ȴ��û�����
	waitKey(0);
	return 0;
}
