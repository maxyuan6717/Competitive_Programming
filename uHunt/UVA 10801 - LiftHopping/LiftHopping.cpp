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
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,K;
int speeds[5];
set<int> adj[100];
int dis[100][100];
int dist[100];

int dijkstra() {
	dist[0] = 0;
	priority_queue<pii,vii,greater<pii> > pq;
	pq.push(mp(0,0));
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		int u = p.second;
		//cout << u << endl;
		if (u == K) return dist[u];
		//cout << u << " " << dist[u] << endl;
		set<int>::iterator it;
		for (it = adj[u].begin(); it != adj[u].end(); it++) {
			int v = *it;
			int c = dis[u][v];
			//cout << u << " " << v <<  " " << c << " " << dist[u] << " " << dist[v] << endl;
			int newd;
			if (u == 0) newd = dist[u] + c;
			else newd = dist[u] + c + 60;
			if (newd < dist[v]) {
				dist[v] = newd;
				pq.push(mp(dist[v],v));
			}
		}
	}
	return -1;
}

int main() {
	while (cin >> N >> K) {
		cin.ignore();
		for (int i = 0; i < N; i++) {
			cin >> speeds[i];
		}
		for (int i = 0; i < 100; i++) {
			adj[i].clear();
			dist[i] = LARGE;
			for (int j = 0; j < 100; j++) {
				dis[i][j] = LARGE;
			}
		}
		cin.ignore();
		for (int i = 0; i < N; i++) {
			stringstream ss;
			string s;
			getline(cin,s);
			ss << s;
			int num;
			int counter = 0;
			vector<int> v;
			while (ss >> num) {
				v.push_back(num);
				for (int j = 0; j < counter; j++) {
					adj[num].insert(v[j]);
					adj[v[j]].insert(num);
					dis[num][v[j]] = min(dis[num][v[j]],(num-v[j])*speeds[i]);
					dis[v[j]][num] = dis[num][v[j]];
					//cout << num << " " << v[j] << " " << dis[num][v[j]] << endl;
				}
				counter++;
			}
		}
		int ans = dijkstra();
		if (ans == -1) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;
	}
    
    return 0;
}
