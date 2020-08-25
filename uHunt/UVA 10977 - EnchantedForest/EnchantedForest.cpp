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
int M,N;
int arr[201][201];
int vis[201][201];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
vector<point> jigglypuffs;

int dist(point a, point b) {
	return ((a.r-b.r)*(a.r-b.r) + (a.c-b.c)*(a.c-b.c));
}

bool inbounds(int r, int c) {
	return (r > 0 && r <= R && c > 0 && c <= C);
}

bool safe(point a) {
	for (int i = 0; i < N; i++) {
		point b = jigglypuffs[i];
		if (dist(a,b) <= b.time*b.time) return 0;
	}
	return 1;
}

int bfs() {
	vis[1][1] = 1;
	queue<point> q;
	point start = {1,1,0};
	q.push(start);
	while (!q.empty()) {
		point u = q.front();
		q.pop();
		if (u.r == R && u.c == C) return u.time;
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (vis[nr][nc]) continue;
			if (arr[nr][nc]) continue;
			point v = {nr,nc,u.time+1};
			if (!safe(v)) continue;
			vis[nr][nc] = 1;
			q.push(v);
		}
	}
	return -1;
}

int main() {
	cin >> R >> C;
    while (R || C) {
    	for (int i = 1; i <= R; i++) {
    		for (int j = 1; j <= C; j++) {
    			arr[i][j] = 0;
    			vis[i][j] = 0;
    		}
    	}
    	cin >> M;
    	for (int i = 0; i < M; i++) {
    		int r,c;
    		cin >> r >> c;
    		arr[r][c] = 1;
    	}
    	cin >> N;
    	jigglypuffs.clear();
    	for (int i = 0; i < N; i++) {
    		point p;
    		cin >> p.r >> p.c >> p.time;
    		jigglypuffs.push_back(p);
    	}
    	int ans = bfs();
    	if (ans == -1) cout << "Impossible." << endl;
    	else cout << ans << endl;
    	cin >> R >> C;
    }
    return 0;
}
