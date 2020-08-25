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

struct edge {
	int s,d,c;
};

int N,M;
vector<edge> edges;
int p[10001];

bool compare (edge a, edge b) {
	return a.c > b.c;
}

int find(int u) {
	if (p[u] == u) return u;
	else return p[u] = find(p[u]);
}

bool inSameSet(int u, int v) {
	return find(u) == find(v);
}

void unionSet(int u, int v) {
	p[find(u)] = find(v);
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> M;
		int total = 0;
		edges.clear();
		for (int i = 1; i <= N; i++) {
			p[i] = i;
		}
		for (int i = 0; i < M; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			edge e = {x,y,z};
			edges.push_back(e);
			total += z;
		}
		sort(edges.begin(),edges.end(),compare);
		int ans = 0;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.s,e.d)) continue;
			unionSet(e.s,e.d);
			ans += e.c;
		}
		cout << total-ans << endl;
	}
	int zero;
	cin >> zero;
    return 0;
}
