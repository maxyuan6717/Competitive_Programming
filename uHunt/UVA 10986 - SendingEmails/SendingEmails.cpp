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

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,S,D;
vii adj[20001];
int dis[20001];

int dijkstra() {
	priority_queue<pii,vii,greater<pii> > pq;
	dis[S] = 0;
	pq.push(mp(0,S));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int c = adj[u][i].second;
			if (dis[u] + c < dis[v]) {
				dis[v] = dis[u] + c;
				pq.push(mp(dis[v],v));
			}
		}
	}
	return dis[D];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
    	cin >> N >> M >> S >> D;
    	for (int i = 0; i < N; i++) {
    		adj[i].clear();
    		dis[i] = LARGE;
    	}
    	for (int i = 0; i < M; i++) {
    		int a,b,c;
    		cin >> a >> b >> c;
    		adj[a].push_back(mp(b,c));
    		adj[b].push_back(mp(a,c));
    	}
    	cout << "Case #" << t << ": ";
    	int ans = dijkstra();
    	if (ans == LARGE) cout << "unreachable" << endl;
    	else cout << ans << endl;
    }
    return 0;
}
