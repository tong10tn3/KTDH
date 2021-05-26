#include <graphics.h> 
#include<iostream>
#include "hamCoSo.h"
#include "ve2D1.h"
#include<fstream>
#include<math.h>
#include<conio.h>
#include "VeGiaoDien.h"
#define ROUND(a) (int)(a+0.5)
#include <sstream>
#include "ve3DHinhCau.h"
using namespace std;
#define PI 3.14159265359
int xO=700;
int yO=320;
void doisang2D(int x,int y,int z,int &X,int &Y)
{
	X=x-y*((sqrt(2)/4));
	Y=z-y*((sqrt(2)/4));	
}
void doiNguoiDungsangMayTinh(int xDoi, int yDoi, int x0, int y0, int &xKQ, int &yKQ)
{
	xKQ=xDoi*5+x0;
	yKQ=-yDoi*5+y0;
}
void veNetDut(int x1, int y1, int x2, int y2)
{
	int i,j,step;
	int dx=x2-x1;
	int dy=y2-y1;
	abs(dx)>=abs(dy) ? step=abs(dx) : step=abs(dy);
	float inc_x = (float) dx/step;
	float inc_y = (float) dy/step;
	
    int soNetPutPixel=0;
    int soNetKhongPutPixel=0;
    int soNetVe=10;
    int soNetAn=5;
	if(abs(dx)>=abs(dy) || abs(dx)<=abs(dy)){
		float x=x1;
		float y=y1;
		for(i=0;i<=abs(step);i++){
			if(soNetPutPixel<soNetVe&&soNetKhongPutPixel==0)
        {
        	putpixel5DV(ROUND(x),ROUND(y),0);
        	soNetPutPixel++;
		}
		else if(soNetPutPixel==soNetVe&&soNetKhongPutPixel<soNetAn)
		{
			soNetKhongPutPixel++;
			soNetPutPixel=0;
		}
		else if(soNetPutPixel==0&&soNetKhongPutPixel<soNetAn)
		{
			soNetKhongPutPixel++;
		}
		else if(soNetKhongPutPixel==soNetAn&&soNetPutPixel==0)
		{
			soNetPutPixel++;
			soNetKhongPutPixel=0;
			putpixel5DV(ROUND(x),ROUND(y),0);
		}
			x+=inc_x;
			y+=inc_y;
		}
	}
      
   
}
void veHinhNon(int x,int y,int z,int R,int h)
{
	R=R*5;
	h=h*5;

	int X,Y,Xdoi,Ydoi;
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
	
	brokenElipse(Xdoi,Ydoi,R,(sqrt(2)/4)*R,0);
	lineDDA(Xdoi,Ydoi-h,Xdoi-R,Ydoi,0);
	lineDDA(Xdoi,Ydoi-h,Xdoi+R,Ydoi,0);
	veNetDut(Xdoi,Ydoi-h,Xdoi,Ydoi);
	veNetDut(Xdoi,Ydoi,Xdoi-R,Ydoi);
	veNetDut(Xdoi,Ydoi,Xdoi+R,Ydoi);
	
}
void veHinhCau(int x,int y,int z,int R)
{
	R=R*5;
	int X,Y,Xdoi,Ydoi;
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
	
	
	circleBresenham(Xdoi,Ydoi,R,0);
	elipse(Xdoi,Ydoi,R,(sqrt(2)/4)*R,0);	
}



void hamVeHinhNon()
{
	
	clearmouseclick(WM_LBUTTONUP);
	setGiaoDienHoatDong(2);
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
	outtextxy(70,280,"HINH NON ");
	int x=	nhapDuLieu("NhAP TOA DO X DAY: ",3,1);

	int y=	nhapDuLieu("NHAP TOA DO Y DAY: ",3,2);

	int z=	nhapDuLieu("NHAP TOA DO Z DAY: ",3,3);
	
	int R=	nhapDuLieu("NHAP BAN KINH DAY: ",3,4);
	
	int h=	nhapDuLieu("NHAP CHIEU CAO: ",3,5);

	veHinhNon(x,y,z,R,h);
	setcolor(15);
	
	ostringstream convertX;
	ostringstream convertY;
	ostringstream convertZ;
	ostringstream convertR;
	ostringstream convertH;
	
	convertX<<x;
	convertY<<y;
	convertZ<<z;
	convertR<<R;
	convertH<<h;
	string toaDoXString=convertX.str();
	string toaDoYString= convertY.str();
	string toaDoZString= convertZ.str();
	string RString= convertR.str();
	string HString= convertH.str();
	
	setThongTin();
	
	outtextxy(70,280,"HINH NON ");
	string text= "TAM DAY O ("+toaDoXString+","+toaDoYString+","+toaDoZString+")";
	string text2= "BAN KINH DAY : "+RString;
	string text3="CHIEU CAO : "+HString;
	
	char *textC = new char[text.length()+1];
	strcpy(textC,text.c_str());
	outtextxy(15,280+30,textC);
	
	char *textC2= new char[text2.length()+1];
	strcpy(textC2,text2.c_str());
	outtextxy(15,280+60,textC2);
	
	char *textC3= new char[text3.length()+1];
	strcpy(textC3,text3.c_str());
	outtextxy(15,280+90,textC3);
	
	while(true){
		delay(1);

	if(ismouseclick(WM_LBUTTONUP))
			{
				int xtam; int ytam;
				getmouseclick(WM_LBUTTONUP,xtam,ytam);
				clearmouseclick(WM_LBUTTONUP);
				if(xtam>=25&&xtam<=108&&ytam>=119&&ytam<=189)
				{
					setThongTin();
					setDoThi();
					break;
				}
			}
		}
}
void hamVeHinhCau()
{
	
	clearmouseclick(WM_LBUTTONUP);
	setGiaoDienHoatDong(3);
	settextstyle(DEFAULT_FONT,0, 1);
	setcolor(15);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(70,280,"HINH CAU ");
	int x=	nhapDuLieu("NHAP TOA DO X TAM 0: ",3,1);

	int y=	nhapDuLieu("NHAP TOA DO Y TAM 0: ",3,2);

	int z=	nhapDuLieu("NHAP TOA DO Z TAM 0: ",3,3);
	
	int R=	nhapDuLieu("NHAP BAN KINH : ",3,4);
	
	
	veHinhCau(x,y,z,R);
	setcolor(15);
	float Rs= (sqrt(2)/4)*R;
	
	ostringstream convertX;
	ostringstream convertY;
	ostringstream convertZ;
	ostringstream convertR;
	ostringstream convertRs;
	
	convertX<<x;
	convertY<<y;
	convertZ<<z;
	convertR<<R;
	convertRs<<Rs;
	
	string toaDoXString=convertX.str();
	string toaDoYString= convertY.str();
	string toaDoZString= convertZ.str();
	string RString= convertR.str();
	string RsString= convertRs.str();
	setThongTin();
	outtextxy(70,280,"HINH CAU ");
	string text= "TAM O ("+toaDoXString+","+toaDoYString+","+toaDoZString+")";
	string text2= "AN KINH : "+RString;
	//string text3="R sau khi bien doi:  "+RsString;
	
	char *textC = new char[text.length()+1];
	strcpy(textC,text.c_str());
	outtextxy(15,280+30,textC);
	
	char *textC2= new char[text2.length()+1];
	strcpy(textC2,text2.c_str());
	outtextxy(15,280+60,textC2);
	
//	char *textC3= new char[text3.length()+1];
//	strcpy(textC3,text3.c_str());
//	outtextxy(15,280+90,textC3);
	
	while(true){
		delay(1);

	if(ismouseclick(WM_LBUTTONUP))
			{
				int xtam; int ytam;
				getmouseclick(WM_LBUTTONUP,xtam,ytam);
				clearmouseclick(WM_LBUTTONUP);
				if(xtam>=113&&xtam<=195&&ytam>=119&&ytam<=189)
				{
					setThongTin();
					setDoThi();
					break;
				}
			}
		}
}

