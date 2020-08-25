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

vector<int> adj[257];
bool vis[257];
vector<int> seq;
int N;
bool done = 0;

bool rec(int cur, int d) {
    vis[cur] = 1;
    seq.push_back(cur);
    if(done) return true;
    bool ans = false;
    for(int i = 0; i < adj[cur].size(); i++) {
        if(!vis[adj[cur][i]] || (d + 1 == N && adj[cur][i] == 0)) {
            if(d + 1 == N && adj[cur][i] == 0) {
                for(int i = 0; i < seq.size(); i++) {
                	cout << seq[i]+1 << " ";
                }
                cout << 1 << endl;
                return done = 1;
            }
            ans = ans || rec(adj[cur][i], d + 1);
        }
    }
    vis[cur] = 0;
    seq.pop_back();
    return ans;
}
int main() {
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			vis[i] = 0;
		}
		int u,v;
		cin.ignore();
		string s;
		while (getline(cin,s), s[0] != '%') {
			stringstream ss(s);
			ss >> u >> v;
			u--,v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		seq.clear();
		done = 0;
		if (!rec(0,0)) cout << "N" << endl;
	}
    return 0;
}
