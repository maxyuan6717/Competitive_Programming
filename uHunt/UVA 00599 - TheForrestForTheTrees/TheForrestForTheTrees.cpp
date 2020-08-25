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

vector<int> adj[26];
bitset<26> vis;
int counter = 0;

void dfs(int cur) {
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (vis[v]) continue;
		else {
			vis[v] = 1;
			counter++;
			dfs(v);
		}
	}
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
    	string s;
    	cin >> s;
    	int trees = 0;
    	int acorns = 0;
    	for (int i = 0; i < 26; i++) {
    		vis[i] = 1;
    		adj[i].clear();
    	}
    	while (s[0] != '*') {
    		int a = s[1] - 'A';
    		int b = s[3] - 'A';
    		adj[a].push_back(b);
    		adj[b].push_back(a);
    		cin >> s;
    	}
    	cin >> s;
    	for (int i = 0; i < s.size(); i += 2) vis[s[i]-'A'] = 0;
    	for (int i = 0; i < 26; i++) {
    	    if (vis[i]) continue;
    	    counter = 1;
    	    dfs(i);
    	    if (counter == 1) acorns++;
    	    else trees++;
    	}
    	cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
    }
    return 0;
}
