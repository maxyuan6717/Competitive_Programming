/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int n[100001][3] = {0};
int ma(int x, int y) {
	int num = 0;
	int a;
	//int ans;
	for (int i = 0; i < 3; i++) {
		a = n[y][i]-n[x][i];
		if (a > num) {
			num = a;
			//ans = i;
		}	
	}
	return num;
}
int main() {
    ofstream fout ("hps.out");
    ifstream fin ("hps.in");
    fin >> N;
    char a;
    for (int i = 0; i < N; i++) {
    	fin >> a;
    	if (a == 'H') {
    		//c[i] = 0;
    		n[i+1][0] = n[i][0]+1;
    		n[i+1][1] = n[i][1];
    		n[i+1][2] = n[i][2];
    	}	
    	else if (a == 'P') {
    		//c[i] = 1;
    		n[i+1][1] = n[i][1]+1;
    		n[i+1][0] = n[i][0];
    		n[i+1][2] = n[i][2];
    		
    	}	
    	else if (a == 'S') {
    		//c[i] = 2;
    		n[i+1][2] = n[i][2]+1;
    		n[i+1][0] = n[i][0];
    		n[i+1][1] = n[i][1];
    	}	
    	
    	
    }
    /*for (int i = 0; i <= N; i++) {
    	for (int j = 0; j < 3; j++) {
    		cout << n[i][j] << " ";
    	}
    	cout << endl;
	}*/
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
    	sum += ma(0,i) + ma(i,N);
    	if (sum > ans) ans = sum;
    	sum = 0;
    }
    //cout << ma(0,3) << endl;
    fout << ans << endl;
    return 0;
}