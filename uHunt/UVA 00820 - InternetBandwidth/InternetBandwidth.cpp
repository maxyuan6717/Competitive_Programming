#include <iostream>
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

int N;
int S,T,C;
int res[101][101];
int p[101];
int vis[101];

bool bfs() {
	for (int i = 1; i <= N; i++) { vis[i] = 0; p[i] = 0; }
	vis[S] = 1, p[S] = -1;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == T) return 1;
		for (int i = 1; i <= N; i++) {
			if (vis[i] || !res[u][i]) continue;
			q.push(i);
			vis[i] = 1;
			p[i] = u;
		}
	}
	return 0;
}

int ek() {
	int ans = 0;
	while (bfs()) {
		int flow = LARGE;
		for (int i = T; i != S; i = p[i]) {
			flow = min(flow,res[p[i]][i]);
		}
		for (int i = T; i != S; i = p[i]) {
			res[p[i]][i] -= flow;
			res[i][p[i]] += flow;
		}
		ans += flow;
	}
	return ans;
}

int main() {
	cin >> N;
	int nNum = 1;
	while (N) {
		memset(res,0,sizeof(res));
		cin >> S >> T >> C;
		for (int i = 0; i < C; i++) {
			int u,v,c;
			cin >> u >> v >> c;
			res[u][v] += c;
			res[v][u] += c;
		}
		cout << "Network " << nNum++ << endl;
		cout << "The bandwidth is " << ek() << "." << endl;
		cout << endl;
		cin >> N;
	}
    return 0;
}
