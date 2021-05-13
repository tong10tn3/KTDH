#include <graphics.h> 
#include<iostream>
#include "hamCoSo.h"
#include "ve3D1.h"
#include<fstream>
#include<math.h>
#include<conio.h>
#include "VeGiaoDien.h"
#include<iostream>
using namespace std;


int main()//int argc, char *argv[]
{
	initwindow(1280+8,720+12);
	setGiaoDien();
	
	int XmangTong[10000];
	int YmangTong[10000];
	int nTong=0;
	veQuyDao(790,360,XmangTong,YmangTong,nTong);
	
	
	int a[1][3]={{2,3,4}};
	int b[3][3]={
		{1,2,3},
		{0,1,0},
		{0,0,1}
	};
	int KQ[3][3];
	//nhan2MaTran(a,b,KQ,1,3,3);
	
	
	int gocQuay=5;
	
	
	//cout<<"Ket qua: "<<KQ[0][0]<<"\t"<<KQ[0][1]<<"\t"<<KQ[0][2]<<endl;
	
	xuLiTam();
	//veTraiDat(790,360);
	//xuLiVongLap(XmangTong,YmangTong,nTong);
	
	//veMatTroi(790,360);
	//xuLi();
	//cout<<"tongkaka"<<endl;
	getch();
	return 0;
	
}



