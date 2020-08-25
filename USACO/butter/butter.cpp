/*
ID: yuanmax1
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define LARGE 10000000
using namespace std;

int main() {
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
    int N,P,C;
    fin >> N >> P >> C;
    int cow[N];
    int p[801] = {0};
    int x,y,d;
    int dist[801][801];
    int t;
    for (int i = 0; i < N; i++) {
    	fin >> t;
    	p[t]++;
    }
    for (int i = 1; i <= P; i++) {
    	for (int j = 1; j <= P; j++) {
    		dist[i][j] = LARGE;	
    	}
    }
    for (int i = 0; i < C; i++) {
    	fin >> x >> y >> d;
    	dist[x][y] = d;
    	dist[y][x] = dist[x][y];	
    }
    for (int k = 1; k <= P; k++) {
    	for (int i = 1; i <= P; i++) {
    		for (int j = 1; j <= P; j++) {
    			if (dist[i][j] > dist[i][k] + dist[k][j]) {
     				dist[i][j] = dist[i][k] + dist[k][j];
     			}
    		}
    	}
    }
    int ans = LARGE;
    int num = 0;
    for (int i = 1; i <= P; i++) {
    	num = 0;
    	for (int j = 1; j <= P; j++) {
    		if (i!= j) {
    			num += p[j] * dist[i][j];
    		}
    	}
    	if (num < ans) ans = num;
    }
    fout << ans << endl;
    
    
    return 0;
}