/*
 ID: yuanmax1
 PROG: bigbrn
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>

#define LARGE 9999999

using namespace std;

int N,T;
char arr[1001][1001];
int dp[1001][1001];

int main() {
    ofstream fout ("bigbrn.out");
    ifstream fin ("bigbrn.in");
    fin >> N >> T;
    int ans=1;
    if (T == N*N) {
        cout << 0 << endl;
        fout << 0 << endl;
        return 0;
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            arr[i][j] = '.';
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < T; i++) {
        int y,x;
        fin >> y >> x;
        arr[y][x] = '#';
    }
    for (int i = 1; i <= N; i++) {
        if (arr[1][i] != '#') dp[1][i] = 1;
        if (arr[1][i] != '#') dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            if (arr[i][j] != '#') {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                if (dp[i][j] > ans) ans = dp[i][j];
            }
        }
    }
    cout << ans << endl;
    fout << ans << endl;
    
    return 0;
}