#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    unsigned long M = s1.length(), N = s2.length();
    int dp[2][N+1];
    for (int i = 0; i < 2; i++) for (int j = 0; j <= N; j++) dp[i][j] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (s1[i-1] == s2[j-1]) dp[1][j] = dp[0][j-1] + 1;
            else dp[1][j] = max(dp[1][j-1],dp[0][j]);
        }
        for (int j = 0; j <= N; j++) dp[0][j] = dp[1][j];
    }
    cout << dp[0][N] << endl;
    return 0;
}