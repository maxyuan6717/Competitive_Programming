/*
ID: yuanmax1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int N;
    fin >> N;
	int sum = (N*(N+1))/2;
    int half = sum/2;
    if (sum%2 == 1) {
    	fout << 0 << endl;
    	return 0;
    }
    unsigned long ans[N+1][sum+1];
    for (int i = 0 ; i < N+1; i++) {
    	for (int j = 0; j < sum+1; j++) {
    		ans[i][j] = 0;
    	}
    }
    ans[1][1] = 1;
    for (int i = 2; i <= N; i++) {`
    	for (int j = 1; j <= half; j++) {
    		if(j < i) ans[i][j] = ans[i-1][j];
            if(j == i) ans[i][j] = ans[i-1][j]+1;
            if(j > i) ans[i][j] = ans[i-1][j]+ans[i-1][j-i];\\
    	}
    }
    
    fout << ans[N][half]/2 << endl;
    

    return 0;
}