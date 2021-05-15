#include "hamCoSo.h"
#include "VeGiaoDien.h"
#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

int banKinhMatTroi=50;
int banKinhTraiDat=25;
int mauMatTroi=12;// mau cam
int mauTraiDat=2;//mau Xanh la
int mauMatTrang=14;//mau Vang
int banKinhMatTrang=10;

//TT gia dinh 
int tr_x=0;
int tr_y=0;


int Mtt[3][3] =
{
	{1,0,0	},
	{0,1,0	},
	{tr_x, tr_y, 1}	
};

void veMatTroi(int xTam, int yTam)
{
	circleBresenham(xTam,yTam,banKinhMatTroi,mauMatTroi);
	setfillstyle(1,mauMatTroi);
	floodfill(xTam,yTam,mauMatTroi); 
	
}
void hoanViMang(int mangA[], int n)
{
	for(int i=0;i<(n-1)/2;i++)
	{
		int tam=mangA[i];
		mangA[i]=mangA[n-i-1];
		mangA[n-i-1]=tam;
	}
}
void veQuyDao(int xTam,int yTam, int XmangTong[], int YmangTong[], int &nTong)
{
	//Elipse(xTam,yTam,300,200,0);
	int Xmang1[1000];int n1=0;int Ymang1[1000];
	int Xmang2[1000];int n2=0;int Ymang2[1000];
	int Xmang3[1000];int n3=0;int Ymang3[1000];
	int Xmang4[1000];int n4=0;int Ymang4[1000];
	int Xmang5[1000];int n5=0;int Ymang5[1000];
	int Xmang6[1000];int n6=0;int Ymang6[1000];
	int Xmang7[1000];int n7=0;int Ymang7[1000];
	int Xmang8[1000];int n8=0;int Ymang8[1000];
	
	
    
    int a=300;
    int b=200;
    int color= 0;
    int xc=xTam;
    int yc=yTam;
    
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
		
		putpixel(xc+x,yc+y,color);// mang 1
		Xmang1[n1]=xc+x;
		Ymang1[n1]=yc+y;
		n1++;
		
    	putpixel(xc-x,yc+y,color);//mang 8 nguoc
    	Xmang8[n8]=xc-x;
		Ymang8[n8]=yc+y;
		n8++;
		
    	putpixel(xc-x,yc-y,color);//mang 5
    	Xmang5[n5]=xc-x;
		Ymang5[n5]=yc-y;
		n5++;
		
    	putpixel(xc+x,yc-y,color); //mang 4 nguoc
		Xmang4[n4]=xc+x;
		Ymang4[n4]=yc-y;
		n4++;
    
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
		putpixel(xc+x,yc+y,color);// mang 2 Nguoc
		Xmang2[n2]=xc+x;
		Ymang2[n2]=yc+y;
		n2++;
	
	
   		putpixel(xc-x,yc+y,color); //mang 7
		Xmang7[n7]=xc-x;
		Ymang7[n7]=yc+y;
		n7++;
		
		
   		putpixel(xc-x,yc-y,color); //mang 6 nguoc
		Xmang6[n6]=xc-x;
		Ymang6[n6]=yc-y;
		n6++;
		
		
    	putpixel(xc+x,yc-y,color); //mang 3
		Xmang3[n3]=xc+x;
		Ymang3[n3]=yc-y;
		n3++;
		
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

	hoanViMang(Xmang8,n8);
	hoanViMang(Ymang8,n8);
	
	hoanViMang(Xmang4,n4);
	hoanViMang(Ymang4,n4);
	
	hoanViMang(Xmang2,n2);
	hoanViMang(Ymang2,n2);
	
	hoanViMang(Xmang6,n6);
	hoanViMang(Ymang6,n6);
	
	
	for(int i=0;i<n1;i++)
	{
		XmangTong[nTong]=Xmang1[i];
		YmangTong[nTong]=Ymang1[i];
		nTong++;
	}
	
	for(int i=0;i<n2;i++)
	{
		XmangTong[nTong]=Xmang2[i];
		YmangTong[nTong]=Ymang2[i];
		nTong++;
	}
	
	for(int i=0;i<n3;i++)
	{
		XmangTong[nTong]=Xmang3[i];
		YmangTong[nTong]=Ymang3[i];
		nTong++;
	}
	
	for(int i=0;i<n4;i++)
	{
		XmangTong[nTong]=Xmang4[i];
		YmangTong[nTong]=Ymang4[i];
		nTong++;
	}
	
	for(int i=0;i<n5;i++)
	{
		XmangTong[nTong]=Xmang5[i];
		YmangTong[nTong]=Ymang5[i];
		nTong++;
	}
	
	for(int i=0;i<n6;i++)
	{
		XmangTong[nTong]=Xmang6[i];
		YmangTong[nTong]=Ymang6[i];
		nTong++;
	}

	for(int i=0;i<n7;i++)
	{
		XmangTong[nTong]=Xmang7[i];
		YmangTong[nTong]=Ymang7[i];
		nTong++;
	}
	
	for(int i=0;i<n8;i++)
	{
		XmangTong[nTong]=Xmang8[i];
		YmangTong[nTong]=Ymang8[i];
		nTong++;
	}
//	for(int i=0;i<nTong;i++)
//	{
//		cout<<XmangTong[i]<<"\t"<<YmangTong[i]<<endl;
//	}

}

void veTraiDat(int xTam, int yTam)
{
	circleBresenham(xTam,yTam,banKinhTraiDat,mauTraiDat);
	setfillstyle(1,mauTraiDat);
	floodfill(xTam,yTam,mauTraiDat); 
}

void xuLiVongLap(int mangX[], int mangY[], int n)
{	
	while(true)
	{
		
		for(int i=0;i<n;i+=10)
		{
			setDoThi();
			//THUAT TOAN TU VIET
			veMatTroi(790,360);
			Elipse(790,360,300,200,0);
			veTraiDat(mangX[i],mangY[i]);
			
			
//			//THUAT TOAN CO SAN
//			setcolor(0);
//			ellipse(790, 360, 0, 360, 300, 200) ;
//			
//			setcolor(mauMatTroi);
//			setfillstyle(SOLID_FILL,mauMatTroi);
//			pieslice(790,360,0,360,banKinhMatTroi);
//			
//			setcolor(mauTraiDat);
//			setfillstyle(SOLID_FILL,mauTraiDat);
//			pieslice(mangX[i],mangY[i],0,360,banKinhTraiDat);
			
			
			delay(100);
		}
		
	}
}

// A cap mxn * B cap nxp = C cap mxp
void nhan2MaTran(int A[][3], int B[][3], int C[][3], int m, int n, int p)
{
	for(int i=0;i<m;i++)
	{
		for(int k=0;k<p;k++)
		{
			C[i][k]=0;
			for(int j=0;j<n;j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void nhan2MaTran(double A[][3], double B[][3], double C[][3], int m, int n, int p)
{
	for(int i=0;i<m;i++)
	{
		for(int k=0;k<p;k++)
		{
			C[i][k]=0;
			for(int j=0;j<n;j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void maTranQo(double Qo[][3], double gocQuay)
{
	Qo[0][0]= cos(gocQuay);
	Qo[0][1]= sin(gocQuay);
	Qo[0][2]= 0;
	
	Qo[1][0]= -sin(gocQuay);
	Qo[1][1]= cos(gocQuay);
	Qo[1][2]= 0;
	
	Qo[2][0]=0;
	Qo[2][1]= 0;
	Qo[2][2]= 1;
	

}

void veVongTronQuyDao()
{
	double Qo[3][3];
		//VE VONG TRON TRUOC
		for(double i=0.0436;i<6.29;i+=0.0436)
		{
			double gocQuay=i;
			maTranQo(Qo,gocQuay);
			
			double traiDat[1][3] ={{790,610,1}};
			double maTranTTVeO[3][3]=
			{
				{1,0,0	},
				{0,1,0	},
				{-790, -360, 1}
			};
			double maTranTTVeLai[3][3]
			{
				{1,0,0	},
				{0,1,0	},
				{790, 360, 1}
			};
			double KQ1[1][3];
			double KQ2[1][3];
			double KQ3[1][3];
			
			nhan2MaTran(traiDat,maTranTTVeO,KQ1,1,3,3);
			nhan2MaTran(KQ1,Qo,KQ2,1,3,3);
			nhan2MaTran(KQ2,maTranTTVeLai,KQ3,1,3,3);

			
			setcolor(0);
			putpixel(KQ3[0][0],KQ3[0][1],0);
		}
		
}
//void matTrangXoay()
//{
//	
//}
void xuLiTam()
{
	while(true)
	{
		
		double Qo[3][3];
		double Qo_MT[3][3];
		//TRAI DAT XOAY
		for(double i=-0.0436;i>-6.29;i-=0.0436)
		{
			double gocQuay=i;
			maTranQo(Qo,gocQuay);
			
			double traiDat[1][3] ={{790,610,1}};
			double maTranTTVeO[3][3]=
			{
				{1,0,0	},
				{0,1,0	},
				{-790, -360, 1}
			};
			double maTranTTVeLai[3][3]
			{
				{1,0,0	},
				{0,1,0	},
				{790, 360, 1}
			};
			double KQ1[1][3];
			double KQ2[1][3];
			double KQ3[1][3];
			
			nhan2MaTran(traiDat,maTranTTVeO,KQ1,1,3,3);
			nhan2MaTran(KQ1,Qo,KQ2,1,3,3);
			nhan2MaTran(KQ2,maTranTTVeLai,KQ3,1,3,3);
			
			//MATTRANG
			double gocQuayMT=i*5;
			maTranQo(Qo_MT,gocQuayMT);
			double matTrang[1][3]={{890,610,1}};
			double KQMTXoay1[1][3];
			double KQMTXoay2[1][3];
			double KQMTXoay3[1][3];
			
			double maTranTTVeO_MT[3][3]=
			{
				{1,0,0	},
				{0,1,0	},
				{-790, -610, 1}
			};
			double maTranTTVeLai_MT[3][3]
			{
				{1,0,0	},
				{0,1,0	},
				{790, 610, 1}
			};
			nhan2MaTran(matTrang,maTranTTVeO_MT,KQMTXoay1,1,3,3);
			nhan2MaTran(KQMTXoay1,Qo_MT,KQMTXoay2,1,3,3);
			nhan2MaTran(KQMTXoay2,maTranTTVeLai_MT,KQMTXoay3,1,3,3);
			
			double matTrangNew[1][3]={{KQMTXoay3[0][0],KQMTXoay3[0][1],1}};
			
			double KQMT1[1][3];
			double KQMT2[1][3];
			double KQMT3[1][3];
			nhan2MaTran(matTrangNew,maTranTTVeO,KQMT1,1,3,3);
			nhan2MaTran(KQMT1,Qo,KQMT2,1,3,3);
			nhan2MaTran(KQMT2,maTranTTVeLai,KQMT3,1,3,3);

			//VE 
			setDoThi();
			veVongTronQuyDao();
			
			setcolor(mauMatTroi);
			setfillstyle(SOLID_FILL,mauMatTroi);
			pieslice(790,360,0,360,banKinhMatTroi);
			setcolor(0);
			circle(790,360,banKinhMatTroi);
			
			setcolor(mauTraiDat);
			setfillstyle(SOLID_FILL,mauTraiDat);
			pieslice(KQ3[0][0],KQ3[0][1],0,360,banKinhTraiDat);
			setcolor(0);
			circle(KQ3[0][0],KQ3[0][1],banKinhTraiDat);
			
			setcolor(mauMatTrang);
			setfillstyle(SOLID_FILL,mauMatTrang);
			pieslice(KQMT3[0][0],KQMT3[0][1],0,360,banKinhMatTrang);
			setcolor(0);
			circle(KQMT3[0][0],KQMT3[0][1],banKinhMatTrang);
		
			delay(1000);
		}		
	}
}


