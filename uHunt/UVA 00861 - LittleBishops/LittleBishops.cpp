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

int ans[9][65];
vector<vector<int> > used(9,vector<int>(9));
map<vector<vector<int> >, bool> vis;
int N,K;

bool check(int r, int c) {
	for (int i = 1; i <= 8; i++) {
		int nr = r + (i-c);
		if (nr >= 1 && nr <= 8) {
			if (i != c && used[nr][i]) return 0;
		}
		nr = r + (c-i);
		if (nr >= 1 && nr <= 8) {
			if (i != c && used[nr][i]) return 0;
		}
	}
	return 1;
}

void rec(int r, int c, int cnt, int n) {
	//cout << r << " " << c << " " << cnt << endl;
	used[r][c] = 1;
	ans[n][cnt]++;
	/*if (cnt) {
		int n = max(r,c);
		for (int i = n; i <= 8; i++) ans[i][cnt]++;
	}*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (used[i][j]) continue;
			if (!check(i,j)) continue;
			used[i][j] = 1;
			if (vis[used]) {
				used[i][j] = 0;
				continue;
			}
			vis[used] = 1;
			rec(i,j,cnt+1,n);
			used[i][j] = 0;
		}
	}
}

int main() {
	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j <= 64; j++) {
			ans[i][j] = 0;
			if (!j) ans[i][j] = 1;
			if (j <= 8) used[i][j] = 0;
		}
	}
	vis.clear();
	rec(0,0,0,2);
	while (cin >> N >> K, N || K) {
		cout << ans[N][K] << endl;
	}
    return 0;
}
