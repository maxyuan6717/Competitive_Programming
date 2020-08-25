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
#define radius 6378.0
#define PI 3.141592653589793/180
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct city {
	string name;
	double x,y;
};

int N,M,Q,dis[100][100];
vector<int> adj[100];
city cities[100];
map<string,int> indx;

int dijkstra(int start, int dest) {
	int dist[100];
	for (int i = 0; i < N; i++) dist[i] = LARGE;
	dist[start] = 0;
	priority_queue<pii,vii,greater<pii> > pq;
	pq.push(mp(0,start));
	while (!pq.empty()) {
		int u = pq.top().s;
		pq.pop();
		if (u == dest) return dist[u];
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (dist[u] + dis[u][v] < dist[v]) {
				dist[v] = dist[u] + dis[u][v];
				pq.push(mp(dist[v],v));
			}
		}
	}
	return -1;
}

int main() {
	int caseNum = 1;
	while (cin >> N >> M >> Q, N || M || Q) {
		if (caseNum++ > 1) cout << endl;
		cout << "Case #" << caseNum-1 << endl;
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			cin >> cities[i].name >> cities[i].x >> cities[i].y;
			indx[cities[i].name] = i;
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				double lat1 = cities[i].x * PI, lat2 = cities[j].x * PI;
				double lon1 = cities[i].y * PI, lon2 = cities[j].y * PI;
				double cs = cos(lat1) * cos(lat2) * cos(lon2 - lon1) + sin(lat1) * sin(lat2);
				dis[i][j] = dis[j][i] = (int) (radius * acos(cs) + 0.5);
			}
		}
		for (int i = 0; i < M; i++) {
			string s1,s2;
			cin >> s1 >> s2;
			adj[indx[s1]].push_back(indx[s2]);
		}
		for (int i = 0; i < Q; i++) {
			string s1,s2;
			cin >> s1 >> s2;
			int ans =  dijkstra(indx[s1],indx[s2]);
			if (ans == -1) cout << "no route exists" << endl;
			else cout << ans << " km" << endl;
		}
	}
    return 0;
}
