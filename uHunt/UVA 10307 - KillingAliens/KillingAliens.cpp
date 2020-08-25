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

struct edge {
	int u,v,d;
};

char arr[50][50];
int R,C;
pii pnts[101];
int indx[50][50];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
vector<edge> edges;
int p[101];

bool comp(edge a, edge b) {
	return a.d < b.d;
}

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
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

void bfs(int start) {
	queue<pii> q;
	int dist[50][50];
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) dist[i][j] = -1;
	q.push(pnts[start]);
	dist[pnts[start].f][pnts[start].s] = 0;
	while (!q.empty()) {
		int r = q.front().f, c = q.front().s;
		q.pop();
		if (indx[r][c] >= 0) {
			edge add = {start,indx[r][c],dist[r][c]};
			edges.push_back(add);
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (!inbounds(nr,nc) || dist[nr][nc] >= 0 || arr[nr][nc] == '#') continue;
			dist[nr][nc] = dist[r][c] + 1;
			q.push(mp(nr,nc));
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> C >> R;
		cin.ignore();
		edges.clear();
		int idx = 0;
		memset(indx,-1,sizeof(indx));
		for (int i = 0; i < R; i++) {
			string str;
			getline(cin,str);
			int j = 0;
			for (; j < str.size(); j++) {
				arr[i][j] = str[j];
				if (arr[i][j] == 'S' || arr[i][j] == 'A') {
					pnts[idx] = mp(i,j);
					indx[i][j] = idx++;
				}
			}
			for (; j < C; j++) arr[i][j] = ' ';
		}
		for (int i = 0; i < idx; i++) {
			bfs(i);
			p[i] = i;
		}
		sort(edges.begin(),edges.end(),comp);
		int ans = 0;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.u,e.v)) continue;
			unionSet(e.u,e.v);
			ans += e.d;
		}
		cout << ans << endl;
	}
    return 0;
}
