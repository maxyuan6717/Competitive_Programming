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

vector<int> adj[26];
int dis[26];
int cost[26];

int longestdist(int cur) {
	if (dis[cur] != -1) return dis[cur];
	dis[cur] = 0;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		dis[cur] = max(dis[cur],longestdist(v));
	}
	dis[cur] += cost[cur];
	return dis[cur];
}

int main() {
	//ifstream fin ("test");
	int T;
	cin >> T;
	cin.ignore();
	string s;
	getline(cin,s);
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 26; i++) {
			adj[i].clear();
			dis[i] = -1;
			cost[i] = 0;
		}
		while (getline(cin,s),s != "") {
			stringstream ss(s);
			char c;
			int indx;
			ss >> c;
			indx = c - 'A';
			ss >> cost[indx];
			string pre;
			if (ss >> pre) {
				for (int i = 0; i < pre.size(); i++) {
					int indx2 = pre[i]-'A';
					adj[indx2].push_back(indx);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			longestdist(i);
		}
		for (int i = 0; i < 26; i++) {
			ans = max(ans,dis[i]);
		}
		cout << ans << endl;
		if (t != T-1) cout << endl;
	}
    return 0;
}
