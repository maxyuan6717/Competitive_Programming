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

int N,M,lines[10001],dis[10001];
vector<int> adj[10001];

int bfs (int s) {
	for (int i = 0; i <= N; i++) dis[i] = -1;
	dis[s] = 0 ;
	queue<int> q;
	q.push(s);
	int sum = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (dis[v] >= 0) continue;
			dis[v] = dis[u] + 1;
			if (lines[v] > 1) sum += dis[v];
			q.push(v);
		}
	}
	return sum;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i <= N; i++) {
			adj[i].clear();
			lines[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int p = 0,c;
			while (cin >> c,c) {
				lines[c]++;
				if (p) {
					adj[c].push_back(p);
					adj[p].push_back(c);
				}
				p = c;
			}
		}
		int ans,minDis = LARGE;
		for (int i = 1; i <= N; i++) {
			if (lines[i] > 1) {
				int sum = bfs(i);
				if (sum < minDis) {
					minDis = sum;
					ans = i;
				}
			}
		}
		cout << "Krochanska is in: " << ans << endl;
	}
    return 0;
}
