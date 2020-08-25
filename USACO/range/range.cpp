/*
ID: yuanmax1
PROG: range
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("range.out");
    ifstream fin ("range.in");
    int N;
    fin >> N;
    int map[N][N];
    int val[N][N];
    int ans[N];
    int row;
    string str;
    for (int i = 0; i < N; i++) {
    	fin >> str;
    	ans[i]= 0;
    	for (int j = 0; j < N; j++) {
    		map[i][j] = str[j]-'0';
    		//val[i][j] = 0;
    	}
    }
    for (int i = 0; i < N; i++) {
    	row = 0;
    	for (int j = 0; j < N; j++) {
    		if (map[i][j] == 0) row =0;
    		else row++;
    		val[i][j] = row;
    	}
    }
    for (int i = 0; i < N-1; i++) {
    	for (int j = 0; j < N; j++) {
    		if (val[i][j] < 2) continue;
    		else {
    			int num = i+val[i][j];
    			for (int k = i+1; k < num; k++) {
    				if (val[k][j] >= k-i+1) {
    					ans[k-i]++;
    					//if (k-i+1 > 3) cout << i << " " << j << " " << k-i+1 << endl;
    					if (val[k][j] < num-i) num = i+val[k][j];
    				}
    				else {
    					break;
    				}
    			}
    		}
    	}
    }
    for (int i = 0; i < N; i++) {
    	if (ans[i] != 0) fout << i+1 << " " << ans[i] << endl;
    }
    /*for (int i = 0; i < N; i++) {
    	cout << i << " ";
    	for (int j = 0; j < N; j++) {
    		cout << val[i][j];
    	}
    	cout << endl;
    }*/
    return 0;
}