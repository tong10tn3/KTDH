#include "hamCoSo.h"
#include "VeGiaoDien.h"
#include "ve3D1.h"
#include "mylib.h"
#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
double maTranTinhTien[3][3]=
			{
				{1,0,0},
				{0,1,0},
				{-2,0,1}
};
double maTranDonVi[3][3]=
			{
				{1,0,0},
				{0,1,0},
				{0,0,1}
			};
//ma tran 2 diem ve thung xe sau
double maTranThung1[1][3]={{950,400,1}};
double maTranThung2[1][3]={{1250,500,1}};
//ma tran 2 diem ve dau xe 1
double maTranDauXe1[1][3]={{900, 430,1}};
double maTranDauXe2[1][3]={{950, 500,1}};
//ma tran 2 diem ve dau xe 2
double maTranDauXe11[1][3]={{870, 460,1}};
double maTranDauXe22[1][3]={{900, 500,1}};
//ma tran banh xe truoc
double maTranBanhXe1[1][3]={{910,500,1}};
//ma tran banh xe thu 2 
double maTranBanhXe2[1][3]={{1030,500,1}};
//ma tran banh xe thu 3
double maTranBanhXe3[1][3]={{1170,500,1}};
//ma tran duong thang ve kinh oto
double maTranKinh1[1][3]={{900, 430,1}};
double maTranKinh2[1][3]={{870, 460,1}};

void veOtoTai(){
	//thùng xe sau
	Ve_HCN(950, 400, 1250, 500, 0);
	setfillstyle(1,14);
	floodfill(955, 405,0);
	//bánh xe truoc cua thung
	circle(1030,500,20);
	circle(1030,500,12);
	setcolor(15);
	line(1018,500,1042,500);
	setcolor(0);
	setfillstyle(1,7);
	floodfill(1030, 500,0);
	
	//mau lop
	setfillstyle(1,0);
	floodfill(1043, 501,0);
	floodfill(1043, 499,0);
	
	//bánh xe sau cua thung
	circle(1170,500,20);
	circle(1170,500,12);
	setcolor(15);
	line(1158,500,1182,500);
	setfillstyle(1,7);
	floodfill(1170, 500,0);
	//mau lop
	setfillstyle(1,0);
	floodfill(1183, 501,0);
	floodfill(1183, 499,0);
	
	//dau xe
	Ve_HCN(900, 430, 950, 500, 0);
	setfillstyle(1,1);
	floodfill(901, 431,0);
	Ve_HCN(870, 460, 900, 500, 0);
	setfillstyle(1,1);
	floodfill(871, 461,0);
	line(900, 430,870, 460);
	
	//banh xe dau
	circle(910,500,20);
	circle(910,500,12);
	setcolor(15);
	line(898,500,922,500);
	setfillstyle(1,7);
	floodfill(910, 500,0);
	//mau lop
	setfillstyle(1,0);
	floodfill(923, 501,0);
	floodfill(894, 498,0);
	floodfill(923, 499,0);
	
	//mau cua kinh
	setfillstyle(1,7);
	floodfill(895, 449,0);
}
void tinhTien(){
	double mt11[1][3];
	double mt12[1][3];
	
	double mt21[1][3];
	double mt22[1][3];
	
	double mt31[1][3];
	double mt32[1][3];
	
	double mt41[1][3];
	double mt42[1][3];
	
	double mt51[1][3];
	double mt52[1][3];
	double mt53[1][3];
	int page=0;
	for(int i=0;i<280;i++){
		setactivepage(page);
		setvisualpage(1-page);
		setGiaoDien();
		//duong di
		setfillstyle(1,8);
		bar(306,480,1275,590);
		//le duong
		setfillstyle(1,2);
		bar(306,591,1275,800);
		//bau troi
		setfillstyle(1,9);
		bar(306,479,1275,5);
		//giai phan cach
		VePhanCach(320,530,0);
		VePhanCach(520,530,0);
		VePhanCach(720,530,0);
		VePhanCach(920,530,0);
		VePhanCach(1120,530,0);
		//Ve banh xe thu 1
		circleBresenham(mt51[0][0],mt51[0][1],20,0);
		setfillstyle(1,0);
		floodfill(mt51[0][0],mt51[0][1],0);
		circleBresenham(mt51[0][0],mt51[0][1],12,15);
		nhan2MaTran(maTranBanhXe1,maTranTinhTien,mt51,1,3,3);
		nhan2MaTran(mt51,maTranDonVi,maTranBanhXe1,1,3,3);
		//Ve banh xe thu 2
		circleBresenham(mt52[0][0],mt52[0][1],20,0);
		setfillstyle(1,0);
		floodfill(mt52[0][0],mt52[0][1],0);
		circleBresenham(mt52[0][0],mt52[0][1],12,15);
		nhan2MaTran(maTranBanhXe2,maTranTinhTien,mt52,1,3,3);
		nhan2MaTran(mt52,maTranDonVi,maTranBanhXe2,1,3,3);
		//Ve banh xe thu 3
		circleBresenham(mt53[0][0],mt53[0][1],20,0);
		setfillstyle(1,0);
		floodfill(mt53[0][0],mt53[0][1],0);
		circleBresenham(mt53[0][0],mt53[0][1],12,15);
		nhan2MaTran(maTranBanhXe3,maTranTinhTien,mt53,1,3,3);
		nhan2MaTran(mt53,maTranDonVi,maTranBanhXe3,1,3,3);
		//Ve thung xe sau
		Ve_HCN_DDA(mt11[0][0],mt11[0][1],mt12[0][0],mt12[0][1],0);
		setfillstyle(1,14);
		floodfill(mt11[0][0]+1,mt11[0][1]+1,0);
		
		nhan2MaTran(maTranThung1,maTranTinhTien,mt11,1,3,3);
		nhan2MaTran(mt11,maTranDonVi,maTranThung1,1,3,3);
		
		nhan2MaTran(maTranThung2,maTranTinhTien,mt12,1,3,3);
		nhan2MaTran(mt12,maTranDonVi,maTranThung2,1,3,3);
		//Ve dau xe thu 2
		Ve_HCN_DDA(mt21[0][0],mt21[0][1],mt22[0][0],mt22[0][1],0);
		setfillstyle(1,1);
		floodfill(mt21[0][0]+1,mt21[0][1]+1,0);
		
		nhan2MaTran(maTranDauXe1,maTranTinhTien,mt21,1,3,3);
		nhan2MaTran(mt21,maTranDonVi,maTranDauXe1,1,3,3);
		
		nhan2MaTran(maTranDauXe2,maTranTinhTien,mt22,1,3,3);
		nhan2MaTran(mt22,maTranDonVi,maTranDauXe2,1,3,3);
		//Ve dau xe thu 1
		Ve_HCN_DDA(mt31[0][0],mt31[0][1],mt32[0][0],mt32[0][1],0);
		setfillstyle(1,1);
		floodfill(mt31[0][0]+1,mt31[0][1]+1,0);
		
		nhan2MaTran(maTranDauXe11,maTranTinhTien,mt31,1,3,3);
		nhan2MaTran(mt31,maTranDonVi,maTranDauXe11,1,3,3);
		
		nhan2MaTran(maTranDauXe22,maTranTinhTien,mt32,1,3,3);
		nhan2MaTran(mt32,maTranDonVi,maTranDauXe22,1,3,3);
		
		lineDDA(mt21[0][0]+1,mt21[0][1]+1,mt31[0][0]+1,mt31[0][1]-1,0);
		setfillstyle(1,15);
		floodfill(mt21[0][0]+1-1,mt21[0][1]+6,0);
		line(305,590,1275,590);
		line(305,480,mt31[0][0],480);
		line(1275,480,mt12[0][0],480);
		page=1-page;
		delay(1);
		}
}
