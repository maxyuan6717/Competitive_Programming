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

struct state {
	int r,c,t;
	state(int x, int y, int z) {
		r = x, c = y, t = z;
	}
};

int R,C,B,M;
bool blocked[100][100][100][100], vis[100][100][501];
pii monitor[501];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool inbounds (int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int bfs() {
	queue<state> q;
	vis[0][0][0] = 1;
	state init(0,0,0);
	q.push(init);
	while (!q.empty()) {
		int r = q.front().r, c = q.front().c, t = q.front().t;
		//cout << r << " " << c << " " << t << endl;
		q.pop();
		if (r == R-1 && c == C-1) return t;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			int nt = t + 1;
			if (!inbounds(nr,nc) || vis[nr][nc][nt] || monitor[nt] == mp(nr,nc) || blocked[r][c][nr][nc]) continue;
			vis[nr][nc][nt] = 1;
			state add(nr,nc,nt);
			q.push(add);
		}
		if (!vis[r][c][t+1]) {
			vis[r][c][t+1] = 1;
			state add(r,c,t+1);
			q.push(add);
		}
	}
	return -1;
}

int main() {
	while (cin >> C >> R) {
		cin >> B;
		memset(blocked,0,sizeof(blocked));
		memset(vis,0,sizeof(vis));
		for (int i = 0; i <= 500; i++) monitor[i] = mp(-1,-1);
		for (int i = 0; i < B; i++) {
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			blocked[y1][x1][y2][x2] = 1;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int t,x,y;
			cin >> t >> x >> y;
			monitor[t] = mp(y,x);
		}
		cout << bfs() << endl;
	}
    return 0;
}
