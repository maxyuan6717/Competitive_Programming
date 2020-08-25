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
#define MAXN 50001
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M;
int dist[MAXN];
bool vis[MAXN];

vii arr[MAXN];

void dijkstra(int st) {
    for (int i = 0; i <= N; i++) {
        dist[i] = LARGE;
        vis[i] = 0;
    }
    dist[st] = 0;
    priority_queue< pii,vii,greater<pii> > pq;
    pq.push(mp(0,st));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < arr[u].size(); i++) {
            int c = arr[u][i].s;
            int v = arr[u][i].f;
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u]+c;
                pq.push(mp(dist[v],v));
            }
        }
    }
    
}

int main() {
    ifstream fin ("dijkstra2.in");
    fin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u,v,c;
        fin >> u >> v >> c;
        arr[u].push_back(mp(v,c));
        arr[v].push_back(mp(u,c));
    }
    dijkstra(1);
    for (int i = 1; i <= N; i++) {
        if (dist[i] == LARGE) dist[i] = -1;
        cout << dist[i] << endl;
    }
    
    return 0;
}