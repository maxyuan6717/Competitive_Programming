/*
ID: yuanmax1
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int li[361] = {0};
void clear() {
	for (int z = 0; z < 361; z++) {
		li[z] = 0;
	}
}
int main() {
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
    int w[5][10];
    int s[5];
    int n[5];

    //int li[361] = {0};
    int a,b,x,y;
    for (int i = 0; i < 5; i++) {
    	fin >> a >> b;
    	s[i] = a;
    	n[i] = b;
    	for (int j = 0; j < b; j++) {
    		fin >> x >> y;
    		w[i][j*2] = x;
    		w[i][j*2+1] = y;
    		//cout << s[i] << " " << i << " " << w[i][j*2] << " " << w[i][j*2+1] << endl;
    	}
	}
    for (int i = 0; i <= 360; i++) {
    	clear();
    	for (int j = 0; j < 5; j++) {
    		for (int k = 0; k < n[j]; k++) {
    			//w[j][k*2] = (w[j][k*2] + s[j])%360;
    			//w[j][k*2+1] = (w[j][k*2+1] + s[j])%360;
    			x = (w[j][k*2] + i*s[j])%360;
    			y = w[j][k*2+1];
    			//cout << i << " " << j << " " << x << " " << x+y << endl;
    			for (int l = x; l <= x+y; l++) {
    				//cout << i << " " << j << " " << w[j][k*2] << " " << w[j][k*2+1]<< " " << l << endl;
    				li[l%360]++;
    				if (li[l%360] == 5) {
    					//cout << i << endl;
    					fout << i << endl;
    					return 0;
    				}
    			}
    		}
    	}
    	
    }
    fout << "none" << endl;
    
    return 0;
}