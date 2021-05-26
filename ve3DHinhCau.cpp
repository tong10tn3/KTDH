#include<iostream>
#include <graphics.h>
#include<fstream>
#include<math.h>
#include<conio.h>
#include "VeGiaoDien.h"
#include "hamCoSo.h"

using namespace std;

float xo=650;
float yo=450;
float cos30= 0.866;
float sin30= 0.5;
float oz=385; //(317,642)
int mautocHatakeKakashi= 15;

	float x=1;
	float y=1;
	float z=1;
	float rDemo=30;


void veHeToaDo3D() {
	setcolor(0);
	lineDDA1DV(xo,yo,xo,10,0); //Y(650;10)
	lineDDA1DV(xo,yo,xo+600,yo,0); //X(1250,450)
	lineDDA1DV(xo,yo,xo-(oz*cos30),yo+(oz*sin30),0); //Z(317,642)
	
	lineDDA1DV(650,10,645,15,0); lineDDA1DV(650,10,655,15,0);
	lineDDA1DV(1250,450,1245,445,0); lineDDA1DV(1250,450,1245,455,0);
	lineDDA1DV(317,642,320,632,0); 	lineDDA1DV(317,642,327,642,0);
	
	settextstyle(DEFAULT_FONT, 0, 1);
	setbkcolor(mautocHatakeKakashi);
	outtextxy(1245,457,"x");
	outtextxy(657,15,"y");
	outtextxy(318,644,"z");
	
}

void brokenElipse(int xcenter,int ycenter,int xradius,int yradius, int color) {
    int x,y; 
	float c,p;
    x=0; 
	y=yradius;
	
    c=(float)yradius/xradius;
    c=c*c; p=2*c-2*yradius+1;
    
    while (c*x<=y) {
    	if(x%8==0)
		{
		
        putpixel5DV(xcenter+x,ycenter-y,color);
        putpixel5DV(xcenter-x,ycenter-y,color);
    	}
    	putpixel5DV(xcenter+x,ycenter+y,color);
        putpixel5DV(xcenter-x,ycenter+y,color);
    	
    	if (p<0) p += 2*c*(2*x+3);
        else {
            p +=4*(1-y)+2*c*(2*x+3);
            y-=2;
            }
        x+=2;
    }
    
    
	y=0;
	x=xradius;
    c= (float)xradius/yradius;
    c=c*c;
	p=2*c-2*xradius+1;
    while (c*y<=x) {
    	if(y%8==0)
		{
		putpixel5DV(xcenter+x,ycenter-y,color);
        putpixel5DV(xcenter-x,ycenter-y,color);
		}
    	
        putpixel5DV(xcenter+x,ycenter+y,color);
        putpixel5DV(xcenter-x,ycenter+y,color);
    		
        if (p<0) p +=2*c*(2*y+3);
        else {
        	p +=4*(1-x)+2*c*(2*y+3);
        	x-=2;
        }
        y+=2;
    }
}

void veKhoiCau(int x, int y, int z, int r) {
	
	//1DV=5PPixels
	x=5*x;
	y=5*y;
	z=5*z;
	r=5*r;
	
	//convert 3D to 2D
	float xf, yf, zf;
	xf= x;
	yf= y;
	zf= z/2;
	
	xf-=zf*cos30;
	yf-=zf*sin30;
	
	//draw orb
	circleBresenham(xo+xf,yo-yf,r,0);
	
	//elipse(xo+xf,yo-yf,r,r/4,12);
	brokenElipse(xo+xf,yo-yf,r,sin30*r/2,0);
	lineDDA1DV(xo,yo,xo+xf,yo-yf,0); //line from origin to orb's center
	
}

void runHinhCau()
{
	clearmouseclick(WM_LBUTTONUP);
	
	setGiaoDienHoatDong(3);
	veHeToaDo3D();
	
	settextstyle(DEFAULT_FONT,0, 1);
	setcolor(15);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(70,280,"HINH CAU ");
	int x=	nhapDuLieu("NHAP TOA DO X TAM O: ",3,1);

	int y=	nhapDuLieu("NHAP TOA DO Y TAM O: ",3,2);

	int z=	nhapDuLieu("NHAP TOA DO Z TAM O: ",3,3);
	
	int R=	nhapDuLieu("NHAP BAN KINH : ",3,4);
	
	
	veHeToaDo3D();
	veKhoiCau(x,y,z,R);
	setcolor(15);
	float Rs= R/4;
	
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
	string text= "TAM 0 ("+toaDoXString+","+toaDoYString+","+toaDoZString+")";
	string text2= "BAN KINH : "+RString;
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
	clearmouseclick(WM_LBUTTONUP);
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


