#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include <conio.h>

const int NotUsed = system( "color 70" );

int main()
{
    HWND hWnd = GetConsoleWindow();
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HDC hdc=GetDC(GetConsoleWindow());
    HPEN Pen=CreatePen(0,1,RGB(255,0,0));
    HBRUSH Brush = CreateSolidBrush(RGB(255,255,0));
    if(!MoveWindow(hWnd,0,0,640,480,TRUE)) printf("ERR");
    SelectObject(hdc,Pen);
    SetPixel(hdc, 10,10, RGB(0,0,0));
    RECT r; //объ€вл€ем экзмепл€р структуры RECT - координаты пр€моугольника.
    r.left=100; //левый верхний угол
    r.top=100;
    r.right=200; //правый нижний
    r.right=300;
    FillRect(hdc,&r, Brush);
    MoveToEx(hdc, 0, 0, NULL);
    LineTo(hdc, 150, 150);
    printf("%i",GetPixel(hdc,20,30));
      _getch();
    HBRUSH BrushClear = CreateSolidBrush(RGB(192,192,192));
    RECT RectClear;
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    MoveToEx(hdc,320,0,NULL);
    LineTo(hdc,320,480);
    MoveToEx(hdc,0,240,NULL);
    LineTo(hdc,640,240);
    SetPixel(hdc,-1,-1,RGB(255,255,255));
    _getch();
   }
