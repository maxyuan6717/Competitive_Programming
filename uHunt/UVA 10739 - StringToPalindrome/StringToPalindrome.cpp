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

string s;
int dp[1000][1000];
int N;

int cnt(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 0;
	if (l + 1 == r) {
		if (s[l] == s[r]) return dp[l][r] = 0;
		else return dp[l][r] = 1;
	}
	if (s[l] == s[r]) return dp[l][r] = cnt(l+1,r-1);
	return dp[l][r] = 1 + min(cnt(l+1,r-1),min(cnt(l,r-1),cnt(l+1,r)));
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		N = s.size();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dp[i][j] = -1;
		cout << "Case " << t << ": " << cnt(0,N-1) << endl;
	}
    return 0;
}
