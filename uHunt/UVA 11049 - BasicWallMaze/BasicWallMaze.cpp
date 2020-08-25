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
	int r,c;
	string seq;
};

struct wall {
	point u,v;
};

int sr,sc;
int er,ec;
vector<wall> walls;
int vis[7][7];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
string add[4] = {"N","E","S","W"};

bool inbounds(int r, int c) {
	return (r > 0 && r <= 6 && c > 0 && c <= 6);
}

bool intersectWall(point u, point v) {
	for (int i = 0; i < 3; i++) {
		wall w = walls[i];
		point w1 = w.u;
		point w2 = w.v;
		bool h1 = (u.r == v.r);
		bool h2 = (w1.r == w2.r);
		if (h1 == h2) continue;
		if (h1) {
			int l = min(u.c,v.c);
			int r = max(u.c,v.c);
			if (u.r > w1.r && u.r <= w2.r && l <= w1.c && r > w1.c) return 1;
		}
		else {
			int t = min(u.r,v.r);
			int b = max(u.r,v.r);
			if (u.c > w1.c && u.c <= w2.c && t <= w1.r && b > w1.r) return 1;
		}
	}
	return 0;
}

string bfs() {
	vis[sr][sc] = 1;
	queue<point> q;
	point start = {sr,sc,""};
	q.push(start);
	while (!q.empty()) {
		point u = q.front();
		q.pop();
		//cout << u.r << " " << u.c << endl;
		if (u.r == er && u.c == ec) return u.seq;
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (vis[nr][nc]) continue;
			point v = {nr,nc,u.seq+add[i]};
			if (intersectWall(u,v)) continue;
			q.push(v);
			vis[nr][nc] = 1;
		}
	}
	return "rip";
}

int main() {
	cin >> sc >> sr;
	while (sc || sr) {
		cin >> ec >> er;
		walls.clear();
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				vis[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; i++) {
			int r1,c1,r2,c2;
			cin >> c1 >> r1 >> c2 >> r2;
			point u = {r1,c1,""};
			point v = {r2,c2,""};
			wall w = {u,v};
			walls.push_back(w);
		}
	    cout << bfs() << endl;
		cin >> sc >> sr;
	}
    return 0;
}
