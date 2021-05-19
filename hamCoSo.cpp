#include <math.h>
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <graphics.h>
#define ROUND(a) (int)(a+0.5)

void doiMayTinhSangNguoiDung(int xDoi, int yDoi, int x0, int y0, int &xKQ, int &yKQ)
{
	xKQ=(xDoi-x0)/5;
	yKQ=-(yDoi-y0)/5;
}


void lineDDA(int x1,int y1, int x2,int y2,int c){
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
//Elipse
void elipse(int xcenter,int ycenter,int xradius,int yradius, int color)
{
    int x,y; float c,p;
    x=0; y=yradius;
    c=(float)yradius/xradius;
    c=c*c; p=2*c-2*yradius+1;
    while (c*x<=y)
        {
            putpixel(xcenter+x,ycenter+y,color);
            putpixel(xcenter-x,ycenter+y,color);
            putpixel(xcenter+x,ycenter-y,color);
            putpixel(xcenter-x,ycenter-y,color);
            if (p<0) p += 2*c*(2*x+3);
            else
                {
                    p +=4*(1-y)+2*c*(2*x+3);
                    y--;
                }
            x++;
        }
   
    y=0;x=xradius;
    c= (float)xradius/yradius;
    c=c*c; p=2*c-2*xradius+1;
    while (c*y<=x)
        {
            putpixel(xcenter+x,ycenter+y,color);
            putpixel(xcenter-x,ycenter+y,color);
            putpixel(xcenter+x,ycenter-y,color);
            putpixel(xcenter-x,ycenter-y,color);
            if (p<0) p +=2*c*(2*y+3);
            else
                {
                    p +=4*(1-x)+2*c*(2*y+3);
                    x--;
                }
            y++;
        }
}

void Ve_HCN(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    lineDDA(x1,y1,x1,y2,color);
    lineDDA(x1,y1,x2,y1,color);
    lineDDA(x2,y2,x2,y1,color);
    lineDDA(x2,y2,x1,y2,color);
}
