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

bitset<26> on;
vector<int> adj[26];
int counter = 0;
int ans;

int main() {
	int N,M;
	while (cin >> N >> M) {
		string s;
		getline(cin,s);
		getline(cin,s);
		on.reset();
		for (int i = 0; i < 26; i++) adj[i].clear();
		for (int i = 0; i < 3; i++) on[s[i]-'A'] = 1;
		for (int m = 0; m < M; m++) {
			getline(cin,s);
			int a = s[0]-'A';
			int b = s[1]-'A';
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		counter = 3;
		ans = 0;
		int done = 0;
		while (counter < N) {
			//cout << counter << " " << ans << endl;
			vector<int> newawake;
			for (int i = 0; i < 26; i++) {
				if (on[i]) continue;
				int neighbors = 0;
				for (int j = 0; j < adj[i].size(); j++) {
					int v = adj[i][j];
					if (on[v]) neighbors++;
				}
				if (neighbors > 2) {
					newawake.push_back(i);
					counter++;
				}
			}
			if (newawake.empty()) {
				cout << "THIS BRAIN NEVER WAKES UP" << endl;
				done = 1;
				break;
			}
			ans++;
			for (int i = 0; i < newawake.size(); i++) {
				on[newawake[i]] = 1;
			}
		}
		if (!done) cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
	}
    
    return 0;
}
