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
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct state {
	int v,l;
	vector<int> seq;
};

map<string,int> indx;
vector<string> words;
vector<int> adj[26000];
vector<int> ans;
bool vis[26000];

int works(string a, string b) {
	int n = a.size();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) cnt++;
		if (cnt > 1) return 0;
	}
	return 1;
}

void bfs(int st, int d) {
	queue<state> q;
	state s;
	s.v = st, s.l = 0;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		int u = s.v;
		s.seq.push_back(u);
		if (u == d && s.l) {
			ans = s.seq;
			return;
		}
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (vis[v]) continue;
			vis[v] = 1;
			state next;
			next.v = v, next.l = s.l + 1;
			next.seq = s.seq;
			q.push(next);
		}
	}
}

int main() {
	//ifstream fin ("in");
	string s;
	indx.clear();
	words.clear();
	int cindx = 1;
	int caseNum = 0;
	while (getline(cin,s), s != "") {
		words.push_back(s);
		adj[cindx].clear();
		vis[cindx] = 0;
		indx[s] = cindx++;
		for (int i = 1; i < cindx-1; i++) {
			string s2 = words[i-1];
			if (s.size() != s2.size()) continue;
			if (works(s,s2)) {
				adj[cindx-1].push_back(i);
				adj[i].push_back(cindx-1);
			}
		}
	}
	string u,v;
	while (cin >> u >> v) {
		if (caseNum++) cout << endl;
		int start = indx[u];
		int dest = indx[v];
		if (!start || !dest) {
			cout << "No solution." << endl;
			continue;
		}
		for (int i = 0; i < cindx; i++) vis[i] = 0;
		ans.clear();
		bfs(start,dest);
		if (ans.empty()) {
			cout << "No solution." << endl;
			continue;
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << words[ans[i]-1] << endl;
		}
	}
    return 0;
}
