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

int N,M;
vector<int> adj1[2001];
vector<int> adj2[2001];
int vis[2001];

void dfs1(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < adj1[cur].size(); i++) {
		int v = adj1[cur][i];
		if (vis[v]) continue;
		dfs1(v);
	}
}

void dfs2(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < adj2[cur].size(); i++) {
		int v = adj2[cur][i];
		if (vis[v]) continue;
		dfs2(v);
	}
}

int main() {
    cin >> N >> M;
    while (N || M) {
    	for (int i = 1; i <= N; i++) {
    		vis[i] = 0;
    		adj1[i].clear();
    		adj2[i].clear();
    	}
    	for (int i = 0; i < M; i++) {
    		int v,w,p;
    		cin >> v >> w >> p;
    		adj1[v].push_back(w);
    		adj2[w].push_back(v);
    		if (p == 2) {
    			adj1[w].push_back(v);
    			adj2[v].push_back(w);
    		}
    	}
    	dfs1(1);
    	int ans = 1;
    	for (int i = 1; i <= N; i++) {
    		if (!vis[i]) ans = 0;
    		vis[i] = 0;
    	}
    	if (ans) {
    		dfs2(1);
    		for (int i = 1; i <= N; i++) {
    			if (!vis[i]) {
    				ans = 0;
    				break;
    			}
    		}
    	}
    	cout << ans << endl;
    	cin >> N >> M;
    }
    return 0;
}
