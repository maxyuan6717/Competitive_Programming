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

struct point {
	int r,c,dir;
};

int N,M;
int arr[50][50];
int vis[50][50][50];
int dis[50][50][4];
int sr,sc,er,ec,sdir;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
string dire[4] = {"east","south","west","north"};

bool inbounds(int r, int c) {
	return (r > 0 && r < N && c > 0 && c < M);
}

bool check(int r, int c) {
	return !(arr[r][c] || arr[r-1][c] || arr[r][c-1] || arr[r-1][c-1]);
}

int bfs() {
	queue<point> q;
	point start = {sr,sc,sdir};
	dis[sr][sc][sdir] = 0;
	q.push(start);
	vis[sr][sc][sdir] = 1;
	while (!q.empty()) {
		point u = q.front();
		q.pop();
		//cout << u.r << " " << u.c << " " << dire[u.dir] << " " << dis[u.r][u.c][u.dir] << endl;
		if (u.r == er && u.c == ec) return dis[u.r][u.c][u.dir];
		for (int j = 1; j <= 3; j++) {
			int nr = u.r + dr[u.dir]*j;
			int nc = u.c + dc[u.dir]*j;
			if (!inbounds(nr,nc)) break;
			if (!check(nr,nc)) break;
			if (vis[nr][nc][u.dir]) continue;
			dis[nr][nc][u.dir] = dis[u.r][u.c][u.dir] + 1;
			vis[nr][nc][u.dir] = 1;
			point p = {nr,nc,u.dir};
			q.push(p);
		}
		for (int i = -1; i <= 1; i+=2) {
			int ndir = (4+i+u.dir)%4;
			if (vis[u.r][u.c][ndir]) continue;
			vis[u.r][u.c][ndir] = 1;
			dis[u.r][u.c][ndir] = dis[u.r][u.c][u.dir] + 1;
			point p = {u.r,u.c,ndir};
			q.push(p);
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	while (N || M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				for (int k = 0; k < 4; k++) {
					dis[i][j][k] = LARGE;
					vis[i][j][k] = 0;
				}
			}
		}
		cin >> sr >> sc >> er >> ec;
		string s;
		cin >> s;
		if (s == "east") sdir = 0;
		else if (s == "south") sdir = 1;
		else if (s == "west") sdir = 2;
		else sdir = 3;
		cout << bfs() << endl;
		cin >> N >> M;
	}
    return 0;
}
