/*
ID: yuanmax1
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int dp[10001] = {0};
int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    int M,N;
    fin >> M >> N;
    for (int i = 0; i < N; i++) {
    	int a, b;
    	fin >> a >> b;
    	for (int j = b; j <= M; j+=b) {
    		dp[j] = max(dp[j], dp[j-b]+a);
    	}
    	for (int j = 1; j <= M; j++) {
    		if (j+b <= 10001 && dp[j] !=  -1) {
    			dp[j+b] = max(dp[j+b],dp[j] + a);
    		}
    	}
    }
    fout << dp[M] << endl;
    
    return 0;
}