/*
 ID: yuanmax1
 PROG: mroute
 LANG: C++
 */
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

struct edge {
    int v,l,c;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,X;
vector<edge> adj[501];

int dijkstra(int C) {
    int dis[501];
    for (int i = 0; i <= 500; i++) dis[i] = LARGE;
    dis[1] = 0;
    priority_queue<pii,vii,greater< pii > > pq;
    pq.push(mp(0,1));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (u == N) return dis[u];
        for (int i = 0; i < adj[u].size(); i++) {
            if (adj[u][i].c < C) continue;
            int v = adj[u][i].v;
            int l = adj[u][i].l;
            if (dis[u] + l < dis[v]) {
                dis[v] = dis[u] + l;
                pq.push(mp(dis[v],v));
            }
        }
    }
    return -1;
}

int main() {
    ofstream fout ("mroute.out");
    ifstream fin ("mroute.in");
    fin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int u,v,l,c;
        fin >> u >> v >> l >> c;
        edge e1 = {v,l,c};
        edge e2 = {u,l,c};
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }
    int ans = LARGE;
    for (int i = 1; i <= M; i++) {
        int L = dijkstra(i);
        if (L == -1) break;
        ans = min(ans, L + (X/i));
    }
    fout << ans << endl;
    return 0;
}