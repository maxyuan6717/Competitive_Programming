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

int N;
vector<int> adj[10001];
int marbles[10001],out[10001],parent[10001];

int main() {
	while (cin >> N, N) {
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			out[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int u,v,d;
			cin >> u >> marbles[u] >> d;
			for (int j = 0; j < d; j++) {
				cin >> v;
				adj[u].push_back(v);
				out[u]++;
				parent[v] = u;
			}
		}
		queue<int> q;
		int ans = 0;
		for (int i = 1; i <= N; i++) if (!out[i]) q.push(i);
		while (!q.empty()) {
			int u = q.front();
			int v = parent[u];
			q.pop();
			ans += abs(marbles[u]-1);
			marbles[v] += marbles[u]-1;
			marbles[u] = 1;
			out[v]--;
			if (!out[v]) q.push(v);
		}
		cout << ans << endl;
	}
    return 0;
}
