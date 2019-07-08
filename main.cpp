#include <io.h>
#include <iostream>
#include<string>
#include <vector> 
#include <opencv.hpp>
#include "roadDetection.h"

using namespace std;
using namespace cv;


////��ȡ�ض���ʽ���ļ���    
//void getAllFiles(string path, vector<string>& files, string format)
//{
//	long  hFile = 0;//�ļ����  64λ��long ��Ϊ intptr_t
//	struct _finddata_t fileinfo;//�ļ���Ϣ 
//	string p;
//	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1) //�ļ�����
//	{
//		do
//		{
//			if ((fileinfo.attrib & _A_SUBDIR))//�ж��Ƿ�Ϊ�ļ���
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)//�ļ������в���"."��".."
//				{
//					files.push_back(p.assign(path).append("\\").append(fileinfo.name)); //�����ļ�����
//					getAllFiles(p.assign(path).append("\\").append(fileinfo.name), files, format); //�ݹ�����ļ���
//				}
//			}
//			else
//			{
//				files.push_back(p.assign(path).append("\\").append(fileinfo.name));//��������ļ��У������ļ���
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//		_findclose(hFile);
//	}
//}


//int main()
//{
//	//vector<string> files;
//	//string filePath = "D:\\�û��ļ���\\Documents\\Visual Studio 2017\\Projects\\��·���\\��·���\\road\\";
//	//string format = ".jpg";
//	//getAllFiles(filePath, files, format);
//	//for (int i = 0; i < files.size(); i++)
//	//{
//		Mat readimage;
//		string readStr = INPUT;
//		string writeStr = OUTPUT;
//
//		readimage = imread(readStr);
//		if (!readimage.data) { printf("��ȡImage����~�� \n"); return -1; }
//		imshow("ԭͼ", readimage);
//
//		RoadDetection RoDetec(readimage);
//		RoDetec.detection();
//
//		Mat writeimage = RoDetec.result();
//		imshow("���ͼ", writeimage);
//		imwrite(writeStr, writeimage);
//
//		waitKey(0);
////	}
//	
//	return 0;
//}
  
void loop(string readStr, string writeStr)
{
	readStr = "road\\" + readStr;
	writeStr = "result\\" + writeStr;
	Mat readimage;
	readimage = imread(readStr);
	if (!readimage.data) { printf("��ȡImage����~�� \n"); return;}
	imshow(readStr, readimage);

	RoadDetection RoDetec(readimage);
	RoDetec.detection();

	Mat writeimage = RoDetec.result();
	imwrite(writeStr, writeimage);

	imshow(writeStr, writeimage);
}


int main()
{
	string str1 = "test1.jpg";
	string str2 = "test2.jpg";
	string str3 = "test3.jpg";
	string str4 = "straight_lines1.jpg";
	string str5 = "straight_lines2.jpg";


	loop(str1, str1);
	waitKey(0);
	loop(str2, str2);
	waitKey(0);
	loop(str3, str3);
	waitKey(0);
	loop(str4, str4);
	waitKey(0);
	loop(str5, str5);
	waitKey(0);
	return 0;
}