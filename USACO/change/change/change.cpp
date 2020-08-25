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

int C,N;
int coins[10];
int dp[1001];
bool can[1001];

int main() {
    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    for (int i = 0; i <= C; i++) {
        dp[i] = LARGE;
    }
    dp[0] = 0;
    can[0] = 1;
    for (int i = 0; i < N; i++) {
        int val = coins[i];
        for (int j = val; j <= C; j++) {
            if (can[j-val] && dp[j-val] + 1 < dp[j]) {
                can[j] = 1;
                dp[j] = dp[j-val] + 1;
            }
        }
    }
    cout << dp[C] << endl;
    
    return 0;
}