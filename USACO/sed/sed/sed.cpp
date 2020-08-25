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

#define LARGE 999999999

using namespace std;

int M,N;
int dp[1001][1001];

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int M = int(s1.size());
    int N = int(s2.size());
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
        }
    }
    cout << dp[M][N] << endl;
    return 0;
}