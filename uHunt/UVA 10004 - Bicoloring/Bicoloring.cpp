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

int N;
vector<int> adj[201];
string ans[2] = {"NOT BICOLORABLE.","BICOLORABLE."};

int bfs() {
	queue<int> q;
	int color[N];
	for (int i = 0; i < N; i++) color[i] = 0;
	q.push(0);
	color[0] = 1;
	int ret = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int c1 = color[u];
		int newc;
		if (c1 == 1) newc = 2;
		else newc = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			int c2 = color[v];
			if (c2 && c2 == c1) {
				ret = 0;
				break;
			}
			if (!c2) {
				color[v] = newc;
				q.push(v);
			}
		}
		if (!ret) break;
	}
	return ret;
}

int main() {
    cin >> N;
    while (N) {
    	int l;
    	cin >> l;
    	for (int i = 0; i < N; i++) adj[i].clear();
    	for (int i = 0; i < l; i++) {
    		int u,v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cout << ans[bfs()] << endl;
    	cin >> N;
    }
    return 0;
}
