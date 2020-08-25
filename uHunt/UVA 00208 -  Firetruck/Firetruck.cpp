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
#define fout cout

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
vector<int> adj[21];
bool vis[21];
bool works[21][21];
int cnt = 0;

//ofstream fout ("out");

void rec(int cur, vector<int> seq) {
	seq.push_back(cur);
	if (cur == N) {
		for (int i = 0; i < seq.size(); i++) {
			fout << seq[i];
			if (i != seq.size()-1) fout << " ";
		}
		fout << endl;
		cnt++;
		return;
	}
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (vis[v] || !works[v][N]) continue;
		vis[v] = 1;
		rec(v,seq);
		vis[v] = 0;
	}
}

int main() {
	int caseNum = 1;
	while (cin >> N) {
		for (int i = 0; i < 21; i++) {
			adj[i].clear();
			vis[i] = 0;
			for (int j = 0; j < 21; j++) {
				works[i][j] = 0;
			}
		}
		int u,v;
		while (cin >> u >> v,u || v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			works[u][v] = 1;
			works[v][u] = 1;
		}
		for (int i = 0; i < 21; i++) sort(adj[i].begin(),adj[i].end());
		for (int k = 0; k < 21; k++)
			for (int i = 0; i < 21; i++)
				for (int j = 0; j < 21; j++)
					works[i][j] |= (works[i][k] && works[k][j]);
		cnt = 0;
		fout << "CASE " << caseNum++ << ":" << endl;
		vector<int> ve;
		vis[1] = 1;
		rec(1,ve);
		fout << "There are " << cnt << " routes from the firestation to streetcorner " << N << "." << endl;
	}
    return 0;
}
