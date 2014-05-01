#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include <conio.h>
//800*592
const int NotUsed = system( "color 70" );

int main()
{
    HWND hWnd = GetConsoleWindow();
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HDC hdc=GetDC(GetConsoleWindow());
    HPEN Pen=CreatePen(0,1,RGB(255,0,0));
    HBRUSH Brush = CreateSolidBrush(RGB(255,255,0));
    CONSOLE_SCREEN_BUFFER_INFO inf;
    //GetConsoleScreenBufferInfo(hStdOut,&inf);
    COORD sz=GetLargestConsoleWindowSize(hStdOut);
    sz.X=100;
    sz.Y=50;
    SMALL_RECT DisplayArea;
    DisplayArea.Left=0;
    DisplayArea.Top=0;
    DisplayArea.Right=sz.X-1;
    DisplayArea.Bottom=sz.Y-1;
    printf("\n%i:%i\n",sz.X,sz.Y);
    if(!SetConsoleScreenBufferSize(hStdOut,sz)) printf("ErrSCSBS\n%i",GetLastError());
    if(!MoveWindow(hWnd,0,0,800,600,TRUE)) printf("ERR");
    if(!SetConsoleWindowInfo(hStdOut,TRUE,&DisplayArea)) printf("NARKOMAN!");
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
      _getch();
    HBRUSH BrushClear = CreateSolidBrush(RGB(192,192,192));
    RECT RectClear;
    RectClear.top=0;
    RectClear.left=0;
    RectClear.bottom=600;
    RectClear.right=800;
    FillRect(hdc,&RectClear, BrushClear);
    MoveToEx(hdc,400,0,NULL);
    LineTo(hdc,400,600);
    MoveToEx(hdc,0,300,NULL);
    LineTo(hdc,800,300);
    SetPixel(hdc,-1,-1,RGB(255,255,255));
    _getch();
   }



/*int main()
{
    HWND hWnd = GetConsoleWindow();
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HDC hdc=GetDC(GetConsoleWindow());
    HPEN Pen=CreatePen(0,1,RGB(255,0,0));
    HBRUSH Brush = CreateSolidBrush(RGB(255,255,0));
    CONSOLE_SCREEN_BUFFER_INFO inf;
    //GetConsoleScreenBufferInfo(hStdOut,&inf);
    COORD sz=GetLargestConsoleWindowSize(hStdOut);
    sz.X=80;
    sz.Y=40;
    SMALL_RECT DisplayArea;
    DisplayArea.Left=0;
    DisplayArea.Top=0;
    DisplayArea.Right=sz.X-1;
    DisplayArea.Bottom=sz.Y-1;
    printf("\n%i:%i\n",sz.X,sz.Y);
    if(!SetConsoleScreenBufferSize(hStdOut,sz)) printf("ErrSCSBS\n%i",GetLastError());
    if(!MoveWindow(hWnd,0,0,640,480,TRUE)) printf("ERR");
    if(!SetConsoleWindowInfo(hStdOut,TRUE,&DisplayArea)) printf("NARKOMAN!");
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
   }*/
