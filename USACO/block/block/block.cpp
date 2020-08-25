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

int N,R;
vector<pair<int,int>> adj[5001];

pair<int,int> mp(int a, int b){
    return make_pair(a,b);
}

pair<int,pair<int,int>> mp2(int a, int b, int c) {
    return make_pair(a,make_pair(b,c));
}

int dijkstra() {
    int dis[5001][2];
    for (int i = 0; i <= N; i++) {
        dis[i][0]= LARGE;
        dis[i][1] = LARGE;
    }
    dis[1][0] = 0;
    priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int> > > > pq;
    pq.push(mp2(0,1,0));
    while (!pq.empty()) {
        int v = pq.top().second.first;
        int d = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i].first;
            int c = adj[v][i].second;
            if (dis[v][d]+c < dis[u][0]) {
                dis[u][1] = dis[u][0];
                dis[u][0] = dis[v][d] + c;
                pq.push(mp2(dis[u][0],u,0));
            }
            else if (dis[v][d]+c != dis[u][0] && dis[v][d] + c < dis[u][1]) {
                dis[u][1] = dis[v][d] + c;
                pq.push(mp2(dis[u][1],u,1));
            }
        }
    }
    return dis[N][1];
}

int main() {
    cin >> N >> R;
    for (int i = 0; i < R; i++) {
        int i1,i2,c;
        cin >> i1 >> i2 >> c;
        adj[i1].push_back(mp(i2,c));
        adj[i2].push_back(mp(i1,c));
    }
    cout << dijkstra() << endl;
    
    return 0;
}