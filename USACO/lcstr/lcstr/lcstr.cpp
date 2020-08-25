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

int M,N,ans = 0;
int dp[1001][1001];

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    M = int(s1.size());
    N = int(s2.size());
    for (int i = 0; i <= M; i++) for(int j = 0; j <= M; j++) dp[i][j] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}