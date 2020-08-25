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
typedef vector<pii> vii;

int N,M;
vector<int> adj[10001];
int dfsNum[10001];
int dfsLow[10001];
int dfsParent[10001];
int root;
int rootChildren = 0;
set<int> artpoints;
set<int> notartpoints;
int counter = 0;
int down;
int vis[10001];

void articulation(int cur) {
	dfsLow[cur] = dfsNum[cur] = counter++;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (dfsNum[v] == -1) {
			dfsParent[v] = cur;
			if (cur == root) rootChildren++;
			articulation(v);
			if (dfsLow[v] >= dfsNum[cur] && cur != root) {
				artpoints.insert(cur);
				set<int>::iterator it;
				it = notartpoints.find(cur);
				if (it != notartpoints.end()) notartpoints.erase(it);
			}
			dfsLow[cur] = min(dfsLow[cur],dfsLow[v]);
		}
		else if (v != dfsParent[cur]) {
			dfsLow[cur] = min(dfsLow[cur],dfsNum[v]);
		}
	}
}

void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (v == down || vis[v]) continue;
		dfs(v);
	}
}

bool compare(pii a, pii b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

int main() {
	cin >> N >> M;
	while (N || M) {
		artpoints.clear();
		notartpoints.clear();
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			notartpoints.insert(i);
			dfsNum[i] = -1;
			dfsLow[i] = 0;
		}
		int x,y;
		cin >> x >> y;
		while (x != -1 && y != -1) {
			adj[x].push_back(y);
			adj[y].push_back(x);
			cin >> x >> y;
		}
		counter = 0;
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] != -1) continue;
			root = i;
			rootChildren = 0;
			articulation(root);
			if (rootChildren > 1) {
				artpoints.insert(root);
				set<int>::iterator it;
				it = notartpoints.find(root);
				if (it != notartpoints.end()) notartpoints.erase(it);
			}
		}
		set<int>::iterator it;
		vii ans;
		ans.clear();
		for (it = artpoints.begin(); it != artpoints.end(); it++) {
			down = *it;
			int connectedCount = 0;
			for (int i = 0; i < N; i++) vis[i] = 0;
			for (int i = 0; i < N; i++) {
				if (i == down || vis[i]) continue;
				connectedCount++;
				dfs(i);
			}
			ans.push_back(mp(connectedCount,*it));
		}
		sort(ans.begin(),ans.end(),compare);
		if (ans.size() < M) {
			for (int i = 0; i < ans.size(); i++) cout << ans[i].second << " " << ans[i].first << endl;
			it = notartpoints.begin();
			for (int i = 0; i < M-ans.size(); i++) {
				cout << *it << " " << 1 << endl;
				it++;
			}
		}
		else {
			for (int i = 0; i < M; i++) cout << ans[i].second << " " << ans[i].first << endl;
		}
		cout << endl;
		cin >> N >> M;
	}
    return 0;
}
