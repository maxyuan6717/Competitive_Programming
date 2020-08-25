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

int N;
int arr[8][8];
int num[8][8];
int dis[9][9];
bool vis[8][8];
int dr[8] = {1,1,-1,-1,2,2,-2,-2};
int dc[8] = {2,-2,2,-2,1,-1,1,-1};
int dp[9][1<<9];
char ch;
vector<point> coin;
int C;
int indx;
bool works = 1;

bool inbounds(int r, int c) {
	return (r >= 0 && r < 8 && c >= 0 && c < 8);
}

void bfs(int start) {
	point p = {coin[start].r,coin[start].c,0};
	queue<point> q;
	q.push(p);
	memset(vis,0,sizeof(vis));
	dis[start][start] = 0;
	vis[coin[start].r][coin[start].c] = 1;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		int cr = p.r, cc = p.c, d = p.d;
		if (arr[cr][cc] == 2) {
			dis[start][num[cr][cc]] = d;
		}
		for (int i = 0; i < 8; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (vis[nr][nc] || !arr[nr][nc]) continue;
			vis[nr][nc] = 1;
			point add = {nr,nc,d+1};
			q.push(add);
		}
	}
	for (int i = 0; i < C; i++) {
		if (i != start && !dis[start][i]) {
			works = 0;
			return;
		}
	}
}

int tsp(int cur, int vis) {
	if (vis == (1<<C)-1) {
		return dp[cur][vis] = 0;
	}
	if (dp[cur][vis] != -1) return dp[cur][vis];
	int ret = 100000;
	for (int i = 0; i < C; i++) {
		if ((vis&(1<<i)) || i == cur) continue;
		ret = min(ret, dis[cur][i] + tsp(i,vis|(1<<i)));
	}
	return dp[cur][vis] = ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		memset(num,-1,sizeof(num));
		memset(dis,0,sizeof(dis));
		memset(dp,-1,sizeof(dp));
		coin.clear();
		works = 1;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> ch;
				if (ch == '.') arr[i][j] = 1;
				else if (ch == 'p' || ch == 'K') arr[i][j] = 0;
				else {
					arr[i][j] = 2;
					num[i][j] = coin.size();
					if (ch == 'k') indx = coin.size();
					point p = {i,j};
					coin.push_back(p);
				}
			}
		}
		C = coin.size();
		for (int i = 0; i < C; i++) bfs(i);
		if (!works) {
			cout << "No" << endl;
			continue;
		}
		int ans = tsp(indx,1<<indx);
		ans = ans <= N;
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}
