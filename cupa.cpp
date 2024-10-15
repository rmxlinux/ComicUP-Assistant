#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>
#include "opt.h"

/* copyright rmxlinux(c) 2024
This program is used to execute mouse operations recorded in files.
***TIMESET and TIMEEND are used to specify the start and end of a time list.
update 2024.0.0.02a: Time table moved to an extra program. 

Support the following operations:
X [x]        - Divide the milliseconds of all DELAY operations by x.
DELAY [ms]   - Wait for ms milliseconds.
MOV [x] [y]  - Move the mouse pointer to the screen (x, y) in absolute coordinates.
KEYDOWN [id] - Press the button corresponding to the ID.
KEYUP [id]   - Release the button corresponding to the ID.
LDOWN,LUP,
RDOWN,RUP    - Emulate the mouse operations.
END          - Indicates the end of the record.
*/
struct time_r{
	int h ;
	int m ;
	int s ; 
	time_r(int hh, int mm, int ss) :
		h(hh), m(mm), s(ss) {}
};
std::vector <time_r> table ;

double divide_rate = 1.0 ; 

void task(char* filename) {
	freopen(filename, "r", stdin) ;
	std::string com ;
	while(std::cin >> com) {
		if (com == "END") break ;
		if (com == "X")	std::cin >> divide_rate ;
		if (com == "DELAY") {
			int raw_ms ;
			std::cin >> raw_ms ;
			int real_ms = (int)((double)raw_ms / divide_rate) ;
			Sleep(real_ms) ;
		}
		if (com == "MOV") {
			int dx, dy ;
			std::cin >> dx >> dy ;
			moveto(dx, dy) ;
		}
		if (com == "KEYDOWN") {
			int key_id ;
			std::cin >> key_id ;
			keydown(key_id) ;
		}
		if (com == "KEYUP") {
			int key_id ;
			std::cin >> key_id ;
			keyup(key_id) ;
		}
		if (com == "LDOWN") { ldown() ; }
		if (com == "LUP") { lup() ; }
		if (com == "RDOWN") { rdown() ; }
		if (com == "RUP") { rup() ; }
	}
	fclose(stdin) ;
}

int main(int argc,char **argv) {
	if ( argc != 2 ) {
		printf("\
cupa [filename]\n\
contact dandinking@buaa.edu.cn for support.\
") ;
 		return 0 ;
	}
	task(argv[1]) ;
	return 0 ;
}
