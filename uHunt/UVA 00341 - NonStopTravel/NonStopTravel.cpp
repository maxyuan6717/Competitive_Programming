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
#define maxN 11

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
vii adj[maxN];
int dis[maxN];
int p[maxN];
int start,dest;

int dijkstra() {
	dis[start] = 0;
	p[start] = -1;
	priority_queue<pii,vii,greater<pii> > pq;
	pq.push(mp(0,start));
	while (!pq.empty()) {
		int u = pq.top().second;
		int c = pq.top().first;
		pq.pop();
		if (u == dest) return c;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int nc = adj[u][i].second;
			if (c + nc < dis[v]) {
				dis[v] = c + nc;
				p[v] = u;
				pq.push(mp(dis[v],v));
			}
		}
	}
	return -1;
}

int main() {
	cin >> N;
	int caseNum = 1;
    while (N) {
    	for (int i = 1; i <= N; i++) {
    		adj[i].clear();
    		dis[i] = LARGE;
    		p[i] = 0;
    		int I;
    		cin >> I;
    		for (int j = 0; j < I; j++) {
    			int v,c;
    			cin >> v >> c;
    			adj[i].push_back(mp(v,c));
    		}
    	}
    	cin >> start >> dest;
    	int ans = dijkstra();
    	vector<int> ansstr;
    	for (int i = dest; i != -1; i = p[i]) {
    		ansstr.push_back(i);
    	}
    	reverse(ansstr.begin(),ansstr.end());
    	cout << "Case " << caseNum++ << ": Path =";
    	for (int i = 0; i < ansstr.size(); i++) {
    		cout << " " << ansstr[i];
    	}
    	cout << "; " << ans << " second delay" << endl;
    	cin >> N;
    }
    return 0;
}
