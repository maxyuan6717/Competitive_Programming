/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N, K, R;
int cow[100001] = {0};
int cowc[101][2] = {0};
char field[199][199];
int field2[100][100] = {0};
int cfind[199][199] = {0};
int counter = 1;
int num = 1;
int ans = 0;
void flood(int x, int cy, int cx) {
	field2[cy/2][cx/2] = counter;
	if (field[cy][cx] == 'c' && cfind[cy][cx] != 1) {
		cfind[cy][cx] = 1;	
		cow[counter]++;
	}	
	if (cy > 0 && field[cy-1][cx] == '0' && field2[cy/2 - 1][cx/2] != counter) {
		flood(x,cy-2,cx);
	}
	if (cx < 2*(N-1) && field[cy][cx+1] == '0' && field2[cy/2][cx/2 + 1] != counter) {
		flood(x,cy,cx+2);
	}
	if (cy < 2*(N-1) && field[cy+1][cx] == '0' && field2[cy/2 + 1][cx/2] != counter) {
		flood(x,cy+2,cx);
	}
	if (cx > 0 && field[cy][cx-1] == '0' && field2[cy/2][cx/2-1] != counter) {
		flood(x,cy,cx-2);
	}
	
}

int main() {
    ofstream fout ("countcross.out");
    ifstream fin ("countcross.in");
    fin >> N >> K >> R;
    for (int i = 0; i < 2*N-1; i++) {
    	for (int j = 0; j < 2*N-1; j++) {
    		field[i][j] = '0';
    	}
    }
    int x1,y1,x2,y2;
    int sumx,sumy;
    for (int i = 0; i < R; i++) {
    	fin >> y1 >> x1 >> y2 >> x2;
    	sumx = (x1-1)*2 + (x2-1)*2;
    	sumy = (y1-1)*2 + (y2-1)*2;
    	field[sumy/2][sumx/2] = 'x';
    }
    for (int i = 0; i < K; i++) {
    	fin >> y1 >> x1;
    	field[(y1-1)*2][(x1-1)*2] = 'c';
    	cowc[i][0] = y1-1;
    	cowc[i][1] = x1-1;
    }
   	for (int i = 0; i < K; i++) {
    	if (field2[cowc[i][0]][cowc[i][1]] == 0) {
    		flood(i,2*cowc[i][0],2*cowc[i][1]);
    		counter++;
    	}	
	}
	for (int i = 1; i < counter; i++) {
		cout << cow[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < counter-1; i++) {
		for (int j = i+1; j < counter; j++) {
			ans += cow[i]*cow[j];
		}
	}
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		cout << field2[i][j] << " ";
    	}
    	cout << endl;
    }
    fout << ans << endl;
    /*for (int i = 0; i < 2*N-1; i++) {
    	for (int j = 0; j < 2*N-1; j++) {
    		cout << field[i][j] << " ";
    	}
    	cout << endl;
    }*/
    
    return 0;
}