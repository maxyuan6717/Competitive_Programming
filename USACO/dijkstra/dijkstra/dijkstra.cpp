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

#define LARGE 9999999

using namespace std;

int T,C,s;
int dist[2501];

vector< pair<int,int> > arr[2501];


void dijkstra() {
    
    for (int i = 0; i <= T; i++) {
        dist[i] = LARGE;
    }
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < arr[v].size(); i++) {
            int c = arr[v][i].second;
            int t = arr[v][i].first;
            if (dist[v] + c < dist[t]) {
                dist[t] = dist[v]+c;
                q.push(t);
            }
        }
    }

}

int main() {
    cin >> T >> C >> s;
    for (int i = 0; i < C; i++) {
        int r1,r2,c;
        cin >> r1 >> r2 >> c;
        arr[r1].push_back(make_pair(r2,c));
        arr[r2].push_back(make_pair(r1,c));
    }
    dijkstra();
    for (int i = 1; i <= T; i++) {
        if (dist[i] == LARGE) dist[i] = -1;
        cout << dist[i] << endl;
    }
    
    return 0;
}