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

int N;
vector<int> adj[15000];
vector<int> adj2[15000];
bool vis[15000];
int dp[15000];
stack<int> s;

void topsort(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (vis[v]) continue;
		topsort(v);
	}
	s.push(cur);
}

int main() {
	int caseNum = 0;
	while (cin >> N) {
		if (caseNum) cout << endl;
		for (int i = 0; i < N; i++) adj2[i].clear();
		for (int i = 0; i < N; i++) {
			int M;
			cin >> M;
			adj[i].clear();
			vis[i] = 0;
			dp[i] = 0;
			for (int j = 0; j < M; j++) {
				int v;
				cin >> v;
				adj[i].push_back(v);
				adj2[v].push_back(i);
			}
		}
		topsort(0);
		dp[0] = 1;
		int ans = 0;
		s.pop();
		if (adj[0].empty()) ans += dp[0];
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			for (int i = 0; i < adj2[u].size(); i++) {
				int v = adj2[u][i];
				dp[u] += dp[v];
			}
			if (adj[u].empty()) ans += dp[u];
		}
		cout << ans << endl;
		caseNum++;
	}
    return 0;
}
