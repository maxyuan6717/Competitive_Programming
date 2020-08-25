/*
ID: yuanmax1
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    int N;
    fin >> N;
    int con[101][101] = {0};
    int per[101][101] = {0};
    int com1, com2, perc;
    for (int i = 0; i < N; i++) {
    	fin >> com1 >> com2 >> perc;
    	per[com1][com2] = perc;
    }
    for (int i = 0; i < 101; i++) {
    	for (int j = 0; j < 101; j++) {
    		if (i != j && per[i][j] > 50 && con[i][j] != 1) {
    			con[i][j] = 1;
    			for (int a = 0; a < 101; a++) {
    				per[i][a] += per[j][a];
    				if (con[j][a] == 1) {
    					con[i][a] = 1;
    				}
    			}
    			j = 0;
    		}
    	}
    }
    for (int i = 0; i < 101; i++) {
    	for (int j = 0; j < 101; j++) {
    		if (i != j && con[i][j] != 0) {
    			fout << i << " " << j << endl;
    		} 
    	}
    }
    
    return 0;
}