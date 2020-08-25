#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
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
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int main() {
	int M,N,T,cost[2];
	int dp[10001];
	while (cin >> M >> N >> T) {
		cost[0] = M, cost[1] = N;
		for (int i = 0; i <= T; i++) dp[i] = -1;
		dp[0] = 0;
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			int c = cost[i];
			for (int i = 0; i <= T-c; i++) {
				if (dp[i] == -1) continue;
				dp[i+c] = max(dp[i+c], dp[i] + 1);
				ans = max(ans,i+c);
			}
		}
		cout << dp[ans];
		if (ans != T) {
			cout << " " << T-ans;
		}
		cout << endl;
	}
    return 0;
}
