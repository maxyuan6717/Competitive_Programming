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

int N,M;
vector<pair<int,int> > adj1[10001];
vector<pair<int,int> > adj2[10001];
vector<pair<int,int> > adj[10001];
int dist[10001];
int parent[10001];
vector<int> parent1;
vector<int> parent2;
int s;

pair<int,int> mp(int a, int b) {
    return make_pair(a,b);
}

void dijkstra(vector<pair<int,int> > arr[10001]) {
    for (int i = 0; i <= N; i++) {
        dist[i] = LARGE;
        parent[i] = -1;
    }
    dist[s] = 0;
    parent[s] = -1;
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > pq;
    pq.push(mp(0,s));
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for (int i = 0; i < arr[v].size(); i++) {
            int c = arr[v][i].second;
            int t = arr[v][i].first;
            if (dist[v] + c < dist[t]) {
                dist[t] = dist[v]+c;
                pq.push(mp(dist[t],t));
                parent[t] = v;
            }
        }
    }
    
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int i1,i2,p,q;
        cin >> i1 >> i2 >> p >> q;
        adj1[i2].push_back(mp(i1,p));
        adj2[i2].push_back(mp(i1,q));
    }
    s = N;
    dijkstra(adj1);
    for (int i = 1; i <= N; i++) parent1.push_back(parent[i]);
    //for (int i = 0; i < N; i++) cout << parent1[i] << " ";
    //cout << endl;
    dijkstra(adj2);
    for (int i = 1; i <= N; i++) parent2.push_back(parent[i]);
    //for (int i = 0; i < N; i++) cout << parent2[i] << " ";
    //cout << endl;
    // For every node
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < adj1[i].size(); j++) {
            int v = adj1[i][j].first;
            int cost = 2;
            if (parent1[v-1] == i) cost--;
            if (parent2[v-1] == i) cost--;
            adj[v].push_back(mp(i,cost));
            //cout << v << " " << i << " " << cost << endl;
        }
    }
    s = 1;
    dijkstra(adj);
    cout << dist[N] << endl;
    
    return 0;
}