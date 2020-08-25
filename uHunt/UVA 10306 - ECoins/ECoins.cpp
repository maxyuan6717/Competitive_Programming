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

struct coin {
	int x,y;
};

int main() {
	int N;
	cin >> N;
	for (int n = 0; n < N; n++) {
		int M,S;
		cin >> M >> S;
		vector<coin> coins;
		for (int i = 0; i < M; i++) {
			coin c;
			cin >> c.x >> c.y;
			coins.push_back(c);
		}
		int dp[S+1][S+1];
		for (int i = 0; i <= S; i++) {
			for (int j = 0; j <= S; j++) {
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		int ans = 1000000;
		for (int m = 0; m < M; m++) {
			int x = coins[m].x;
			int y = coins[m].y;
			for (int i = y; i <= S; i++) {
				for (int j = x; j <= S; j++) {
					if (dp[i-y][j-x] == -1) continue;
					if (dp[i][j] == -1) dp[i][j] = dp[i-y][j-x] + 1;
					else dp[i][j] = min(dp[i][j],dp[i-y][j-x] + 1);
					if (S*S == i*i + j*j) ans = min(ans,dp[i][j]);
				}
			}
		}
		if (ans == 1000000) cout << "not possible" << endl;
		else cout << ans << endl;
	}
    
    return 0;
}
