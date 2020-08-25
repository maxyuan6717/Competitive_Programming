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

int N,M;
int dp[101][101][11];

int rec(int l, int r, int rem) {
	if (dp[l][r][rem] != -1) return dp[l][r][rem];
	int sum = 100000;
	for (int i = l+1; i <= r; i++) {
		sum = min(sum, i + max(rec(i,r,rem),rec(l,i-1,rem-1)));
	}
	return dp[l][r][rem] = sum;
}

int main() {
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i <= 100; i++) {
		for (int j = i+1; j <= 100; j++) dp[i][j][1] = (j*(j+1) - i*(i+1)) / 2;
		for (int k = 0; k <= 10; k++) dp[i][i][k] = 0;
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		cout << rec(0,M,N) << endl;
	}
    return 0;
}
