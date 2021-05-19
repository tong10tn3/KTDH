#include<iostream>
#include<string.h>
#include<graphics.h>
#define mauvongtron 2
#define Rvongtron 25
using namespace std;
#define MauNenDoThi 7
#define MAX 100
#define mauxanhgiongaokhoaccrush 9

#define mauxanhlachuoi 10
#define mauxanhlacay 2

#define mauNutThoat 4
#define mauKhiChamNutThoat 12
#define soLuongDinhMax 15
#define nhanDinh 12
#define MaxMatrix 20
#define DENTA 15
#define VOCUNG 999
#include "VeGiaoDien.h"
#include "ve2D1.h"
using namespace std;

// =============== THIET LAP GIAO DIEN ================
void setGiaoDien()
{
	setfillstyle(SOLID_FILL,MauNenDoThi);
	bar(0, 0, 1280, 720);
	
	setThongTin();
	setMenu();
	setDoThi();

}

void setThongTin()
{
	int xdau=5; 	int xcuoi=300;
	int ydau=220;	int ycuoi=715;
	setfillstyle(SOLID_FILL,mauxanhgiongaokhoaccrush);
	bar(xdau,ydau,xcuoi,ycuoi);
	setfillstyle(0,MauNenDoThi);
	rectangle(xdau,ydau,xcuoi,ycuoi);
	
	line(xdau,ydau+50,xcuoi,ydau+50);
	int xgiua=(xdau+xcuoi)/2 -30;
	int ygiua=(ydau+ydau+50)/2;
	char *s=new char[8];
	s="THONG TIN";
	setbkcolor(mauxanhgiongaokhoaccrush);
	settextstyle(DEFAULT_FONT,0, 2);
	outtextxy(xgiua-8-3*16,ygiua-8,s);
	settextstyle(DEFAULT_FONT,0,1);
	delete s;

}

void setMenu()
{
	int xdau=5;		int xcuoi=300;
	int ydau=5;		int ycuoi=215;
	setfillstyle(SOLID_FILL,mauxanhgiongaokhoaccrush);
	bar(xdau,ydau,xcuoi,ycuoi);
	
	setfillstyle(0,MauNenDoThi);
	rectangle(xdau,ydau,xcuoi,ycuoi);
}

void setDoThi()
{
	int xdau=305;	int xcuoi=1275;
	int ydau=5;		int ycuoi=715;
	setfillstyle(SOLID_FILL,15);
	bar(xdau,ydau,xcuoi,ycuoi);
	setfillstyle(SOLID_FILL,15);
	
	setcolor(0);
	rectangle(xdau,ydau,xcuoi,ycuoi);
	setcolor(15);
	
}

// ============ THIET LAP NUT CHUC NANG ===============
void taoMangButton(button a[])
{
	a[0].xdau=25;		a[0].ydau=27;
	a[0].xcuoi=150;		a[0].ycuoi=97;
	a[0].content="2D 1";
	
	a[1].xdau=155;		a[1].ydau=27;
	a[1].xcuoi=280;		a[1].ycuoi=97;
	a[1].content="2D 2";
	
	a[2].xdau=25;		a[2].ydau=119;
	a[2].xcuoi=150;		a[2].ycuoi=189;
	a[2].content="3D 1";
	
	a[3].xdau=155;		a[3].ydau=119;
	a[3].xcuoi=280;		a[3].ycuoi=189;
	a[3].content="3D 2";
	
	a[0].mauButton=a[1].mauButton=a[2].mauButton=a[3].mauButton= mauxanhlacay;
	a[0].BGcolor=a[1].BGcolor=a[2].BGcolor=a[3].BGcolor=mauxanhlacay;

	
	
	for(int i=0;i<=3;i++)
	{
		a[i].doRongFont=2;
	}
	
}

void doiMauButton(button a, int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	rectangle(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	
	int xgiua=(a.xdau+a.xcuoi)/2;
	int ygiua=(a.ydau+a.ycuoi)/2;
	setbkcolor(color);
	settextstyle(DEFAULT_FONT,0, a.doRongFont);
	
	char*s=new char [a.content.length()+1];
	for(int i=0;i<a.content.length();i++)
	{
		s[i]=a.content[i];
	}
	s[a.content.length()]='\0';
	int denta=a.content.length()/2;
	outtextxy(xgiua-a.doRongFont*4-denta*a.doRongFont*8,ygiua-a.doRongFont*4,s);
	delete s;
}

void setButton(button a)
{
	setfillstyle(SOLID_FILL,a.mauButton);
	bar(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	setfillstyle(SOLID_FILL,MauNenDoThi);
	rectangle(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	
	int xgiua=(a.xdau+a.xcuoi)/2;
	int ygiua=(a.ydau+a.ycuoi)/2;
	setbkcolor(a.BGcolor);
	settextstyle(DEFAULT_FONT,0, a.doRongFont);
	//chuyen string thanh char*
	char*s=new char [a.content.length()+1];
	for(int i=0;i<a.content.length();i++)
	{
		s[i]=a.content[i];
	}
	s[a.content.length()]='\0';
	int denta=a.content.length()/2;
	//
	outtextxy(xgiua-a.doRongFont*4-denta*a.doRongFont*8,ygiua-a.doRongFont*4,s);
	delete s;
}
void drawMenuButton(button a[])
{
	for(int i=0;i<4;i++)
	{
		setButton(a[i]);
	}
}

void setGiaoDienHoatDong(int i)
{
	setfillstyle(SOLID_FILL,MauNenDoThi);
	bar(0, 0, 1280, 720);
	
	setThongTin();
	setMenu();
	int xdau=305;	int xcuoi=1275;
	int ydau=5;		int ycuoi=715;
	setfillstyle(SOLID_FILL,0);
	bar(xdau,ydau,xcuoi,ycuoi);
	setcolor(15);
	rectangle(xdau,ydau,xcuoi,ycuoi);
	
	button a[11];
	taoMangButton(a);
	drawMenuButton(a);
	doiMauButton(a[i],mauxanhlachuoi);
	
}


// ====================================================

// =============== BAT DIEU KIEN CHUOT ===============
void batDkClickChuot(button &a,int x,int y,button b[])
{
	if(ismouseclick(WM_LBUTTONUP))
	{
		int xtam; int ytam;
		getmouseclick(WM_LBUTTONUP,xtam,ytam);
		clearmouseclick(WM_LBUTTONUP);
		if(xtam>=25&&xtam<=150&&ytam>=27&&ytam<=97)
		{
			cout<<"Tong 2D 1"<<endl;
			xuLi2D1();
			cout<<"Da thoat ra khoi ham 2d1"<<endl;
			
			
		}
		else if(xtam>=155&&xtam<=280&&ytam>=27&&ytam<=97)
		{
			cout<<"Tong 2D 2"<<endl;
		}
		else if(xtam>=25&&xtam<=150&&ytam>=119&&ytam<=189)
		{
			cout<<"Tong 3D 1"<<endl;
		}
		else if(xtam>=25&&xtam<=150&&ytam>=119&&ytam<=189)
		{
			cout<<"Tong 3D 2"<<endl;
		}
		
		a.isChangeColor=false;
		clearmouseclick(WM_LBUTTONUP);
		
	}
	
}
void batDkChuot(button &a,int x,int y,button b[])
{
	batDkClickChuot(a,x,y,b);
 
	if(x>=a.xdau&&x<=a.xcuoi&&y>=a.ydau&&y<=a.ycuoi&&a.isChangeColor==false)
   	{
		a.isChangeColor=true;
		if(a.content=="2D 1")
		{
	
			setMenu();
			doiMauButton(b[0],b[0].mauKhiCham);
			setButton(b[1]);
			setButton(b[2]);
			setButton(b[3]);
		}
		else if(a.content=="2D 2")
		{
			setMenu();
			cout<<"tongkaka"<<endl;
			doiMauButton(b[1],b[1].mauKhiCham);
			setButton(b[0]);
			setButton(b[2]);
			setButton(b[3]);
			
		}
		else if(a.content=="3D 1")
		{
			setMenu();
			doiMauButton(b[2],b[2].mauKhiCham);
			setButton(b[0]);
			setButton(b[1]);
			setButton(b[3]);
		}
		else if(a.content=="3D 2")
		{	
			setMenu();
			doiMauButton(b[3],b[3].mauKhiCham);
			setButton(b[0]);
			setButton(b[1]);
			setButton(b[2]);
		}
		
	}

	else if(a.isChangeColor==true&&(x>=a.xdau&&x<=a.xcuoi&&y>=a.ydau&&y<=a.ycuoi)==false&&(x!=-1&&y!=-1))
	{	
		a.isChangeColor=false;
		if (a.content=="2D 1"||a.content=="2D 2"||a.content=="3D 1"||a.content=="3D 2")
		{
			setMenu();
			drawMenuButton(b);
		}
		else
		{
			setButton(a);
		}
		fflush(stdin);
	}
	fflush(stdin);
}


// =============== CHAY CHUONG TRINH =================
void xuLiChuot(button a[])
{
	int x=0,y=0;

	while(true)
	{
		delay(1);
		getmouseclick(WM_MOUSEMOVE,x,y);
		for(int i=0;i<=3;i++)
		{
			batDkChuot(a[i],x,y,a);
			
		}
		
	}
}

void xuLi()
{
	button a[11];
	taoMangButton(a);
	drawMenuButton(a);

	xuLiChuot(a);
}

