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

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

int E;
vector<int> adj[2500];
int vis[2500];
int day[2500];
int src;

pii bfs() {
	queue<pii> q;
	vis[src] = 1;
	q.push(mp(src,0));
	int ans1 = 0, ans2 = 0;
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		int u = p.first;
		int c = p.second;
		if (u != src) day[c]++;
		if (day[c] > ans1) {
			ans1 = day[c];
			ans2 = c;
		}
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (vis[v]) continue;
			vis[v] = 1;
			q.push(mp(v,c+1));
		}
	}
	return mp(ans1,ans2);
}

int main() {
	cin >> E;
	int N;
	for (int i = 0; i < E; i++) {
		cin >> N;
		adj[i].clear();
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			adj[i].push_back(num);
		}
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> src;
		for(int j = 0; j < E; j++) {
			vis[j] = 0;
			day[j] = 0;
		}
		pii ans = bfs();
		if (ans.second == 0) cout << 0 << endl;
		else cout << ans.first << " " << ans.second << endl;
	}
    
    return 0;
}
