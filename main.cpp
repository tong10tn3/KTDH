#include <graphics.h> 
#include "VeGiaoDien.h"
#include "ve3D3.h"
using namespace std;

int main()//int argc, char *argv[]
{
	initwindow(1280+8,720+12);
	setGiaoDien();
	ghiDSTV();
	xuLi();
	getch();
	return 0;
	
}



