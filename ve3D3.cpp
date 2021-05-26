#include <graphics.h> 
#include<iostream>
#include "hamCoSo.h"
#include "ve3D3.h"
#include "ve3D1.h"
#include<fstream>
#include<math.h>
#include<conio.h>
#include "VeGiaoDien.h"
#define ROUND(a) (int)(a+0.5)
#include <sstream>
using namespace std;


void veHinhHopChuNhat(int x,int y,int z,int d,int r,int c){
	d=d*5;
	r=r*5;
	c=c*5;
	int xO=700;
	int yO=320;	
	int X,Y,Xdoi,Ydoi;
	float sqrt2per2 = sqrt(2) / 2;
	doisang2D(x,y,z,X,Y);
	doiNguoiDungsangMayTinh(X,Y,xO,yO,Xdoi,Ydoi);
	setcolor(0);
	lineDDA(700,5,700,320,0);
	lineDDA(700,320,305,715,0);
	lineDDA(700,320,1275,320,0);
	setbkcolor(15);
	outtextxy(680,20,"Y");
	outtextxy(1250,300,"X");
	outtextxy(320,665,"Z");
	lineDDA(Xdoi, Ydoi - c, Xdoi + d, Ydoi - c,0);
	lineDDA(Xdoi + d, Ydoi - c, Xdoi + d, Ydoi,0);
	veNetDut(Xdoi + d, Ydoi, Xdoi, Ydoi);
	veNetDut(Xdoi, Ydoi, Xdoi, Ydoi-c);
	lineDDA(Xdoi - sqrt2per2*r, Ydoi - (c - sqrt2per2*r), Xdoi + d - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r),0);//EF
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r), Xdoi + d - sqrt2per2 * r, Ydoi + sqrt2per2 * r,0);//FG
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi - sqrt2per2 * r, Ydoi + sqrt2per2 * r,0);//HG
	lineDDA(Xdoi - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r),0);//EH
	
	lineDDA(Xdoi - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r), Xdoi, Ydoi - c,0);//BF
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r), Xdoi + d, Ydoi - c,0);//BB'
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi + d, Ydoi,0);//CG
	veNetDut(Xdoi - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi, Ydoi);//DH
}
void hamVeHinhHopChuNhat(){
	
	clearmouseclick(WM_LBUTTONUP);
	setGiaoDienHoatDong(4);
	setcolor(0);
	lineDDA(700,5,700,320,0);
	lineDDA(700,320,305,715,0);
	lineDDA(700,320,1275,320,0);
	setbkcolor(15);
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(680,20,"Y");
	outtextxy(1250,300,"X");
	outtextxy(320,665,"Z");
	setcolor(15);
	setbkcolor(mauxanhgiongaokhoaccrush);
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(70,280,"HINH HCN "); 
	float x=	nhapDuLieu("NHAP TOA DO X TAM : ",3,1);

	float y=	nhapDuLieu("NHAP TOA DO Y TAM: ",3,2);

	float z=	nhapDuLieu("NHAP TOA DO Z TAM: ",3,3);
	
	float d=	nhapDuLieu("NHAP CHIEU DAI: ",3,4);
	
	float r=	nhapDuLieu("NHAP CHIEU RONG: ",3,5);
	
	float c = nhapDuLieu("NHAP CHIEU CAO: ",3,6);
	veHinhHopChuNhat(x,y,z,d,r,c);
	setcolor(15);
	
	ostringstream convertDai;
	ostringstream convertRong;
	ostringstream convertCao;
	
	ostringstream convertOx;
	ostringstream convertOy;
	ostringstream convertOz;
	
	ostringstream convertAx;
	ostringstream convertAy;
	ostringstream convertAz;
	
	ostringstream convertBx;
	ostringstream convertBy;
	ostringstream convertBz;
	
	ostringstream convertCx;
	ostringstream convertCy;
	ostringstream convertCz;

	ostringstream convertDx;
	ostringstream convertDy;
	ostringstream convertDz;
	
	ostringstream convertEx;
	ostringstream convertEy;
	ostringstream convertEz;
	
	ostringstream convertFx;
	ostringstream convertFy;
	ostringstream convertFz;
	
	ostringstream convertGx;
	ostringstream convertGy;
	ostringstream convertGz;
	
	convertDai<<d;
	convertRong<<r;
	convertCao<<c;
	
	string DaiString= convertDai.str();
	string RongString= convertRong.str();
	string CaoString= convertCao.str();
	
	//diem O
	convertOx<<x;
	convertOy<<y;
	convertOz<<z;
	
	string toaDoOxString=convertOx.str();
	string toaDoOyString= convertOy.str();
	string toaDoOzString= convertOz.str();
	//diem A
	convertAx<<d+x;
	convertAy<<y;
	convertAz<<z;
	
	string toaDoAxString=convertAx.str();
	string toaDoAyString=convertAy.str();
	string toaDoAzString=convertAz.str();
	//diem B
	convertBx<<d+x;
	convertBy<<y;
	convertBz<<r+z;
	
	string toaDoBxString=convertBx.str();
	string toaDoByString=convertBy.str();
	string toaDoBzString=convertBz.str();
	//diem C
	convertCx<<x;
	convertCy<<y;
	convertCz<<r+z;
	
	string toaDoCxString=convertCx.str();
	string toaDoCyString=convertCy.str();
	string toaDoCzString=convertCz.str();
	//diem D
	convertDx<<d+x;
	convertDy<<c+y;
	convertDz<<z;
	
	string toaDoDxString=convertDx.str();
	string toaDoDyString=convertDy.str();
	string toaDoDzString=convertDz.str();
	//diem E
	convertEx<<x;
	convertEy<<y+c;
	convertEz<<z;
	
	string toaDoExString=convertEx.str();
	string toaDoEyString=convertEy.str();
	string toaDoEzString=convertEz.str();
	//diem F
	convertFx<<x;
	convertFy<<y+c;
	convertFz<<z+r;
	
	string toaDoFxString=convertFx.str();
	string toaDoFyString=convertFy.str();
	string toaDoFzString=convertFz.str();
	//diem G
	convertGx<<d+x;
	convertGy<<c+y;
	convertGz<<r+z;
	
	string toaDoGxString=convertGx.str();
	string toaDoGyString=convertGy.str();
	string toaDoGzString=convertGz.str();
	

	
	setThongTin();
	outtextxy(70,280,"HINH HCN ");
	string text= "CHIEU DAI: "+DaiString;
	string text2="CHIEU RONG: "+RongString;
	string text3="CHIEU CAO: "+CaoString;
	string textO="O ("+toaDoOxString+","+toaDoOyString+","+toaDoOzString+")";
	string textA="A ("+toaDoAxString+","+toaDoAyString+","+toaDoAzString+")";
	string textB="B ("+toaDoBxString+","+toaDoByString+","+toaDoBzString+")";
	string textC="C ("+toaDoCxString+","+toaDoCyString+","+toaDoCzString+")";
	string textD="D ("+toaDoDxString+","+toaDoDyString+","+toaDoDzString+")";
	string textE="E ("+toaDoExString+","+toaDoEyString+","+toaDoEzString+")";
	string textF="F ("+toaDoFxString+","+toaDoFyString+","+toaDoFzString+")";
	string textG="G ("+toaDoGxString+","+toaDoGyString+","+toaDoGzString+")";
		
	char *textC1 = new char[text.length()+1];
	strcpy(textC1,text.c_str());
	outtextxy(15,280+30,textC1);
	
	char *textC2= new char[text2.length()+1];
	strcpy(textC2,text2.c_str());
	outtextxy(15,280+60,textC2);
	
	char *textC3= new char[text3.length()+1];
	strcpy(textC3,text3.c_str());
	outtextxy(15,280+90,textC3);
	
	char *textCO= new char[text.length()+1];
	strcpy(textCO,textO.c_str());
	outtextxy(15,280+120,textCO);
	
	char *textCA= new char[text.length()+1];
	strcpy(textCA,textA.c_str());
	outtextxy(15,280+150,textCA);
	
	char *textCB= new char[text.length()+1];
	strcpy(textCB,textB.c_str());
	outtextxy(15,280+180,textCB);
	
	char *textCC= new char[text.length()+1];
	strcpy(textCC,textC.c_str());
	outtextxy(15,280+210,textCC);
	
	char *textCD= new char[text.length()+1];
	strcpy(textCD,textD.c_str());
	outtextxy(15,280+240,textCD);
	
	char *textCE= new char[text.length()+1];
	strcpy(textCE,textE.c_str());
	outtextxy(15,280+270,textCE);
	
	char *textCF= new char[text.length()+1];
	strcpy(textCF,textF.c_str());
	outtextxy(15,280+300,textCF);
	
	char *textCG= new char[text.length()+1];
	strcpy(textCG,textG.c_str());
	outtextxy(15,280+330,textCG);
	while(true){
		delay(1);

		if(ismouseclick(WM_LBUTTONUP))
			{
				int xtam; int ytam;
				getmouseclick(WM_LBUTTONUP,xtam,ytam);
				clearmouseclick(WM_LBUTTONUP);
				if(xtam>=200&&xtam<=280&&ytam>=119&&ytam<=189)
				{
					setThongTin();
					setDoThi();
					break;
				}
			}
	}
}
