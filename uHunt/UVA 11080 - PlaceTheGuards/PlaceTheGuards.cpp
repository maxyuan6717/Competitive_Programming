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

int V,E;
vector<int> adj[200];
int color[200];

int bfs(int start) {
	color[start] = 1;
	queue<int> q;
	q.push(start);
	int c1 = 1, c2 = 0;
	while(!q.empty()) {
		int u = q.front();
		//cout << u << endl;
		q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (color[v] && color[v] == color[u]) return -1;
			else if (color[v]) continue;
			if (color[u] == 1) color[v] = 2,c2++;
			else color[v] = 1,c1++;
			q.push(v);
		}
	}
	if (c2) return min(c1,c2);
	else return c1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> V >> E;
		for (int i = 0; i < V; i++) {
			adj[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			int f,t;
			cin >> f >> t;
			adj[f].push_back(t);
			adj[t].push_back(f);
		}
		int ans = 0;
		for (int i = 0; i < V; i++) {
			if (!color[i]) {
				int m = bfs(i);
				if (m == -1) {
					ans = -1;
					break;
				}
				else ans += m;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
