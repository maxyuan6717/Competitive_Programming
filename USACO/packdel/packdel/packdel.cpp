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

int T,C,s;
int dist[50001];

vector< pair<int,int> > arr[50001];

pair<int,int> mp(int a, int b) {
    return make_pair(a,b);
}

void dijkstra() {
    for (int i = 0; i <= T; i++) {
        dist[i] = LARGE;
    }
    dist[s] = 0;
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
            }
        }
    }
    
}

int main() {
    cin >> T >> C;
    s = 1;
    for (int i = 0; i < C; i++) {
        int r1,r2,c;
        cin >> r1 >> r2 >> c;
        arr[r1].push_back(make_pair(r2,c));
        arr[r2].push_back(make_pair(r1,c));
    }
    dijkstra();
    if (dist[T] == LARGE) cout << -1 << endl;
    else cout << dist[T] << endl;
    
    return 0;
}