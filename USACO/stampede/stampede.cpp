/*
ID: yuanmax1
PROG: stampede
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int main() {
    ofstream fout ("stampede.out");
    ifstream fin ("stampede.in");
    int N;
    fin >> N;
    int map[N][1001];
    int cow[N][2];
    int s[N];
    int c[N];
    int sp;
    int m =0;
    int ans = 0;
    int mi = 1000001;
    int counter = 0;
    int num;
    int x, y;
    for (int i = 0 ; i < N; i++) {
    	for (int j = 0; j < 1001; j++) {
    		map[i][j] = 0;
    	}
    }
    for (int i = 0; i < N; i++) {
    	c[i] = 0;
    	fin >> x >> y >> sp;
    	//cout << 0-x << endl;
    	s[i] = sp;
    	//cout << i << " " << 0-x << endl;
    	map[i][0-x-1] = 1;
    	cow[i][0] = 0-x-1;
    	cow[i][1] = y; 
    	num = sp * ((0-x));
    	if (num>m) m = num;
    }
    
    //cout << m << endl;
    for (int i = 1; i <= m; i++) {
    	for (int j = 0; j < N; j++) {
    		if (i % s[j] == 0 && cow[j][0] != 0) {
    			map[j][cow[j][0]] = 0;
    			map[j][cow[j][0]-1] = 1;
    			cow[j][0] -= 1;
    		}
    		else if (i % s[j] == 0 && cow[j][0] == 0) {
    			map[j][cow[j][0]] = 0;
    		}
    	}
    	for (int j = 0; j < N; j++) {
    		if (map[j][0] == 1 && cow[j][1] < mi) {
    			mi = cow[j][1];
    			counter++;
    			
    		}
    	}
		if (counter != 0){
			if (c[mi] == 0) {
				ans++;
				c[mi] = 1;
			}	
		}
    	//cout << ans << endl;
    	counter =0;
    	mi = 1000001;
    }
    fout << ans << endl;
    
    return 0;
}