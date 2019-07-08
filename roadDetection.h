#pragma once

#include <string>
#include<vector>

#include <opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include "opencv2/imgproc/imgproc_c.h"
//B�����������
//˫�������
using namespace std;
using namespace cv;

#define INPUT "road\\001.png"
#define OUTPUT "result\\001.png"

class RoadDetection
{
public:
	RoadDetection(const Mat& image=Mat ())
		:readImage(image)
	{
		left_flag = false;
		right_flag = false;
		writeImage = readImage;
	}

	Mat result()
	{
		return writeImage;
	}

	//ȥ��
	void deNoise(Mat inputImage, Mat& outputImage);
	//����ROI
	void mask(Mat inputImage, Mat& outputImage);
	//��̬ѧ������
	void CloseOperation(Mat inputImage, Mat& outputImage);
	//��������
	void Brightness(Mat inputImage, Mat& outputImage);
	//��ɫ��ֵ
	void colorThreshold(Mat inputImage, Mat& outputImage);
	void HistEqualize(Mat inputImage, Mat& outputImage);
	//��Ե���
	void edgeDetector(Mat inputImage, Mat& outputImage);
	//�����߸��ʱ任
	vector<Vec4i> houghLines(Mat inputImage);
	//ɸѡ�߶�
	void lineSeparation(const vector<Vec4i>& lines, vector<std::vector<cv::Vec4i> >& output);
	void select_lines(const vector<std::vector<cv::Vec4i> >& output, vector<std::vector<cv::Vec4i> >& selectLines);
	vector<Point> regression(vector<vector<Vec4i> > left_right_lines, Mat inputImage);

//	void findSide(const Mat& inputImage);
	void findTop(vector<vector<Vec4i> > output);

	bool predictTurn(int right_x, int left_x);
	bool polynomial_curve_fit(vector<Vec4i> lines, int n);
	//��⳵����������
	void detection();

private:
	Mat readImage;
	Mat writeImage;
	bool left_flag;
	bool right_flag;
	Point right_b;	 //��ֱ�ߵ�
	double right_m;  //��ֱ��б��
	Point left_b;	 //��ֱ�ߵ�
	double left_m;   //��ֱ��б��
	int top_y;
};