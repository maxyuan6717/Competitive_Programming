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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector< pair<int,double> > vid;
typedef vector< pdi > vdi;

int R,C,N;
double D,dis[10001];
pdd safe[10001];
vid adj[10001];
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double dist(pdd a, pdd b) {
	return hypot(a.s-b.s,a.f-b.f);
}

bool dijkstra() {
    for (int i = 0; i < N; i++) dis[i] = LARGE;
    dis[N-2] = 0;
    priority_queue<pdi,vdi,greater<pdi> > pq;
    pq.push(mp(0,N-2));
    while (!pq.empty()) {
        int u = pq.top().s;
        int w = pq.top().f;
        pq.pop();
        if (cmp(w, dis[u]) > 0) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            double c = adj[u][i].s;
            int v = adj[u][i].f;
            if (cmp(dis[u] + c, dis[v]) < 0) {
                dis[v] = dis[u]+c;
                pq.push(mp(dis[v],v));
            }
        }
    }
    return (dis[N-1] < D);
}

int main() {
	string done;
	while (cin >> done, done != "*") {
		stringstream ss(done);
		ss >> C;
		cin >> R >> N;
		for (int i = 0; i < N+2; i++) adj[i].clear();
		for (int i = 0; i < N; i++) {
			cin >> safe[i].s >> safe[i].f;
			for (int j = 0; j < i; j++) {
				double d = dist(safe[i],safe[j]);
				if (cmp(d,1.5) <= 0) {
					adj[i].push_back(mp(j,d));
					adj[j].push_back(mp(i,d));
				}
			}
		}
		cin >> D;
		safe[N] = mp(0,0);
		safe[N+1] = mp(R,C);
		N += 2;
		for (int i = N-2; i < N; i++) {
			for (int j = 0; j < i; j++) {
				double d = dist(safe[i],safe[j]);
				if (d < 1.5) {
					adj[i].push_back(mp(j,d));
					adj[j].push_back(mp(i,d));
				}
			}
		}
		if (dijkstra()) cout << "I am lucky!" << endl;
		else cout << "Boom!" << endl;
	}
    return 0;
}
