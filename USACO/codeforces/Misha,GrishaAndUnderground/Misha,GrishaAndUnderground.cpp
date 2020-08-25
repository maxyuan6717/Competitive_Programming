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

#define LARGE 999999999

using namespace std;

int N,Q;
vector<int> adj[100001];
bool mark[100001];
bool vis[100001];
int stations[3];
int s,t,f;
bool done = 0;
int counter = 0;
int pos[6][3] = {
    {0,1,2},
    {0,2,1},
    {1,0,2},
    {1,2,0},
    {2,0,1},
    {2,1,0}
};

void dfs1(int cur) {
    if (cur == f) done = 1;
    if (done) return;
    for (int i = 0; i < adj[cur].size(); i++) {
        int v= adj[cur][i];
        if (vis[v]) continue;
        vis[v] = 1;
        mark[v] = 1;
        dfs1(v);
        if (done) return;
        vis[v] = 0;
        mark[v] = 0;
    }
}

void dfs2(int cur) {
    if (cur == f) done = 1;
    if (done) return;
    for (int i = 0; i < adj[cur].size(); i++) {
        int v = adj[cur][i];
        if (vis[v]) continue;
        vis[v] = 1;
        if (mark[v]) counter++;
        dfs2(v);
        if (done) return;
        vis[v] = 0;
        if (mark[v]) counter--;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for (int i = 0; i < Q; i++) {
        cin >> stations[0] >> stations[1] >> stations[2];
        int ans = 0;
        for (int j = 0; j < 6; j++) {
            s = stations[pos[j][0]];
            t = stations[pos[j][1]];
            f = stations[pos[j][2]];
            //cout << s << " " << f << endl;
            done = 0;
            counter = 0;
            for (int i = 1; i <= N; i++) {
                mark[i] = 0;
                vis[i] = 0;
            }
            mark[s] = 1;
            vis[s] = 1;
            dfs1(s);
            for (int i = 1; i <= N; i++) {
                vis[i] = 0;
                //cout << mark[i] << " ";
            }
            //cout << endl;
            vis[t] = 1;
            done = 0;
            counter += (mark[t] == 1);
            dfs2(t);
            ans = max(ans,counter);
        }
        cout << ans << endl;
    }
    
    return 0;
}