#include <iostream>
#include <cstdio>
#include <fstream> 
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <windows.h>
//ansi
#define cur() std::chrono::high_resolution_clock::now()
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void getPos(int& x, int& y) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    x = cursorPos.x;
    y = cursorPos.y;
}

int iskp[256 + 5] ;
std::ofstream tout("crontab") ;
void intro() {
	//create script file
	time_t rawtime;  
	struct tm * timeinfo;
	time(&rawtime);  
	timeinfo = localtime(&rawtime); 
	std::string ctt ;
	printf("Ϊ��β���ȡһ�����֣�") ; 
	std::cin >> ctt ;
	ctt += ".scp" ;
	std::string name = ctt ;
	std::ofstream out(ctt.c_str()) ;
	printf("������ƻ�����ʱ�䣬ÿ��һ��������end��������ʽ��������HH:MM:SS������7:59:21\n") ;
	printf("-----------��ǰʱ��: %d:%d:%d\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec) ;
	//freopen("temp.scp", "w", stdout) ;
	while(std::cin >> ctt) {
		if(ctt.find(':') > 19260817) break ;
		tout << ctt << ' ' << name << std::endl ;
	}
	printf("��Ҫ�������в�����(y/n)") ;
	char opt = getch() ;
	if(opt == 'y') {
		printf("\n�������ٶȱ���\n") ;
		std::cin >> ctt ;
		out << "X " << ctt << std::endl ;
	}
	printf("\n������ʼ��¼�����������׼�����ˣ����������ڣ�Ȼ���¼����ϵ��������\n") ;
	printf("��¼�����밴ESC���˳�\n") ;
	getch() ;
	printf("\n��ʼ��¼\n") ;
	memset(iskp, 0, sizeof(iskp)) ;
	auto last_ms = cur() ;
	std::chrono::duration<double> duration ;
	int x, y ;
	Sleep(50) ;
	while(1) {
		//check if there is new opt
		//first check mouse
		auto now_ms = cur() ;
		duration = now_ms - last_ms ;
		int dur = duration.count()*1000.0 ;
		if(KEY_DOWN(VK_ESCAPE)) break ;
		if(KEY_DOWN(VK_LBUTTON)) {
			if(!iskp[VK_LBUTTON]) {
				iskp[VK_LBUTTON] = 1 ;
				out << "DELAY " << dur << std::endl ;
				getPos(x, y) ;
				out << "MOV " << x << " " << y << std::endl ;
				out << "LDOWN" << std::endl ;
				last_ms = now_ms ;
			}
		}
		else {
			if(iskp[VK_LBUTTON]) {
				iskp[VK_LBUTTON] = 0 ;
				out << "DELAY " << dur << std::endl ;
				getPos(x, y) ;
				out << "MOV " << x << " " << y << std::endl ;
				out << "LUP" << std::endl ;
				last_ms = now_ms ;
			}
		}
		if(KEY_DOWN(VK_RBUTTON)) {
			if(!iskp[VK_RBUTTON]) {
				iskp[VK_RBUTTON] = 1 ;
				out << "DELAY " << dur << std::endl ;
				getPos(x, y) ;
				out << "MOV " << x << " " << y << std::endl ;
				out << "RDOWN" << std::endl ;
				last_ms = now_ms ;
			}
		}
		else {
			if(iskp[VK_RBUTTON]) {
				iskp[VK_RBUTTON] = 0 ;
				out << "DELAY " << dur << std::endl ;
				getPos(x, y) ;
				out << "MOV " << x << " " << y << std::endl ;
				out << "RUP" << std::endl ;
				last_ms = now_ms ;
			}
		}
		for(int i = 0; i < 256; i ++) {
			if(i == VK_RBUTTON || i == VK_LBUTTON) continue ;
			if(KEY_DOWN(i)) {
				if(!iskp[i]) {
					iskp[i] = 1 ;
					out << "DELAY " << dur << std::endl ;
					out << "KEYDOWN " << i << std::endl ;
					last_ms = now_ms ;
				}
			}
			else {
				if(iskp[i]) {
					iskp[i] = 0 ;
					out << "DELAY " << dur << std::endl ;
					out << "KEYUP " << i << std::endl ;
					last_ms = now_ms ;
				}
			}
		}
	}
	out << "END" << std::endl ;
	out.close() ;
	printf("��¼��ϡ�\n\n") ;
	return ;
}

int main() {
	printf("\
ComicUP Assistant 2024.0.0.02a ��������\n\
Copyright (C)2024 rmxlinux\n\n\
������������������⣬������easy_intro_utf8.exe��\n\
If you encounter corrupted content, please run easy_intro_utf8.exe.\n\n\
") ;
	while(1) {
		intro() ;
		printf("�Ƿ������¼�Ʋ�����(y/n)") ;
		getch() ;
		char ch = getch() ;
		if(ch != 'y') break ;
	}
	printf("\n����¼����ϣ��Ѿ���ʼ��ʱ������رձ�����\n\n") ;
	tout.close() ;
	system("time_table crontab") ;
	return 0 ;
}
