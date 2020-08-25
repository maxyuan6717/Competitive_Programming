/*
ID: yuanmax1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
int N, L, I;    

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
    fin >> N >> L >> I;
    int dp[32][32] = {0};
    for (int i = 0; i < 32; i++) {
    	dp[0][i] = 1;
    	dp[i][0] = 1;
    } 
    for (int i = 1; i <= N; i++) {
    	for (int j = 1; j <= L; j++) {
    		dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
    	}
    }
    string ans = "";
    int p = I;
    int x = N;
    int y = L;
    while (x > 0) {
    	//cout << x << " " << y << " " << p << " " << ans << endl;
    	if (p == 1 && x == 1 && y == 1) {
    		x-=1;
    		ans += "1";
    	}
    	else if (p <= dp[x-1][y]) {
    		x-=1;
    		ans += "0";
    	}
    	else {
    		p-=dp[x-1][y];
    		ans += "1";
    		x-=1;
    		y-=1;
    	}
    }
    
    fout << ans << endl;
    return 0;
}