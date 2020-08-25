/*
ID: yuanmax1
PROG: game1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("game1.out");
    ifstream fin ("game1.in");
    int N;
    fin >> N;
    int num;
    int dp1[N][N];
    int dp2[N][N];
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		if (i == j) {
    			fin >> dp1[i][i];
    			dp2[i][i] = dp1[i][i];
    		}	
    		else {
    			dp1[i][j] = 0;
    			dp2[i][j] = 0;
    		}	
    		//cout << dp1[i][j] << " ";	
    	}
    	//cout << endl;
    }
    for (int i = 0; i < N; i++) {
    	for (int j = i+1; j < N; j++) {
    		dp1[i][j] = dp1[i][j-1] + dp1[j][j];
    		//cout << dp1[i][j] << " ";
    	}
    	//cout << endl;
    }
    for (int i = 1; i < N; i++) {
    	for (int j = 0; j + i < N; j++) {
    		dp2[j][i+j] = dp1[j][i+j] - min(dp2[j][i+j-1],dp2[j+1][i+j]);
    	}
    }
    fout << dp2[0][N-1] << " " << dp1[0][N-1]-dp2[0][N-1] << endl;
    return 0;
}