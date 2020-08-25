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

int X,Y,P;
char arr[30][30];
int res[62][62][62][62];
vii adj[62][62];
bool vis[62][62];
pii p[62][62];
int S,T;

bool inbounds(int x, int y) {
	return (x >= 0 && x < X && y >= 0 && y < Y);
}

bool bfs() {
	for (int i = 0; i <= T; i++) {
		for (int j = 0; j <= T; j++) {
			vis[i][j] = 0;
			p[i][j] = mp(-1,-1);
		}
	}
	queue<pii> q;
	vis[S][S] = 1;
	q.push(mp(S,S));
	while (!q.empty()) {
		int u = q.front().first;
		int v = q.front().second;
		q.pop();
		if (u == T && v == T) return 1;
		for (int i = 0; i < adj[u][v].size(); i++) {
			int a = adj[u][v][i].first;
			int b = adj[u][v][i].second;
			if (vis[a][b] || res[u][v][a][b] <= 0) continue;
			vis[a][b] = 1;
			q.push(mp(a,b));
			p[a][b] = mp(u,v);
		}
	}
	return 0;
}

int ek() {
	int ans = 0;
	while (bfs()) {
		int flow = LARGE;
		pii i, dest = mp(T,T), start = mp(S,S);
		for (i = dest; i != start; i = p[i.first][i.second]) {
			int u = i.first, v = i.second;
			int a = p[u][v].first, b = p[u][v].second;
			//cout << a << " " << b << " " << u << " " << v << endl;
			flow = min(flow,res[a][b][u][v]);
		}
		for (i = dest; i != start; i = p[i.first][i.second]) {
			int u = i.first, v = i.second;
			int a = p[u][v].first, b = p[u][v].second;
			res[a][b][u][v] -= flow;
			res[u][v][a][b] += flow;
			adj[u][v].push_back(mp(a,b));
		}
		ans += flow;
	}
	return ans;
}

int main() {
	while (scanf("%d %d %d", &X,&Y,&P) != EOF) {
		S = 2*max(X,Y);
		T = S+1;
		for (int i = 0; i <= T; i++) {
			for (int j = 0; j <= T; j++) {
				adj[i][j].clear();
				for (int k = 0; k <= T; k++) {
					for (int l = 0; l <= T; l++) {
						res[i][j][k][l] = 0;
					}
				}
			}
		}
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '~') continue;
				if (arr[i][j] == '.' || arr[i][j] == '*') {
					res[2*i][2*j][2*i+1][2*j+1] = 1;
				}
				else if (arr[i][j] == '@' || arr[i][j] == '#') {
					res[2*i][2*j][2*i+1][2*j+1] = LARGE;
				}
				adj[2*i][2*j].push_back(mp(2*i+1,2*j+1));
				if (arr[i][j] == '*') {
					res[S][S][2*i][2*j] = 1;
					adj[S][S].push_back(mp(2*i,2*j));
				}
				else if (arr[i][j] == '#') {
					res[2*i+1][2*j+1][T][T] = P;
					adj[2*i+1][2*j+1].push_back(mp(T,T));
				}
				int u = i-1, v = j;
				if (inbounds(u,v) && arr[u][v] != '~') {
					res[2*i+1][2*j+1][2*u][2*v] = LARGE;
					res[2*u+1][2*v+1][2*i][2*j] = LARGE;
					adj[2*i+1][2*j+1].push_back(mp(2*u,2*v));
					adj[2*u+1][2*v+1].push_back(mp(2*i,2*j));
				}
				u = i, v = j-1;
				if (inbounds(u,v) && arr[u][v] != '~') {
					res[2*i+1][2*j+1][2*u][2*v] = LARGE;
					res[2*u+1][2*v+1][2*i][2*j] = LARGE;
					adj[2*i+1][2*j+1].push_back(mp(2*u,2*v));
					adj[2*u+1][2*v+1].push_back(mp(2*i,2*j));
				}
			}
		}
		cout << ek() << endl;
	}
    return 0;
}
