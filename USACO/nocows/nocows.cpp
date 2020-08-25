/*
ID: yuanmax1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    int N,K;
    fin >> N >> K;
    if (N%2 == 0) {
    	fout << 0 << endl;
    	return 0;
    }
    int k2;
    int arr[201][101] = {0};
    for (int i = 1; i <= K; i++) {
    	arr[1][i] = 1;
    }
    for (int i = 3; i <= N; i+=2) {
    	for (int j = 1; j <= K; j++) {
    		//arr[i][j] = 0;
    		for (int k = 1; k <= i-2; k+=2) {
    			k2 = i-k-1;
    			//cout << k2 << endl;
    			//arr[i][j] += arr[i-2][k] * arr[i-1][k2];
    			//arr[i][j] += arr[i-1][k] * arr[i-2][k2];
    			arr[i][j] += arr[k][j-1] * arr[k2][j-1];
    			arr[i][j] %= 9901;
    		}
    	}
    }
    for (int i = 1; i <= N; i++) {
    	for (int j = 1; j <= K; j++) {
    		//cout << arr[i][j] << " ";
    	}	
    	//cout << endl;
    }
   // cout << arr[N][K] << endl;
   	fout << (arr[N][K]-arr[N][K-1]+9901)%9901 << endl;
    return 0;
}