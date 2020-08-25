/*
ID: yuanmax1
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    char map[10][10];
    int far;
    int cow;
    int dirf = 1;
    int dirc = 1;
    int done = 0;
    int time = 0;
    string str;
    for (int i = 0; i < 10; i++) {
    	fin >> str;
    	for (int j = 0; j < 10; j++) {
    		map[i][j] = str[j];
    		if (str[j] == 'F') {
    			far = i*10+j;
    		}
    		if (str[j] == 'C') {
    			cow = i*10+j;
    		}
    	}
    }
    while (!done) {
    	
    	if (dirf == 1) {
    		if ((far/10)-1 >= 0 && map[(far/10)-1][(far%10)] != '*') {
    			far = ((far/10)-1)*10+(far%10);
    		}
    		else {
    			dirf = 2;
    		}
    	}
    	else if (dirf == 2) {
    		if ((far%10) + 1 <= 9 && map[(far/10)][(far%10)+1] != '*') {
    			far = ((far/10))*10+((far%10)+1);
    		}
    		else {
    			dirf = 3;
    		}
    	}
    	else if (dirf == 3) {
    		if ((far/10)+1 <= 9 && map[(far/10)+1][(far%10)] != '*') {
    			far = ((far/10)+1)*10+(far%10);
    		}
    		else {
    			dirf = 4;
    		}
    	}
    	else if (dirf == 4) {
    		if ((far%10)-1 >= 0 && map[(far/10)][((far%10)-1)] != '*') {
    			far = ((far/10))*10+((far%10)-1);
    		}
    		else {
    			dirf = 1;
    		}
    	}
    	if (dirc == 1) {
    		if ((cow/10)-1 >= 0 && map[(cow/10)-1][(cow%10)] != '*') {
    			cow = ((cow/10)-1)*10+(cow%10);
    		}
    		else {
    			dirc = 2;
    		}
    	}
    	else if (dirc == 2) {
    		if ((cow%10) + 1 <= 9 && map[(cow/10)][(cow%10)+1] != '*') {
    			cow = ((cow/10))*10+((cow%10)+1);
    		}
    		else {
    			dirc = 3;
    		}
    	}
    	else if (dirc == 3) {
    		if ((cow/10)+1 <= 9 && map[(cow/10)+1][(cow%10)] != '*') {
    			cow = ((cow/10)+1)*10+(cow%10);
    		}
    		else {
    			dirc = 4;
    		}
    	}
    	else if (dirc == 4) {
    		if ((cow%10)-1 >= 0 && map[(cow/10)][((cow%10)-1)] != '*') {
    			cow = ((cow/10))*10+((cow%10)-1);
    		}
    		else {
    			dirc = 1;
    		}
    	}
    	time++;
    	if (far == cow) {
    		fout << time << endl;
    		done = 1;
    	}
    	if (time > 10000) {
    		fout << 0 << endl;
    		done = 1;
    	}
    	
    	
    }
    /*for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
    		cout << map[i][j];
    	}
    	cout << endl;
    }*/
    //cout << far << " " << cow << endl;
    
    return 0;
}