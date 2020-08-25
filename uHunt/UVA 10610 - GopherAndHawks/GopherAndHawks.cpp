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

struct hole {
	double x,y;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int V,M,N,T;
double sx,sy,dx,dy;
hole holes[1002];

double dist(hole a, hole b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int bfs() {
	int dis[1002];
	for (int i = 0; i < N; i++) dis[i] = -1;
	dis[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == N-1) return dis[u]-1;
		for (int v = 0; v < N; v++) {
			double c = dist(holes[u],holes[v]);
			if (c > T || dis[v] != -1) continue;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	return -1;
}

int main() {
	//ifstream fin ("test");
	while (cin >> V >> M, V || M) {
		T = V*M*60;
		cin >> sx >> sy >> dx >> dy;
		cin.ignore();
		string s;
		N = 1;
		holes[0].x = sx, holes[0].y = sy;
		while (getline(cin,s),s != "") {
			double x,y;
			stringstream ss(s);
			ss >> x >> y;
			holes[N].x = x;
			holes[N++].y = y;
		}
		holes[N].x = dx, holes[N++].y = dy;
		int ans = bfs();
		if (ans == -1) cout << "No." << endl;
		else cout << "Yes, visiting " << ans << " other holes." << endl;
	}
    return 0;
}
