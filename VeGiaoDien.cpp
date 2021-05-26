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
#include "ve2D2.h"
#include "ve3D1.h"
#include "ve3D3.h"
#include "ve3DHinhCau.h"
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
	setcolor(0);
	
//	for(int i=305;i<=1275;i+=5)
//	{
//		line(i,5,i,715);
//	}
//	for(int j=5;j<=715;j+=5)
//	{
//		line(305,j,1275,j);
//	}
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
	a[2].xcuoi=108;		a[2].ycuoi=189;
	a[2].content="3D1";
	
	a[3].xdau=113;		a[3].ydau=119;
	a[3].xcuoi=195;		a[3].ycuoi=189;
	a[3].content="3D2";
	
	a[4].xdau=200;		a[4].ydau=119;
	a[4].xcuoi=280;		a[4].ycuoi=189;
	a[4].content="3D3";
	
	a[0].mauButton=a[1].mauButton=a[2].mauButton=a[3].mauButton= a[4].mauButton= mauxanhlacay;
	a[0].BGcolor=a[1].BGcolor=a[2].BGcolor=a[3].BGcolor=a[4].BGcolor=mauxanhlacay;

	
	
	for(int i=0;i<=4;i++)
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
	for(int i=0;i<5;i++)
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
	
	if(i==0) setfillstyle(SOLID_FILL,0);
	else setfillstyle(SOLID_FILL,15);

	if(i != 1)
	{
		bar(xdau,ydau,xcuoi,ycuoi);
	
	}
	setcolor(0);
	rectangle(xdau,ydau,xcuoi,ycuoi);
	setcolor(15);
//	for(int i=305;i<=1275;i+=5)
//	{
//		line(i,5,i,715);
//	}
//	for(int j=5;j<=715;j+=5)
//	{
//		line(305,j,1275,j);
//	}

	button a[11];
	taoMangButton(a);
	drawMenuButton(a);
	doiMauButton(a[i],mauxanhlachuoi);
	setcolor(15);
	
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
			tinhTien();
		}
		else if(xtam>=25&&xtam<=108&&ytam>=119&&ytam<=189)
		{
			cout<<"Tong 3D 1"<<endl;
			hamVeHinhNon();
		}
		else if(xtam>=113&&xtam<=195&&ytam>=119&&ytam<=189)
		{
			cout<<"Tong 3D 2"<<endl;
			//hamVeHinhCau();
			runHinhCau();
		}
		else if(xtam>=200&&xtam<=280&&ytam>=119&&ytam<=189)
		{
			cout<<"Tong 3D 3"<<endl;
			hamVeHinhHopChuNhat();
		
			
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
			setButton(b[4]);
		}
		else if(a.content=="2D 2")
		{
			setMenu();
			cout<<"tongkaka"<<endl;
			doiMauButton(b[1],b[1].mauKhiCham);
			setButton(b[0]);
			setButton(b[2]);
			setButton(b[3]);
			setButton(b[4]);
			
		}
		else if(a.content=="3D1")
		{
			setMenu();
			doiMauButton(b[2],b[2].mauKhiCham);
			setButton(b[0]);
			setButton(b[1]);
			setButton(b[3]);
			setButton(b[4]);
		}
		else if(a.content=="3D2")
		{	
			setMenu();
			doiMauButton(b[3],b[3].mauKhiCham);
			setButton(b[0]);
			setButton(b[1]);
			setButton(b[2]);
			setButton(b[4]);
		}
		else if(a.content=="3D3")
		{
			setMenu();
			doiMauButton(b[4],b[4].mauKhiCham);
			setButton(b[0]);
			setButton(b[1]);
			setButton(b[2]);
			setButton(b[3]);
		}
		
	}

	else if(a.isChangeColor==true&&(x>=a.xdau&&x<=a.xcuoi&&y>=a.ydau&&y<=a.ycuoi)==false&&(x!=-1&&y!=-1))
	{	
		a.isChangeColor=false;
		if (a.content=="2D 1"||a.content=="2D 2"||a.content=="3D1"||a.content=="3D2")
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
		for(int i=0;i<=4;i++)
		{
			batDkChuot(a[i],x,y,a);
			
		}
		
	}
}
int nhapDuLieu(string text, int sl, int hang)
{
	int x=15;
	int y=280;
	setbkcolor(mauxanhgiongaokhoaccrush);
	char* thongDiep=new char[text.length()+1]; 
 	strcpy(thongDiep,text.c_str());
	outtextxy(x,y +30*hang ,thongDiep); 
	char c[sl];
	int i=0;
	do
	{
		while(!kbhit());
		char s=getch();
		fflush(stdin);
		if(s!=13&&s!=8&&((s-48>=0&&s-48<=9)||s==45)&&i<=sl-1)
		{
			if(i!=0&&s==45)
			{
				
			}
			else
			{
				c[i]=s;
				char tam[2];
				tam[0]=s;
				tam[1]='\0';
				outtextxy(x+text.length()*8+i*8,y+30*hang,tam);
				i++;
			}
		}
		else if(s==8&&i>0)
		{
			i--;
			outtextxy(x+text.length()*8+i*8,y+30*hang," ");
		}
		else if(s==13&&i>0)//&&c[0]!='0'
		{
			break;
		}
		fflush(stdin);
	}
	while(true);
	int trongso=0;
	if(c[0]==45)
	{
		for(int j=1;j<i;j++)
		{
			trongso=trongso*10+(c[j]-48);
		}
		trongso*=-1;
	}
	else {
		for(int j=0;j<i;j++)
		{
			trongso=trongso*10+(c[j]-48);
		}
	}
	
	return trongso;
}
void ghiDSTV()
{
	settextstyle(DEFAULT_FONT,0, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(600,50,"DANH SACH THANH VIEN");
	outtextxy(500,50+50,"1.DUONG PHAM THANH TONG - N18DCCN189");
	outtextxy(500,50+100,"2.NGUYEN LONG NHAT - N18DCCN141");
	outtextxy(500,50+150,"3.NGUYEN VAN DUC - N18DCCN045");
	outtextxy(500,50+200,"4.VU NGOC LINH - N18DCCN105");
	outtextxy(500,50+250,"5.NGUYEN HOANG LONG - N18DCCN108");
	
	
	
	
	setcolor(15);
}
void xuLi()
{
	button a[11];
	taoMangButton(a);
	drawMenuButton(a);

	xuLiChuot(a);
}

