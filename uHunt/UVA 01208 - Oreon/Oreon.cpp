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

int N;
vector<edge> edges;
int p[27];

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
	for (int t = 1; t <= T; t++) {
		edges.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			p[i] = i;
			for (int j = 1; j <= N; j++) {
				int num;
				cin >> num;
				cin.ignore();
				if (num) {
					edge e = {i,j,num};
					edges.push_back(e);
				}
			}
		}
		cout << "Case " << t << ":" << endl;
		sort(edges.begin(),edges.end(),compare);
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.s,e.d)) continue;
			unionSet(e.s,e.d);
			char c1 = min(e.s,e.d) + '@';
			char c2 = max(e.s,e.d) + '@';
			cout << c1 << "-" <<  c2 << " " << e.c << endl;
		}
	}
    return 0;
}
