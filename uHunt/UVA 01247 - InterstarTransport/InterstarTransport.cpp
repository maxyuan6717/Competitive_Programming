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

int N,M,Q;
vii adj[26];
int dis[26],p[26];

int pathLen(int x) {
	int sum = 0;
	for (int i = x; i != -1; i = p[i],sum++);
	return sum;
}

void dijkstra(int s, int d) {
	for (int i = 0; i < 26; i++) dis[i] = LARGE;
	priority_queue<pii,vii,greater<pii> > pq;
	dis[s] = 0;
	p[s] = -1;
	pq.push(mp(0,s));
	while (!pq.empty()) {
		int u = pq.top().s;
		pq.pop();
		if (u == d) break;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].f;
			int c = adj[u][i].s;
			if (dis[u] + c < dis[v] || (dis[u] + c == dis[v] && pathLen(u) + 1 < pathLen(v))) {
				//cout << (char)( u + 'A') << " " << (char) (v + 'A') << endl;
				dis[v] = dis[u] + c;
				p[v] = u;
				pq.push(mp(dis[v],v));
			}
		}
	}
	stack<int> st;
	for (int i = d; i != -1; i = p[i]) st.push(i);
	char start = st.top() + 'A';
	cout << start;
	st.pop();
	while (!st.empty()) {
		char c = st.top()+'A';
		cout << " " << c;
		st.pop();
	}
	cout << endl;
}

int main() {
	while (cin >> N >> M) {
		for (int i = 0; i < 26; i++) adj[i].clear();
		for (int i = 0; i < M; i++) {
			char c1,c2;
			int u,v,c;
			cin >> c1 >> c2 >> c;
			u = c1-'A'; v = c2 - 'A';
			adj[u].push_back(mp(v,c));
			adj[v].push_back(mp(u,c));
		}
		cin >> Q;
		for (int i = 0; i < Q; i++) {
			char c1,c2;
			int u,v;
			cin >> c1 >> c2;
			u = c1-'A'; v = c2 - 'A';
			dijkstra(u,v);
		}
	}
	return 0;
}
