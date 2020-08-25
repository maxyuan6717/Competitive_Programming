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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct pnt {
	int x,y;
};

struct straw {
	pnt p,q;
};

int N;
straw straws[12];
vector<int> adj[12];

bool onSegment(pnt p, pnt q, pnt r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) return 1;
    return 0;
}

int orientation(pnt p, pnt q, pnt r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool doIntersect(straw a, straw b) {
    int o1 = orientation(a.p, a.q, b.p);
    int o2 = orientation(a.p, a.q, b.q);
    int o3 = orientation(b.p, b.q, a.p);
    int o4 = orientation(b.p, b.q, a.q);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(a.p, b.p, a.q)) return 1;
    if (o2 == 0 && onSegment(a.p, b.q, a.q)) return 1;
    if (o3 == 0 && onSegment(b.p, a.p, b.q)) return 1;
    if (o4 == 0 && onSegment(b.p, a.q, b.q)) return 1;
    return 0;
}

bool connected(int a, int b) {
	queue<int> q;
	bool vis[12];
	for (int i = 0; i < N; i++) vis[i] = 0;
	q.push(a);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == b) return 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (vis[v]) continue;
			vis[v] = 1;
			q.push(v);
		}
	}
	return 0;
}

int main() {
	ofstream fout ("out");
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t) cout << endl;
		cin >> N;
		for (int i = 0; i < N; i++) adj[i].clear();
		for (int i = 0; i < N; i++) cin >> straws[i].p.x >> straws[i].p.y >> straws[i].q.x >> straws[i].q.y;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (doIntersect(straws[i],straws[j])) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		int a,b;
		while (cin >> a >> b, a || b) {
			cout << (connected(a-1,b-1) ? "CONNECTED" : "NOT CONNECTED") << endl;
		}
	}
    return 0;
}
