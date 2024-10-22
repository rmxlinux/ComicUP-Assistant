#ifndef OPT_H
#define OPT_H

#include <windows.h>
#include <cstring>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void can_can_need(const char* h) {
    HWND target = FindWindow(NULL, h) ;
    if(target) SetForegroundWindow(target) ;
}
void can_can_need(HWND target) { if(target) SetForegroundWindow(target) ; }
void getPos(int& x, int& y) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    x = cursorPos.x;
    y = cursorPos.y;
}
std::string getWindowTitle(HWND hWnd) {
    char buffer[1024];
    int length = GetWindowText(hWnd, buffer, 1024);
    return (length) ? std::string(buffer) : "";
}
void getRelativePos(int &x, int &y, std::string &title) {
    int x_abs, y_abs ;
    getPos(x_abs, y_abs) ;
    HWND NowWindow = GetForegroundWindow() ;
    can_can_need(NowWindow) ;
    RECT win_r ;
    GetWindowRect(NowWindow, &win_r) ;
    x = win_r.left - x_abs ;
    y = win_r.top - y_abs ;
    title = getWindowTitle(NowWindow) ;
}
void showDesktop() {
	HWND desktopWindow = GetDesktopWindow();
    ShowWindow(desktopWindow, SW_SHOWNORMAL);
    SetForegroundWindow(desktopWindow);
}
 
void click()  { mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); }
void rclick() { mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0); }
void key(int k) { keybd_event(k, 0, 0, 0), keybd_event(k, 0, KEYEVENTF_KEYUP, 0); }
void keydown(int k) { keybd_event(k, 0, 0, 0); }
void keyup(int k) { keybd_event(k, 0, KEYEVENTF_KEYUP, 0); }
void ldown() { mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); }
void rdown() { mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0); }
void lup() { mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); }
void rup() { mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0); }

void moveto(int x,int y) { SetCursorPos(x, y); }
void moveto_r(int rx, int ry) {
    HWND NowWindow = GetForegroundWindow() ;
    RECT win_r ;
    GetWindowRect(NowWindow, &win_r) ;
    int x_abs = win_r.left + rx ;
    int y_abs = win_r.top + ry ;
    moveto(x_abs, y_abs) ;
}

#endif
