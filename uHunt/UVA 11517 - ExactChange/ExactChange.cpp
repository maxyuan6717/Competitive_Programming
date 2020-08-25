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
#include <bitset>

#define LARGE 1000000

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
    	int P;
    	cin >> P;
    	int N;
    	cin >> N;
    	int coins[N+1];
    	int total = 0;
    	int minCoin = 1000000;
    	for (int i = 1; i <= N; i++) {
    		cin >> coins[i];
    		total = max(total,coins[i]);
    		minCoin = min(minCoin,coins[i]);
    	}
    	total += P;
    	int dp[N+1][total+1];
    	for (int i = 0; i <= N; i++) {
    		for (int j = 0; j <= total; j++) {
    			if (j) dp[i][j] = LARGE;
    			else dp[i][j] = 0;
    		}
    	}
    	for (int i = 1; i <= N; i++) {
    		int val = coins[i];
    		for (int j = minCoin; j <= total; j++) {
    			if (val > j) {
    				dp[i][j] = dp[i-1][j];
    				continue;
    			}
    			if (dp[i-1][j-val] == LARGE) {
    				dp[i][j] = dp[i-1][j];
    				continue;
    			}
    			if (dp[i][j] == LARGE) dp[i][j] = dp[i-1][j-val] + 1;
    			else dp[i][j] = min(dp[i][j],dp[i-1][j-val]+1);
    			dp[i][j] = min(dp[i-1][j],dp[i][j]);
    			if (j >= P) total = j;
    			//cout << i << " " << j << " " << dp[i][j] << endl;
    		}
    	}
    	int ans = total;
    	int ans2 = N;
    	ans = total;
    	ans2 = dp[N][total];
    	cout << ans << " " << ans2 << endl;
    }
    return 0;
}
