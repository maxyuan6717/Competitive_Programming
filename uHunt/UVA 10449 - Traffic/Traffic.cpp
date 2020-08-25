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
int busyness[201];
int dis[201];
vector<edge> edges;
int r;

void bellmanford() {
	dis[1] = 0;
	for (int i = 0; i < N-1; i++) {
		edges.clear();
		for (int j = 0; j < M; j++) {
			edge e = edges[j];
			int u = e.u, v = e.v, c = e.c;
			if (dis[u] == LARGE) continue;
			if (dis[u] + c < dis[v]) {
				dis[v] = dis[u] + c;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		edge e = edges[i];
		int u = e.u, v = e.v, c = e.c;
		if (dis[u] == LARGE) continue;
		if (dis[u] + c < dis[v]) {
			dis[v] = -100000;
		}
	}
}

int main() {
	int setNum = 1;
    while (cin >> N) {
    	for (int i = 1; i <= N; i++) {
    		cin >> busyness[i];
    		dis[i] = LARGE;
    	}
    	cin >> M;
    	for (int i = 0; i < M; i++) {
    		int u,v;
    		cin >> u >> v;
    		int c = pow((busyness[v]-busyness[u]),3);
    		edge e = {u,v,c};
    		edges.push_back(e);
    	}
    	bellmanford();
    	int q;
    	cin >> q;
    	cout << "Set #" << setNum++ <<endl;
    	int dest;
    	for (int i = 0; i < q; i++) {
    		cin >> dest;
    		if (dis[dest] < 3 || dis[dest] == LARGE) cout << "?" << endl;
    		else cout << dis[dest] << endl;
    	}
    }
    return 0;
}
