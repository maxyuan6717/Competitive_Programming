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

#define LARGE (1<<31)-1

using namespace std;

struct constraint {
	int a,b;
	int c;
};

int N,M;
vector<constraint> cons;
int vis = 0;
int row[8];
int indx[8];
int ans = 0;

void dfs(int cur) {
	if (cur == N) {
		for (int i = 0; i < cons.size(); i++) {
			int a = cons[i].a;
			int b = cons[i].b;
			int c = cons[i].c;
			a = indx[a];
			b = indx[b];
			if (c > 0 && abs(a-b) > c) return;
			if (c < 0 && abs(a-b) < -c) return;
		}
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if ((vis&1<<i)) continue;
		vis |= 1<<i;
		row[cur] = i;
		indx[i] = cur;
		dfs(cur+1);
		vis ^= 1<<i;
	}
}

int main() {
    cin >> N >> M;
    while (N || M) {
    	cons.clear();
    	for (int i = 0; i < M; i++) {
    		constraint co;
    		cin >> co.a >> co.b >> co.c;
    		cons.push_back(co);
    	}
    	vis = 0;
    	ans = 0;
    	dfs(0);
    	cout << ans << endl;
    	cin >> N >> M;
    }
    return 0;
}
