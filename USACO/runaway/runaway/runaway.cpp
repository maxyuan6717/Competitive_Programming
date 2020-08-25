/*
 ID: yuanmax1
 PROG: runaway
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

typedef pair<int,long long> pii;
typedef vector<pii> vii;

int N,L,ans[200001];
vii adj[200001];

void bfs(int s) {
    long long dis[200001];
    for (int i = 1; i<=N; i++) dis[i] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            long long d = adj[u][i].second;
            if (dis[u] + d > L) continue;
            dis[v] = dis[u] + d;
            ans[s]++;
            q.push(v);
        }
    }
}

int main() {
    ofstream fout ("runaway.out");
    ifstream fin ("runaway.in");
    fin >> N >> L;
    ans[1] = 1;
    for (int i = 2; i <= N; i++) {
        ans[i] = 1;
        int pi;
        long long d;
        fin >> pi >> d;
        adj[pi].push_back(mp(i,d));
    }
    for (int i = 1; i <= N; i++) bfs(i);
    for (int i = 1; i <= N; i++) fout << ans[i] << endl;
    
    return 0;
}