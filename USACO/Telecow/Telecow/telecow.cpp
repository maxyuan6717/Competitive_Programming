/*
 ID: yuanmax1
 PROG: telecow
 LANG: C++
 */
#include <iostream>
#include <cstdio>
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
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

int N,M,s,t;
bool arr[201][201];
int cost[201][201];
int temp[201][201];
int par[201];
int vis[201];
vector<int> adj[201];

void reset() {
    for (int i = 0; i <= 2*N; i++) {
        for (int j = 0; j <= 2*N; j++) {
            cost[i][j] = temp[i][j];
        }
    }
}

bool bfs() {
    for (int i = 0; i <= 2*N; i++) {
        vis[i] = 0;
        par[i] = -1;
    }
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        //cout << u << endl;
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            //cout << u << " " << v << endl;
            if (vis[v] || cost[u][v] <= 0) continue;
            vis[v] = 1;
            par[v] = u;
            if (v == t) break;
            q.push(v);
        }
        if (vis[t]) break;
    }
    if (!vis[t]) return 0;
    int cur = t;
    int flow = LARGE;
    while (par[cur] != -1) {
        int v = par[cur];
        flow = min(flow,cost[v][cur]);
        cur = v;
    }
    cur = t;
    while (par[cur] != -1) {
        int v = par[cur];
        cost[v][cur] -= flow;
        cost[cur][v] += flow;
        cur = v;
    }
    return flow;
}

int dinics() {
    int maxflow = 0,flow;
    flow = bfs();
    while (flow) {
        maxflow += flow;
        flow = bfs();
    }
    return maxflow;
}

int main() {
    ofstream fout ("telecow.out");
    ifstream fin ("telecow.in");
    fin >> N >> M >> s >> t;
    //cout << N << " " << M << " " << s << " " << t << endl;
    s = 2*s, t = 2*t-1;
    for (int i = 1; i <= 2*N; i++) for (int j = 1; j <= 2*N; j++) {arr[i][j] = 0;cost[i][j] = 0;temp[i][j] = 0;}
    for (int i = 1; i <= N; i++) {
        adj[2*i-1].push_back(2*i);
        adj[2*i].push_back(2*i-1);
        cost[2*i-1][2*i] = 1;
        temp[2*i-1][2*i] = 1;
    }
    for (int i = 0; i < M; i++) {
        int u,v;
        fin >> u >> v;
        //cout << 2*u << " " << 2*v << endl;
        adj[2*u].push_back(2*v-1);
        adj[2*v].push_back(2*u-1);
        cost[2*u][2*v-1] = cost[2*v][2*u-1] = M;
        temp[2*u][2*v-1] = temp[2*v][2*u-1] = M;
    }
    vector<int> ans;
    int maxflow = dinics();
    //cout << maxflow << endl;
    //reset();
    for (int i = 1; i <= N; i++) {
        if (2*i == s || 2*i-1 == t) continue;
        int u = 2*i-1, v = 2*i;
        reset();
        cost[u][v] -= 1;
        int newMaxflow = dinics();
        //cout << i << " " << maxflow << " " << newMaxflow << endl;
        if (newMaxflow + 1 == maxflow) {
            ans.push_back(i);
            maxflow = newMaxflow;
            temp[u][v] = 0;
            if (!maxflow) break;
        }
        else cost[u][v] += 1;
    }
    fout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];
        if (i != ans.size()-1) fout << " ";
    }
    if (ans.size()) fout << endl;
    
    return 0;
}