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
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

struct edge {
	int u,v,c;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M;
vector<edge> edges;
int dis[1000];
string ans[2] = {"not possible","possible"};

int bellmanford() {
	dis[0] = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < M; j++) {
			edge e = edges[j];
			int u = e.u, v = e.v, c = e.c;
			if (dis[u] == LARGE) continue;
			if (dis[u] + c < dis[v]) {
				dis[v] = dis[u] + c;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		edge e = edges[i];
		int u = e.u, v = e.v, c = e.c;
		if (dis[u] == LARGE) continue;
		if (dis[u] + c < dis[v]) {
			ans = 1;
			break;
		}
	}
	return ans;
}

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> N >> M;
		edges.clear();
		for (int i = 0; i < N; i++) {
			dis[i] = LARGE;
		}
		for (int i = 0; i < M; i++) {
			int u,v,c;
			cin >> u >> v >> c;
			edge e = {u,v,c};
			edges.push_back(e);
		}
		cout << ans[bellmanford()] << endl;
	}
    
    return 0;
}
