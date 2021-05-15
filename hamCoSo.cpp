#include <math.h>
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <graphics.h>
#define ROUND(a) (int)(a+0.5)



void DoiNguoiDungSangMayTinh(int xDoi, int yDoi,int x0,int y0)
{
	int xKQ,yKQ;
	if(xDoi>0){
		xKQ=(xDoi*5)+x0;
		if(yDoi>0){
			yKQ=y0-(yDoi*5);
		}
		else{
			yKQ=y0+(abs(yDoi)*5);
		}
	}
	else{
		xKQ=x0-(abs(xDoi)*5);
		if(yDoi>0){
			yKQ=y0-(yDoi*5);
			}
		else{
			yKQ = y0+(abs(yDoi)*5);
		}
	}
}
 
void lineDDA(int x1,int y1, int x2,int y2, int c){
	int i,j,step;
	int dx=x2-x1;
	int dy=y2-y1;
	abs(dx)>=abs(dy) ? step=abs(dx) : step=abs(dy);
	float inc_x = (float) dx/step;
	float inc_y = (float) dy/step;
	if(abs(dx)>=abs(dy) || abs(dx)<=abs(dy)){
		float x=x1;
		float y=y1;
		for(i=0;i<=abs(step);i++){
			putpixel(round(x),round(y),c);
			x+=inc_x;
			y+=inc_y;
		}
	}
}
void lineDDA(double x1,double y1, double x2,double y2, int c){
	int i,j,step;
	int dx=x2-x1;
	int dy=y2-y1;
	abs(dx)>=abs(dy) ? step=abs(dx) : step=abs(dy);
	float inc_x = (float) dx/step;
	float inc_y = (float) dy/step;
	if(abs(dx)>=abs(dy) || abs(dx)<=abs(dy)){
		float x=x1;
		float y=y1;
		for(i=0;i<=abs(step);i++){
			putpixel(round(x),round(y),c);
			x+=inc_x;
			y+=inc_y;
		}
	}
}
void ve8diem(int x0,int y0,int x, int y, int color)
{

  putpixel( x0 + x , y0 + y ,color);

  putpixel( x0 - x , y0 + y ,color);

  putpixel( x0 + x , y0 - y ,color);

  putpixel( x0 - x , y0 - y ,color);

  putpixel( x0 + y , y0 + x ,color);

  putpixel( x0 - y , y0 + x ,color);

  putpixel( x0 + y , y0 - x ,color);

  putpixel( x0 - y , y0 - x ,color);

}

void circleBresenham(int x0,int y0,int r, int color)
{

  int x=0;int y=r;

  int p=3-2*r;

  while (x<=y)

  {

   ve8diem(x0,y0,x,y,color);

   if(p<0) p=p+4*x+6;

   else

       {

            p=p+4*(x-y)+10;

            y=y-1;

       }

   x=x+1;

  }

}
void circleBresenham(double x0,double y0,int r, int color)
{

  int x=0;int y=r;

  int p=3-2*r;

  while (x<=y)

  {

   ve8diem(x0,y0,x,y,color);

   if(p<0) p=p+4*x+6;

   else

       {

            p=p+4*(x-y)+10;

            y=y-1;

       }

   x=x+1;

  }

}
//Elipse
void Ve4diem(int xc,int yc,int x, int y,int color)//ve 4 diem doi xung
{
    putpixel(xc+x,yc+y,color);
    putpixel(xc-x,yc+y,color);
    putpixel(xc-x,yc-y,color);
    putpixel(xc+x,yc-y,color);
  
}
void Elipse(int x_center,int y_center,int a,int b,int color)// ve elipse
{
    float p,a2,b2;
	int x,y;
	a2=pow(a,2);
	b2=pow(b,2);
	x=0;
	y=b;
	
	p=2*((float)b2/a2)-(2*b)+1;
	
	//ve nhanh thu 1(tu tren xuong )
	while(((float)b2/a2)*x<=y)
	{
		Ve4diem(x_center,y_center,x,y,color);
		if(p<0)
		{
			p=p+2*((float)b2/a2)*(2*x+3);
		}
		else{
			p= p- 4*y + 2*((float)b2/a2)*(2*x+3);
			y--;
		}
		x++;
	}
	//ve nhanh thu 2(tu duoi len )
	y=0;
	x=a;
	p=2*((float)a2/b2)-2*a+1;
	while(((float)a2/b2)*y<=x)
	{
		Ve4diem(x_center,y_center,x,y,color);
		if(p<0)
		{
			p=p	+2*((float)a2/b2)*(2*y+3);
		}
		else
		{
			p=p- 4*x + 2*((float)a2/b2)*(2*y+3);
			x=x-1;
		}
		y=y+1;
	}
}
void Ve_HCN(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    line(x1,y1,x1,y2);
    line(x1,y1,x2,y1);
    line(x2,y2,x2,y1);
    line(x2,y2,x1,y2);
}
void Ve_HCN_DDA(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    lineDDA(x1,y1,x1,y2,color);
    lineDDA(x1,y1,x2,y1,color);
    lineDDA(x2,y2,x2,y1,color);
    lineDDA(x2,y2,x1,y2,color);
}

void VePhanCach(double x,double y,int color){
	setcolor(color);
	lineDDA(x,y,x+100,y,0);
	lineDDA(x+10,y+7,x+100+10,y+7,0);
	lineDDA(x,y,x+10,y+7,0);
	lineDDA(x+100,y,x+100+10,y+7,0);
	setfillstyle(1,15);
	floodfill(x+5,y+1,0);
}
