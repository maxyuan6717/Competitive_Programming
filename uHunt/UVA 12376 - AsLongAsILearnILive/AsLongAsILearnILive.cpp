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

int val[100],N,M;
vector<int> adj[100];
bool vis[100];
int total,endNode;

void dfs(int u, int sum) {
	vis[u] = 1;
	int next,add = -1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (val[v] > add) {
			next = v;
			add = val[v];
		}
	}
	if (add == -1) {
		total = sum;
		endNode = u;
		return;
	}
	dfs(next,sum+add);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> val[i];
			adj[i].clear();
			vis[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		dfs(0,0);
		cout << "Case " << t << ": "<< total << " " << endNode << endl;
	}
    return 0;
}
