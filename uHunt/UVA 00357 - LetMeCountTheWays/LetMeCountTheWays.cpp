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

#define LARGE (1<<31)-1

using namespace std;

int main() {
    int N;
    while (cin >> N) {
    	int coins[5] = {1,5,10,25,50};
    	long long dp[30001];
    	for (int i = 0; i <= N; i++) {
    		dp[i] = -1;
    	}
    	dp[0] = 1;
    	for (int i = 0; i < 5; i++) {
    		int val = coins[i];
    		for (int j = val; j <= N; j++) {
    			if (dp[j-val] == -1) continue;
    			if (dp[j] == -1) dp[j] = 0;
    			dp[j] += dp[j-val];
    		}
    	}
    	long long ans = dp[N];
    	if (ans == 1) cout << "There is only 1 way to produce " << N << " cents change." << endl;
    	else cout << "There are " << ans << " ways to produce " << N << " cents change." << endl;
    }
    return 0;
}
