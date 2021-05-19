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


// ==================== KHAI BAO ======================


struct button
{
	int xdau;
	int ydau;
	int xcuoi;
	int ycuoi;
	string content;
	int mauButton= mauxanhlacay;
	int BGcolor=mauxanhlacay;
	bool isChangeColor=false;
	int mauKhiCham=mauxanhlachuoi;
	int doRongFont=1;
	bool click=false;
};

// ====================================================

// =============== THIET LAP GIAO DIEN ================
		void setGiaoDien();
		void setGiaoDienHoatDong(int i);
		
		void setMenu();
		void setDoThi();
		void setThongTin();
// ====================================================

// ============ THIET LAP NUT CHUC NANG ===============
		void taoMangButton(button a[]);
		void doiMauButton(button a, int color);
		void setButton(button a);
		void drawMenuButton(button a[]);
		
// ====================================================



// =============== BAT DIEU KIEN CHUOT ===============
		void batDkChuot(button &a, int x,button b[]);
	
// ===================================================

// =============== CHAY CHUONG TRINH =================
		void xuLiChuot(button a[]);
		void xuLi();
// ===================================================

