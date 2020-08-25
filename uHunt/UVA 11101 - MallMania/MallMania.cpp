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

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

struct point {
	int r,c,dist;
};

int N,M;
vector<point> mallA;
int mallB[2001][2001];
int vis[2001][2001];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool inbounds(int r, int c) {
	return (r >= 0 && r <= 2000 && c >= 0 && c <=2000);
}

int bfs() {
	queue<point> q;
	for (int i = 0; i < N; i++) {
		point start = mallA[i];
		start.dist = 0;
		q.push(start);
		vis[start.r][start.c] = 1;
	}
	while (!q.empty()) {
		point u = q.front();
		q.pop();
		if (mallB[u.r][u.c]) return u.dist;
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (vis[nr][nc]) continue;
			vis[nr][nc] = 1;
			point v = {nr,nc,u.dist+1};
			q.push(v);
		}
	}
	return 10000000;
}

int main() {
	cin >> N;
	while (N) {
		for (int i = 0; i <= 2000; i++) {
			for (int j = 0; j <= 2000; j++) {
				mallB[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		mallA.clear();
		for (int i = 0; i < N; i++) {
			point p;
			cin >> p.r >> p.c;
			mallA.push_back(p);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int r,c;
			cin >> r >> c;
			mallB[r][c] = 1;
		}
		cout << bfs() << endl;
		cin >> N;
	}
    return 0;
}
