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
vector<edge> mstEdges;
int p[101];

bool compare (edge a, edge b) {
	return a.c < b.c;
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

bool sameEdge(edge a, edge b) {
	return (a.s == b.s && a.d == b.d && a.c == b.c);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		edges.clear();
		mstEdges.clear();
		for (int i = 1; i <= N; i++) {
			p[i] = i;
		}
		for (int i = 0; i < M; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			edge e = {x,y,z};
			edges.push_back(e);
		}
		sort(edges.begin(),edges.end(),compare);
		int ans1 = 0;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.s,e.d)) continue;
			unionSet(e.s,e.d);
			mstEdges.push_back(e);
			ans1 += e.c;
		}
		int ans2 = 10000000;
		for (int i = 0; i < mstEdges.size(); i++) {
			for (int j = 1; j <= N; j++) p[j] = j;
			edge off = mstEdges[i];
			int temp = 0;
			int cnt = 0;
			for (int j = 0; j < edges.size(); j++) {
				edge e = edges[j];
				if (sameEdge(off,e)) continue;
				if (inSameSet(e.s,e.d)) continue;
				unionSet(e.s,e.d);
				temp += e.c;
				cnt++;
			}
			if (cnt == N-1) ans2 = min(ans2,temp);
		}
		cout << ans1 << " " << ans2 << endl;
	}
    return 0;
}
