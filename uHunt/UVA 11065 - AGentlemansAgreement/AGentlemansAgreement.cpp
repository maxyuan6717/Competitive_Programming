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

int N,M,ans1,ans2;
long long adj[60];
long long works;
long long one = 1;

void rec(int cur, int len, long long vis) {
	if (vis == works) {
		ans1++;
		ans2 = max(ans2,len);
		return;
	}
	for (int i = cur; i < N; i++) {
		if (vis&(one<<i)) continue;
		rec(i+1,len+1,vis | adj[i]);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		ans1 = ans2 = 0;
		works = (one<<N)-1;
		//cout << works << endl;
		for (int i = 0; i < N; i++) {
			adj[i] = 0;
			adj[i] |= (one<<i);
		}
		for (int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			adj[u] |= (one<<v);
			adj[v] |= (one<<u);
		}
		rec(0,0,0);
		cout << ans1 << endl << ans2 << endl;
	}
    return 0;
}
