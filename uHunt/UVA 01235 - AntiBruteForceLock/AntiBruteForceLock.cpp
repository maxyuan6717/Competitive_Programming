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

struct edge {
	int u,v,c;
};

int N,p[500];
string keys[500];
vector<edge> edges;

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

int dif(string a, string b) {
	int sum = 0;
	for (int i = 0; i < 4; i++) sum += min(abs(a[i]-b[i]),10+min(a[i],b[i])-max(a[i],b[i]));
	return sum;
}

bool comp (edge a, edge b) {
	return a.c < b.c;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		edges.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> keys[i];
			p[i] = i;
		}
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				edge e = {i,j,dif(keys[i],keys[j])};
				edges.push_back(e);
			}
		}
		sort(edges.begin(),edges.end(),comp);
		int ans = 0;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.u,e.v)) continue;
			unionSet(e.u,e.v);
			ans += e.c;
		}
		int add = LARGE;
		for (int i = 0; i < N; i++) {
			add = min(add,dif("0000",keys[i]));
		}
		ans += add;
		cout << ans << endl;
	}
    return 0;
}
