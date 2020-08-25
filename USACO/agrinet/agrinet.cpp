/*
ID: yuanmax1
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int dist[101][101];
int n = 1;
int vis[101];
int ans = 0;
int min1;
#define LARGE 999999

int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");

    fin >> N;
    for (int i = 0; i < N; i++) {
    	vis[i] = 0;
    	for (int j = 0; j < N; j++) {
    		fin >> dist[i][j];
    		if (dist[i][j] == 0) {
    			dist[i][j] = LARGE;
    		}
    		//cout << dist[i][j] << " ";
    	}
    	//cout << endl;
    }
    vis[0] = 1;
    int farm;
    while (n != N) {
    	min1 = LARGE;
    	for (int i = 0; i < N; i++) {
    		if (vis[i]) {
    			for (int j = 0; j < N; j++) {
    				if (!vis[j]) {
    					if (dist[i][j] < min1) {
    						min1 = dist[i][j];
    						farm = j;
    					}
    				}	
    			}
    		}
    	}
    	//cout << min1 << endl;
    	vis[farm] = 1;
    	ans += min1;
    	n++;
    }
	fout << ans << endl;

    /*for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		cout << dist[i][j] << " ";
    	}
    	cout << endl;
    }*/
    
    return 0;
}