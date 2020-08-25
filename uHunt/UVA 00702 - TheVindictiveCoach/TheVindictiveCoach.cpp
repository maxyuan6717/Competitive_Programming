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

int N,C;
long long dp[22][22][2];

long long rec(int a, int b, bool m) {
	if (!a && !b) return 1;
	if ((a <= 0 && !m) || (b <= 0 && m)) return 0;
	if (dp[a][b][m] != -1) return dp[a][b][m];
	long long ret = 0;
	if (!m) {
		for (int i = 1; i <= a; i++) ret += rec(a-i, b+i-1,1);
	}
	else {
		for (int i = 1; i <= b; i++) ret += rec(a+i-1,b-i,0);
	}
	return dp[a][b][m] = ret;
}

int main() {
	while (cin >> N >> C) {
		if (N <= 2) {
			cout << 1 << endl;
			continue;
		}
		memset(dp,-1,sizeof(dp));
		if (C == 1) {
			cout << rec(1,N-3,0) << endl;
		}
		else {
			cout << max((long long) 1,rec(C-1,N-C,0)) << endl;
		}
	}
    return 0;
}
