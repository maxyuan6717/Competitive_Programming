#include <iostream>
#include <fstream>
#include <sstream>
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
#define maxn 10001
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
vector<int> adj[maxn];
int dfsNum[maxn];
int dfsLow[maxn];
int dfsParent[maxn];
int root;
int counter = 0;
vii ans;

void articulation(int cur) {
	dfsLow[cur] = dfsNum[cur] = counter++;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (dfsNum[v] == -1) {
			dfsParent[v] = cur;
			articulation(v);
			if (dfsLow[v] > dfsNum[cur]) {
				if (cur < v) ans.push_back(mp(cur,v));
				else ans.push_back(mp(v,cur));
			}
			dfsLow[cur] = min(dfsLow[cur],dfsLow[v]);
		}
		else if (v != dfsParent[cur]) {
			dfsLow[cur] = min(dfsLow[cur],dfsNum[v]);
		}
	}
}

bool compare(pii a, pii b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	while (cin >> N) {
		ans.clear();
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			dfsNum[i] = -1;
			dfsLow[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int u;
			cin >> u;
			string s;
			cin >> s;
			s = s.substr(1,s.size()-2);
			stringstream ss(s);
			int k;
			ss >> k;
			for (int j = 0; j < k; j++) {
				int v;
				cin >> v;
				adj[u].push_back(v);
			}
		}
		counter = 0;
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] != -1) continue;
			root = i;
			articulation(root);
		}
		sort(ans.begin(),ans.end(),compare);
		cout << ans.size() << " critical links" << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " - " << ans[i].second << endl;

		cout << endl;
	}
    
    return 0;
}
