/*
ID: yuanmax1
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
#define LARGE 9000000

int main() {
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");
    int K, N;
    fin >> K >> N;
    int mon[K*10000+1];
    int ans;
    int val[N];
    for (int i = 0; i < N; i++) {
    	fin >> val[i];
    	//cout << val[i] << endl;
    }
    for (int i = 1; i <= K * 10000; i++) {
    	mon[i] = LARGE;
    	for (int j = 0; j < N; j++) {
    		if (val[j] <= i) {
    			if (mon[i] > mon[i-val[j]]+1) {
    				mon[i] = mon[i-val[j]] +1;
    			}
    		}
    		
    		//cout << mon[i] << endl;
    	}
    	if (mon[i] > K) {
    			ans = i-1;
    			break;
    		}	
    }
    fout << ans << endl;    
  
    return 0;
}