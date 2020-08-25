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
int p[200000];

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
	cin >> N >> M;
	while (N || M) {
		edges.clear();
		for (int i = 0; i < N; i++) {
			p[i] = i;
		}
		for (int i = 0; i < M; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			edge e1 = {x,y,z};
			edges.push_back(e1);
		}
		sort(edges.begin(),edges.end(),compare);
		vector<int> ans;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.s,e.d)) {
				ans.push_back(e.c);
				continue;
			}
			unionSet(e.s,e.d);
		}
		sort(ans.begin(),ans.end());
		if (ans.size() == 0) cout << "forest" << endl;
		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i];
				if (i != ans.size()-1) cout << " ";
			}
			cout << endl;
		}
		cin >> N >> M;
	}
    return 0;
}
