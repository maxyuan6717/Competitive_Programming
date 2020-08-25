/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("helpcross.out");
    ifstream fin ("helpcross.in");
    int C,N;
    int c[1000];
    int overlap[1000] = {0};
    int num;
    int ans = 0;
    fin >> C >> N;
    for (int i = 0; i < C; i++) {
    	fin >> c[i];
    }
    sort(c,c+C+1);
    int s,e;
    for (int i = 0; i < N; i++) {
    	fin >> s >> e;
    	for (int j = 0; j < C; j++) {
    		if (c[j] >= s && c[j] <= e && c[j] != 0) {
    			ans++;
    			c[j] = 0;	
    			break;
    		}
    	}
    }
    cout << ans << endl;  
    return 0;
}