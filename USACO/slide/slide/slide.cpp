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

struct edge {
    int p,f;
};

int V,E,K;
vector<edge> edges[50001];
long long dp[11][50001];
//long long maxfun = 0;

long long dfs(int cur, int k, long long maxfun) {
    //cout << cur << endl;
    if (dp[k][cur] != -1) {
        return dp[k][cur];
    }
    for (int i = 0; i < edges[cur].size(); i++) {
        edge e = edges[cur][i];
        long long newfun = e.f;
        //cout << i << " " << cur << " " << edges[cur][i].p << endl;
        newfun += dfs(e.p,k,0);
        maxfun = max(maxfun,newfun);
    }
    if (k > 0) {
        for (int i = 0; i < edges[cur].size(); i++) {
            edge e = edges[cur][i];
            long long newfun = e.f;
            //cout << i << " " << cur << " " << edges[cur][i].p << endl;
            newfun += dfs(e.p,k-1,0);
            maxfun = min(maxfun,newfun);
        }
    }
    dp[k][cur] = maxfun;
    return dp[k][cur];
}

int main() {
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int p1,p2,f;
        cin >> p1 >> p2 >> f;
        edge e;
        e.p = p2;
        e.f = f;
        edges[p1].push_back(e);
    }
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = -1;
        }
    }
    cout << dfs(1,K,0) << endl;
    return 0;
}