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

int S,T;
vector<int> adj[1005];
int pfactors[1005];
bool isPrime[1005];

void genPrimes(int n) {
	memset(isPrime,true,sizeof(isPrime));
	for (int i = 2; i <= n; i+=2) {
		pfactors[i] = 2;
		if (i != 2) isPrime[i] = 0;
	}
	for (long long p = 3; p <= n; p+=2) {
		if (isPrime[p]) {
			pfactors[p] = p;
			for (long long q = p; q*p <= n; q+=2) {
				if (isPrime[p*q]) {
					isPrime[p*q] = 0;
					pfactors[p*q] = p;
				}
			}
		}
	}
}

void genPFactors(int x) {
	if (isPrime[x]) return;
	int temp = x;
	int cur = pfactors[x];
	while (x > 1) {
		x/=pfactors[x];
		if (cur == pfactors[x]) continue;
		adj[temp].push_back(cur);
		cur = pfactors[x];
	}
}

int bfs() {
	queue<int> q;
	bool vis[1005];
	int dis[1005];
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	vis[S] = 1;
	q.push(S);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u > T) continue;
		if (u == T) return dis[u];
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i] + u;
			if (v > 1000) continue;
			if (vis[v]) continue;
			vis[v] = 1;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	return -1;
}

int caseNum = 1;

int main() {
	//ofstream fout ("out");
	genPrimes(1000);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 1; i <= 1000; i++) genPFactors(i);
	while (cin >> S >> T, S || T) {
		cout << "Case " << caseNum++ << ": " << bfs() << endl;
	}
    return 0;
}
