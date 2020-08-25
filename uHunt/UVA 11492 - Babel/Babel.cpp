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

struct edge {
	int v;
	string s;
	bool used;
};

struct point {
	int c;
	char lc;
	int l;
};

bool operator < (point a, point b) {
	return a.c > b.c;
}

int M;
string O,D;
map<string,int> indx;
vector<vector<edge> > adj;
int testNum = 0;

int dijkstra() {
	priority_queue<point> pq;
	point p = {0,'A',indx[O]};
	pq.push(p);
	while (!pq.empty()) {
		p = pq.top();
		pq.pop();
		int cost = p.c;
		char lc = p.lc;
		int l = p.l;
		if (l == indx[D]) return cost;
		for (int i = 0; i < adj[l].size(); i++) {
			edge u = adj[l][i];
			string l2 = u.s;
			bool used = u.used;
			int nl = u.v;
			if (used || l2[0] == lc) continue;
			point add;
			add.c = cost + l2.size();
			add.lc = l2[0];
			add.l = nl;
			pq.push(add);
			adj[l][i].used = 1;
		}
	}
	return -1;
}

int main() {
	cin >> M;
	while (M) {
		testNum++;
		cin >> O >> D;
		int curindx = 1;
		indx.clear();
		adj.clear();
		vector<edge> first;
		adj.push_back(first);
		for (int i = 0; i < M; i++) {
			string s1,s2,s3;
			cin >> s1 >> s2 >> s3;
			int i1 = indx[s1];
			int i2 = indx[s2];
			if (!i1) {
				i1 = curindx++;
				vector<edge> v;
				adj.push_back(v);
			}
			indx[s1] = i1;
			if (!i2) {
				i2 = curindx++;
				vector<edge> v;
				adj.push_back(v);
			}
			indx[s2] = i2;
			edge e1 = {i2,s3,0};
			edge e2 = {i1,s3,0};
			adj[i1].push_back(e1);
			adj[i2].push_back(e2);
		}
		if (!indx[O] || !indx[D]) cout << "impossivel" << endl;
		else {
			int ans = dijkstra();
			if (ans == -1 || O == D) cout << "impossivel" << endl;
			else cout << ans << endl;
		}
		cin >> M;
	}
    
    return 0;
}
