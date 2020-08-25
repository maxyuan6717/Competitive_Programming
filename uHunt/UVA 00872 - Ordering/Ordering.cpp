#include <iostream>
#include <sstream>
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

vector<int> adj[26];
map<char,int> indx;
map<int,char> rindx;
int N = 0;
vector<int> ans;
int vis[26];
int indeg[26];

void topologicalSort() {
	bool done = 0;
	for (int i = 0; i < N; i++) {
		if (!indeg[i] && !vis[i]) {
			for (int j = 0; j < adj[i].size(); j++) {
				int v = adj[i][j];
				indeg[v]--;
			}
			ans.push_back(i);
			vis[i] = 1;
			topologicalSort();
			vis[i] = 0;
			ans.pop_back();
			for (int j = 0; j < adj[i].size(); j++) {
				int v = adj[i][j];
				indeg[v]++;
			}
			done = 1;
		}
	}
	//cout << done << endl;
	if (!done) {
		if (ans.empty()) cout << "NO" << endl;
		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << rindx[ans[i]];
				if (i != ans.size()-1) cout << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	//ifstream fin ("test");
	int T;
	cin >> T;
	cin.ignore();
	for (int t = 0; t < T; t++) {
		N = 0;
		indx.clear();
		rindx.clear();
		string s;
		getline(cin,s);
		getline(cin,s);
		stringstream ss(s);
		char c;
		while (ss >> c) {
			indx[c] = N;
			rindx[N] = c;
			//cout << c << " " << N << endl;
			N++;
		}
		ans.clear();
		for (int i = 0; i < N; i++) {
			vis[i] = 0;
			indeg[i] = 0;
			adj[i].clear();
		}
		getline(cin,s);
		stringstream ss2(s);
		string s2;
		while (ss2 >> s2) {
			int i1 = indx[s2[0]];
			int i2 = indx[s2[2]];
			adj[i1].push_back(i2);
			indeg[i2]++;
		}
		topologicalSort();
		if (t != T-1) cout << endl;
	}
    
    return 0;
}
