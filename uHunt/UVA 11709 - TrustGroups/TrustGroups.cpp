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

map<string,int> indx;
int P,T;
vector<int> adj1[1001];
vector<int> adj2[1001];
int vis[1001];
stack<int> s;

void dfs1(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < adj1[cur].size(); i++) {
		int v = adj1[cur][i];
		if (vis[v]) continue;
		dfs1(v);
	}
	s.push(cur);
}

void dfs2(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < adj2[cur].size(); i++) {
		int v = adj2[cur][i];
		if (vis[v]) continue;
		dfs2(v);
	}
}

int main() {
	cin >> P >> T;
	while (P || T) {
		for (int i = 0; i < P; i++) {
			vis[i] = 0;
			adj1[i].clear();
			adj2[i].clear();
			string s1,s2;
			cin >> s1 >> s2;
			s1 += " " + s2;
			indx[s1] = i;
		}
		for (int i = 0; i < T; i++) {
			string s1,s2,s3;
			cin >> s1 >> s2;
			s1 += " " + s2;
			cin >> s2 >> s3;
			s2 += " " + s3;
			int i1 = indx[s1];
			int i2 = indx[s2];
			adj1[i1].push_back(i2);
			adj2[i2].push_back(i1);
		}
		for (int i = 0; i < P; i++) {
			if (vis[i]) continue;
			dfs1(i);
		}
		for (int i = 0; i < P; i++) vis[i] = 0;
		int ans = 0;
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			if (!vis[u]) {
				dfs2(u);
				ans++;
			}
		}
		cout << ans << endl;
		cin >> P >> T;
	}
    return 0;
}
