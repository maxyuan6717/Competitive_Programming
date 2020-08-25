/*
ID: yuanmax1
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    int V,N;
    int coin[25];
    long long ans[10001] = {0};
    fin >> V >> N;
    for (int i = 0; i < V; i++) {
    	fin >> coin[i];
    }
    sort(coin,coin + V);
    ans[0] = 1;
    for (int i = 0; i < V; i++) {
    	for (int j = coin[i]; j <= N; j++) {
    		//cout << coin[i] << " " << j << " " << ans[j] << " " << ans[j-coin[i]] << endl;
    		ans[j] += ans[j-coin[i]];
    	}
    }
    fout << ans[N] << endl;
    
    return 0;
}