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

struct point {
	int r,c,d;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int R,C,N;
int arr[20][20];
int num[20][20];
int vis[20][20];
int dis[16][16];
int dp[16][1<<16];
int dr[8] = {1,-1,0,0,1,1,-1,-1};
int dc[8] = {0,0,1,-1,1,-1,1,-1};
vector<point> nuts;

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

void bfs(int start) {
	queue<point> q;
	point p = {nuts[start].r,nuts[start].c,0};
	q.push(p);
	dis[start][start] = 0;
	memset(vis,0,sizeof(vis));
	vis[nuts[start].r][nuts[start].c] = 1;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		int cr = p.r, cc = p.c, d = p.d;
		if (arr[cr][cc] == 2) dis[start][num[cr][cc]] = d;
		for (int i = 0; i < 8; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (vis[nr][nc]) continue;
			vis[nr][nc] = 1;
			point add = {nr,nc,d+1};
			q.push(add);
		}
	}
}

int tsp(int cur, int vis) {
	if (vis == (1<<N)-1) {
		return dis[cur][0];
	}
	if (dp[cur][vis] != -1) return dp[cur][vis];
	int ans = 100000;
	for (int i = 0; i < N; i++) {
		if ((vis & 1<<i) || i == cur) continue;
		ans = min(ans,dis[cur][i] + tsp(i,vis|1<<i));
	}
	return dp[cur][vis] = ans;
}

int main() {
	while (cin >> R >> C) {
		nuts.clear();
		memset(dis,0,sizeof(dis));
		memset(dp,-1,sizeof(dp));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char ch;
				cin >> ch;
				if (ch == '.') arr[i][j] = 1;
				else {
					arr[i][j] = 2;
					num[i][j] = nuts.size();
					point p = {i,j};
					nuts.push_back(p);
				}
			}
		}
		N = nuts.size();
		for (int i = 0; i < N; i++) bfs(i);
		cout << tsp(0,1) << endl;
	}
    return 0;
}
