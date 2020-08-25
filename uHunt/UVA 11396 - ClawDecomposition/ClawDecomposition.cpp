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

using namespace std;

int V;
vector<int> adj[301];
int color[301];

int bfs(int start) {
	color[start] = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int c = color[u];
		int nc;
		if (c == 1) nc = 2;
		else nc = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v= adj[u][i];
			if (color[v] && color[v] == c) return 0;
			else if (color[v]) continue;
			color[v] = nc;
			q.push(v);
		}
	}
	return 1;
}

int main() {
    cin >> V;
    while (V) {
    	int u,v;
    	cin >> u >> v;
    	for (int i = 1; i <= V; i++) {
    		adj[i].clear();
    		color[i] = 0;
    	}
    	while (u || v) {
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    		cin >> u >> v;
    	}
    	int ans = 1;
    	for (int i = 1; i <= V; i++) {
    		if (!color[i]) {
    			ans = bfs(i);
    			//cout << i << " " << ans << endl;
    			if (!ans) break;
    		}
    	}
    	if (ans) cout << "YES" << endl;
    	else cout <<"NO" << endl;
    	cin >> V;
    }
    return 0;
}
