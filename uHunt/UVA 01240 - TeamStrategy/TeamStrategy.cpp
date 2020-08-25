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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,arr[4][12];
int dp[1<<12][4][281];
int ans = 0;

int rec(int bm, int p, int cur) {
	if (dp[bm][p][cur] != -1) return dp[bm][p][cur];
	int ret = 0;
	for (int i = 1; i < 4; i++) {
		if (i == p) continue;
		for (int j = 0; j < N; j++) {
			if (bm & (1<<j)) continue;
			if (arr[i][j] + cur > 280) continue;
			ret = max(ret, 1 + rec(bm | (1<<j), i, cur + arr[i][j]));
		}
	}
	return dp[bm][p][cur] = ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 1; i <= 3; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		memset(dp,-1,sizeof(dp));
		cout << rec(0,0,0) << endl;
	}
    return 0;
}
