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

vector<int> adj[1001],adj2[1001];
int N,M;
stack<int> s;
int dis[1001], low[1001], belong[1001], weight[1001], memo[1001];
bool inStack[1001];
int curTime = 0;

void scc(int u) {
	inStack[u] = 1;
	dis[u] = low[u] = ++curTime;
	s.push(u);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (dis[v] == -1) {
			scc(v);
			low[u] = min(low[u],low[v]);
		}
		else if (inStack[v]) {
			low[u] = min(low[u],dis[v]);
		}
	}
	int v;
	if (low[u] == dis[u]) {
		while (s.top() != u) {
			v = s.top();
			s.pop();
			inStack[v] = 0;
			belong[v] = u;
		}
		s.pop();
		inStack[u] = 0;
		belong[u] = u;
	}
}

int dp(int u) {
	if (memo[u]) return memo[u];
	int ret = 0;
	for (int i = 0; i < adj2[u].size(); i++) {
		int v = adj2[u][i];
		ret = max(ret,dp(v));
	}
	memo[u] = ret + weight[u];
	return memo[u];
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			adj2[i].clear();
			dis[i] = -1;
			low[i] = 0;
			inStack[i] = 0;
			weight[i] = 0;
			memo[i] = 0;
		}
		curTime = 0;
		while (s.size()) s.pop();
		for (int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= N; i++) {
			if (dis[i] == -1) {
				scc(i);
			}
		}
		for (int i = 1; i <= N; i++) {
			int u = belong[i];
			weight[u]++;
			for (int j = 0; j < adj[i].size(); j++) {
				int v = belong[adj[i][j]];
				if (u != v) {
					adj2[u].push_back(v);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			ans = max(ans,dp(belong[i]));
		}
		cout << ans << endl;
	}
    return 0;
}
