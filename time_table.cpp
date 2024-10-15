#include <iostream>
#include <cstring>
#include <windows.h>
#include <vector>
#include <time.h>

struct time_r{
	int h ;
	int m ;
	int s ; 
	std::string filename ;
	time_r(int hh, int mm, int ss, std::string str) :
		h(hh), m(mm), s(ss), filename(str) {}
};
std::vector <time_r> table ;

int main(int argc, char **argv) {
	if ( argc != 2 ) {
		printf("\
time_table [filename]\n\
contact dandinking@buaa.edu.cn for support.\
") ;
 		return 0 ;
	}
	std::string com ;
	freopen(argv[1], "r", stdin) ;
	int th, tm, ts ;
	while(~scanf("%d:%d:%d", &th, &tm, &ts)) {
		std::cin >> com ;
		table.push_back(time_r(th, tm, ts, com)) ;
	}
	fclose(stdin) ;
	time_t rawtime;  
	struct tm * timeinfo;
	while(1) {  
	    time(&rawtime);  
	    timeinfo = localtime(&rawtime);  
	    for(int i = 0; i < table.size(); i ++) {
		    	if(
			(timeinfo->tm_hour == table[i].h) &&
	        (timeinfo->tm_min  == table[i].m) &&
	        (timeinfo->tm_sec  == table[i].s)) {
	        	std::string command = "cupa " ;
	        	command += table[i].filename ;
	        	system(command.c_str()) ;
			}
		}
	}
	return 0 ;
}
