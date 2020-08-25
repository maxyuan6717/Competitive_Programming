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

int R,C,N;
int dr[8] = {2,-2,0,0,2,2,-2,-2};
int dc[8] = {0,0,2,-2,2,-2,2,-2};
int dp[4][4][1<<16];

bool inbounds (int r, int c, int cr, int cc) {
	return r >= 0 && r < cr && c >= 0 && c < cc;
}

int rec(int mr, int mc, int bm) {
	if (dp[mr-1][mc-1][bm] != -1) return dp[mr-1][mc-1][bm];
	int ret = 0;
	for (int r = 0; r < mr; r++) {
		for (int c = 0; c < mc; c++) {
			if (bm & (1<<(4*r + c))) {
				for (int i = 0; i < 8; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					int tr = r + dr[i]/2;
					int tc = c + dc[i]/2;
					if (!inbounds(nr,nc,mr,mc) || !inbounds(tr,tc,mr,mc) || (bm & (1<<(4*nr+nc))) || !(bm & (1<<(4*tr+tc)))) continue;
					int nbm = bm ^ (1 << (4*r + c)) ^ (1 << (4*tr + tc)) ^ (1 << (4*nr + nc));
					ret += rec(mr,mc,nbm);
				}
			}
		}
	}
	return dp[mr-1][mc-1][bm] = ret;
}

int main() {
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 16; k++) {
				dp[i][j][1<<k] = 1;
			}
		}
	}
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> R >> C >> N;
		int bm = 0;
		for (int i = 0; i < N; i++) {
			int r,c;
			cin >> r >> c;
			r--;c--;
			bm |= (1 << (4*r+c));
		}
		printf("Case %d: %d\n",t,rec(R,C,bm));
	}
    return 0;
}
