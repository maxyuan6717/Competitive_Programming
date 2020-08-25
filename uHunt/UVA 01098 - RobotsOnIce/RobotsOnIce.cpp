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

struct chkpnt {
	int r,c,d;
};

int R,C,P,ans;
chkpnt cp[4];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
bool vis[8][8], reach[8][8];

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int dis(int r1, int c1, int r2, int c2) {
	return (abs(r1-r2) + abs(c1-c2));
}

void dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (reach[nr][nc]) continue;
		reach[nr][nc] = 1;
		dfs(nr,nc);
	}
}

void rec(int r, int c, int d, int ch) {
	d++;
	//cout << r << " " << c << " " << d << " " << ch << " " << ans << endl;
	if (r == cp[ch].r && c == cp[ch].c && d == cp[ch].d) ch++;
	if (ch == 4) {
		ans++;
		return;
	}
	memset(reach,0,sizeof(reach));
	reach[0][1] = 1;
	dfs(0,1);
	bool works = 1;
	for (int j = 0; j < R; j++) {
		for (int k = 0; k < C; k++) {
			if (!reach[j][k] && !vis[j][k]) {
				works = 0;
				break;
			}
		}
		if (!works) break;
	}
	if (!works) return;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (vis[nr][nc]) continue;
		for (int i = ch + 1; i < 4; i++) {
			if (nr == cp[i].r && nc == cp[i].c) continue;
		}
		if (dis(nr,nc,cp[ch].r,cp[ch].c) > cp[ch].d-(d+1)) continue;
		if (d+1 == cp[ch].d && (nr!= cp[ch].r || nc != cp[ch].c)) continue;
		if (nr == cp[ch].r && nc == cp[ch].c && d+1 != cp[ch].d) continue;
		vis[nr][nc] = 1;
		rec(nr,nc,d,ch);
		vis[nr][nc] = 0;
	}
}

int main() {
	int caseNum = 1;
	while (cin >> R >> C, R || C) {
		P = R*C;
		ans = 0;
		for (int i = 0; i < 3; i++) {
			cin >> cp[i].r >> cp[i].c;
		}
		cp[3].r = 0, cp[3].c = 1, cp[3].d = P;
		cp[0].d = P/4;
		cp[1].d = P/2;
		cp[2].d = (3*P)/4;
		memset(vis,0,sizeof(0));
		vis[0][0] = 1;
		rec(0,0,0,0);
		cout << "Case " << caseNum++ << ": " << ans << endl;
	}
    return 0;
}
