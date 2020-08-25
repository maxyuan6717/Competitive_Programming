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

int T,start,dest;
vector<int> primes;

void genPrimes() {
	bool prime[10000];
	for (int i = 0; i <= 9999; i++) prime[i] = 1;
	for (int i = 2; i*i <= 9999; i++) {
		if (!prime[i]) continue;
		for (int j = i*2; j <= 9999; j += i) prime[j] = 0;
	}
	for (int i = 1000; i <= 9999; i++) {
		if (prime[i]) primes.push_back(i);
	}
}

int dif(int a, int b) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (a % 10 != b % 10) ret++;
		a/=10;
		b/=10;
	}
	return ret;
}

int bfs() {
	queue<int> q;
	q.push(start);
	int dis[10000];
	for (int i = 0; i <= 9999; i++) dis[i] = LARGE;
	dis[start] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == dest) return dis[u];
		for (int i = 0; i < primes.size(); i++) {
			int v = primes[i];
			if (dis[v] != LARGE) continue;
			if (dif(u,v) == 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	genPrimes();
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> start >> dest;
		int ans = bfs();
		if (ans == -1) cout << "Impossible" << endl;
		else cout << ans << endl;
	}
    return 0;
}
