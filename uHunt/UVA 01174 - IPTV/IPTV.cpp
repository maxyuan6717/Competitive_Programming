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
int p[2001];
map<string,int> indx;

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

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		indx.clear();
		edges.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			p[i] = i;
		}
		int curIndx = 1;
		for (int i = 0; i < M; i++) {
			int x,y,z;
			string s1,s2;
			cin >> s1 >> s2 >> z;
			x = indx[s1], y = indx[s2];
			if (!x) indx[s1] = curIndx++, x = indx[s1];
			if (!y) indx[s2] = curIndx++, y = indx[s2];
			edge e1 = {x,y,z};
			edges.push_back(e1);
		}
		sort(edges.begin(),edges.end(),compare);
		int ans = 0;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.s,e.d)) continue;
			unionSet(e.s,e.d);
			ans += e.c;
		}
		cout << ans << endl;
		if (t != T-1) cout << endl;
	}
    return 0;
}
