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

int R,C;
int dr[8] = {0,0,1,-1,1,1,-1,-1};
int dc[8] = {1,-1,0,0,1,-1,1,-1};
int arr[50][50];
char in[50][50];
int dis[11][11];
int num[50][50];
bool vis[50][50];
int dp[11][1<<11];
vector<point> treasure;
char ch;

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

void bfs(int start) {
	queue<point> q;
	point p = {treasure[start].r, treasure[start].c, 0};
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			vis[i][j] = 0;
	q.push(p);
	dis[start][start] = 0;
	vis[treasure[start].r][treasure[start].c] = 1;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		int cr = p.r, cc = p.c, d = p.d;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (vis[nr][nc] || !arr[nr][nc]) continue;
			vis[nr][nc] = 1;
			point add = {nr,nc,d+1};
			if (arr[nr][nc] == 2) {
				dis[start][num[nr][nc]] = d + 1;
			}
			q.push(add);
		}
	}
}

int tsp(int cur, int vis) {
	if (vis == (1<<treasure.size())-1) {
		return dis[cur][0];
	}
	if (dp[cur][vis] != -1) return dp[cur][vis];
	int ans = 100000;
	for (int i = 0; i < treasure.size(); i++) {
		if ((vis & 1<<i) || i == cur) continue;
		ans = min(ans,dis[cur][i] + tsp(i,vis|1<<i));
	}
	return dp[cur][vis] = ans;
}


int main() {
	while (cin >> R >> C, R || C) {
		treasure.clear();
		memset(dp,-1,sizeof(dp));
		memset(dis,0,sizeof(dis));
		bool works = 1;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> in[i][j];
				arr[i][j] = -1;
				num[i][j] = -1;
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!works) break;
				ch = in[i][j];
				if (ch == '#' || ch == '~') arr[i][j] = 0;
				else if (ch == '!') {
					arr[i][j] = 2;
					num[i][j] = treasure.size();
					point p = {i,j};
					treasure.push_back(p);
				}
				else if (ch == '*') {
					arr[i][j] = 0;
					for (int k = 0; k < 8; k++) {
						int nr = i + dr[k];
						int nc = j + dc[k];
						if (inbounds(nr,nc)) {
							if (in[nr][nc] == '!' || in[nr][nc] == '@') {
								cout << -1 << endl;
								works = 0;
							}
							arr[nr][nc] = 0;
						}
					}
				}
				else if (ch == '@') {
					arr[i][j] = 2;
					num[i][j] = treasure.size();
					point p = {i,j};
					treasure.push_back(p);
				}
				else {
					if (arr[i][j] == -1) arr[i][j] = 1;
				}
			}
		}
		if (!works) continue;
		if (treasure.size() == 1) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < treasure.size(); i++) bfs(i);
		for (int i = 0; i < treasure.size(); i++) {
			for (int j = 0; j < treasure.size(); j++) {
				if (i != j && !dis[i][j]) {
					cout << -1 << endl;
					works = 0;
					break;
				}
			}
			if (!works) break;
		}
		if (!works) continue;
		int ans = tsp(0,1);
		if (ans == 100000) cout << -1 << endl;
		else cout << ans << endl;
	}
    return 0;
}
