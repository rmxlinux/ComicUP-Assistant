#ifndef OPT_H
#define OPT_H

#include <windows.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void getPos(int& x, int& y) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    x = cursorPos.x;
    y = cursorPos.y;
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

#endif
