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

int N;
int bales[21];
int dp[2][1000][1000];
int total = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> bales[i];
        total += bales[i];
    }
    int ans = LARGE;
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 667; j++) {
            for (int k = 0; k <= 667; k++) {
                if (dp[0][j][k]) {
                    dp[1][j][k] = 1;
                    dp[1][j+bales[i]][k] = 1;
                    dp[1][j][k+bales[i]] = 1;
                }
            }
        }
        for (int j = 0; j <= 667; j++) {
            for (int k = 0; k <= 667; k++) {
                dp[0][j][k] = dp[1][j][k];
            }
        }
    }
    for (int i = 0; i <= 667; i++) {
        for (int j = 0; j <= 667; j++) {
            if (dp[0][i][j]) {
                int ans2 = max(i,max(j,(total-i-j)));
                ans = min(ans,ans2);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}