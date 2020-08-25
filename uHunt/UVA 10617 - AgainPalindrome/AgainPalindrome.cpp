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
long long dp[60][60];
int N;

long long cnt(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 1;
	if (l + 1 == r) {
		if (s[l] == s[r]) return dp[l][r] = 3;
		else return dp[l][r] = 2;
	}
	long long ret = 0;
	ret += cnt(l+1,r) + cnt(l,r-1) - cnt(l+1,r-1);
	if (s[l] == s[r]) ret += cnt(l+1,r-1) + 1;
	return dp[l][r] = ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> s;
		N = s.size();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = -1;
			}
		}
		cout << cnt(0,N-1) << endl;
	}
    return 0;
}
