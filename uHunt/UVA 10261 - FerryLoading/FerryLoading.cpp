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

int len,cars[2005],pfsum[2005],N,dp[205][10005];
bool ans[205],side[205][10005];
string dir[2] = {"port","starboard"};

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t) cout << endl;
		cin >> len;
		len *= 100;
		N = 1;
		pfsum[0] = 0;
		memset(dp,0,sizeof(dp));
		while (cin >> cars[N], cars[N]) {
			pfsum[N] = pfsum[N-1] + cars[N];
			N++;
		}
		N--;
		dp[0][0] = 1;
		int maxCar = 0, maxLen = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= len; j++) {
				int rlen = pfsum[i]-j;
				if (j >= cars[i] && dp[i-1][j-cars[i]]) {
					dp[i][j] = 1;
					side[i][j] = 0;
				}
				if (rlen <= len && dp[i-1][j]) {
					dp[i][j] = 1;
					side[i][j] = 1;
				}
				if (dp[i][j]) {
					maxCar = i;
					maxLen = j;
				}
			}
			if (maxCar != i) break;
		}
		int curCar = maxCar, curLen = maxLen;
		while (curCar) {
			ans[curCar] = side[curCar][curLen];
			if (side[curCar][curLen] == 0) curLen -= cars[curCar];
			curCar--;
		}
		cout << maxCar << endl;
		for (int i = 1; i <= maxCar; i++) {
			cout << dir[ans[i]] << endl;
		}
	}
    return 0;
}
