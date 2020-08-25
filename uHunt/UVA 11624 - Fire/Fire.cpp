#include <iostream>
#include <fstream>
#include <string>
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

struct point {
	int r,c,time;
};

int R,C;
int arr[1000][1000];
int vis[1000][1000];
int dist[1000][1000];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
vector<point> fires;
int sr,sc;

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

bool escaped(point p) {
	int r = p.r, c = p.c;
	return (r == 0 || r == R-1 || c == 0 || c == C-1);
}

int bfs() {
	queue<point> q;
	point start = {sr,sc,0};
	vis[sr][sc] = 1;
	q.push(start);
	while (!q.empty()) {
		point u = q.front();
		q.pop();
		//cout << u.r << " " << u.c << endl;
		if (escaped(u)) return u.time + 1;
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (!arr[nr][nc]) continue;
			if (vis[nr][nc]) continue;
			point v = {nr,nc,u.time+1};
			if (u.time + 1 >= dist[nr][nc]) continue;
			vis[nr][nc] = 1;
			q.push(v);
		}
	}
	return -1;
}

void bfs2(int r, int c) {
	dist[r][c] = 0;
	queue<point> q;
	point start = {r,c,0};
	q.push(start);
	while (!q.empty()) {
		point u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (!arr[nr][nc]) continue;
			point v = {nr,nc,u.time+1};
			if (u.time+1 < dist[nr][nc]) {
				dist[nr][nc] = u.time+1;
				q.push(v);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> R >> C;
		fires.clear();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				vis[i][j] = 0;
				dist[i][j] = LARGE;
				char c;
				cin >> c;
				if (c == '#') arr[i][j] = 0;
				else if (c == '.') arr[i][j] = 1;
				else if (c == 'J') {
					arr[i][j] = 1;
					sr = i, sc = j;
				}
				else {
					arr[i][j] = 0;
					point f = {i,j,0};
					fires.push_back(f);
				}
			}
		}
		for (int i = 0; i < fires.size(); i++) {
			point f = fires[i];
			bfs2(f.r,f.c);
		}
		int ans = bfs();
		if (ans == -1) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;
	}
    return 0;
}
