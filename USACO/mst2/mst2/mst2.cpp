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

int V,E;
vector<pair<int,int>> arr[50001];
map<int,map<int,int>> m;

pair<int,int> mp(int a, int b) {
    return make_pair(a,b);
}

int main() {
    cin >> V >> E;
    vector<int> key(V+1,LARGE);
    vector<int> parent(V+1,-1);
    vector<bool> used(V+1,0);
    for (int i = 0; i < E; i++) {
        int v1,v2,e;
        cin >> v1 >> v2 >> e;
        arr[v1].push_back(make_pair(v2,e));
        arr[v2].push_back(make_pair(v1,e));
    }
    priority_queue< pair<int,int> ,vector< pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(mp(0,1));
    key[1] = 0;
    int sum = 0;
    while (!pq.empty()) {
        int v = pq.top().second;
        //int c = pq.top().first;
        pq.pop();
        used[v] = 1;
        for (int i = 0; i < arr[v].size(); i++) {
            int newv = arr[v][i].first;
            int newc = arr[v][i].second;
            if (!used[newv] && newc < key[newv]) {
                pq.push(mp(newc,newv));
                parent[newv] = v;
                key[newv] = newc;
                m[newv][v] = newc;
            }
        }
    }
    for (int i = 2; i <= V; i++) sum += m[i][parent[i]];
    cout << sum << endl;
    return 0;
}