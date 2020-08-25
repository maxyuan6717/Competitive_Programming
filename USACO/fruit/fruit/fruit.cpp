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

int main() {
    int T,A,B;
    cin >> T >> A >> B;
    bool dp[2][T+1];
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int a = 0; a < 2; a++) {
        for (int i = 1; i <= T; i++) {
            if (i - A >= 0 && dp[a][i-A]) {
                dp[a][i] = 1;
                if (a == 0) {
                    dp[1][i/2] = 1;
                }
            }
            if (i - B >= 0 && dp[a][i-B]) {
                dp[a][i] = 1;
                if (a == 0) {
                    dp[1][i/2] = 1;
                }
            }
            if (a == 1 && dp[a][i] && i > ans) ans = i;
        }
        //for (int i = 0; i <= T; i++) cout << dp[a][i] << " ";
        //cout << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}