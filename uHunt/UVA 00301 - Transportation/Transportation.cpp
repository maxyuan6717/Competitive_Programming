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

struct order{
	int u,v,c,n;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,C;
order orders[25];
int room[10];
int ans = 0;

void rec(int cur, int sum) {
	if (cur == C) {
		ans = max(ans,sum);
		return;
	}
	order o = orders[cur];
	bool works = 1;
	for (int i = o.u; i < o.v; i++) {
		room[i] -= o.n;
		if (room[i] < 0) works = 0;
	}
	int temp = sum;
	if (works) {
		sum += o.n*o.c;
		rec(cur+1,sum);
	}
	for (int i = o.u; i < o.v; i++) room[i] += o.n;
	rec(cur+1,temp);
}

int main() {
	while (cin >> N >> M >> C, N || M || C) {
		for (int i = 0; i < C; i++) {
			order o;
			cin >> o.u >> o.v >> o.n;
			o.c = o.v-o.u;
			orders[i] = o;
		}
		ans = 0;
		for (int i = 0; i <= M; i++) room[i] = N;
		rec(0,0);
		cout << ans << endl;
	}
    return 0;
}
