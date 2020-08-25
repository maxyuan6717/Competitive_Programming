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
int arr[101][101];
int parent[101];

int dijkstra() {
    int dist[101];
    for (int i = 1; i <= N; i++) {
        dist[i] = LARGE;
        parent[i] = -1;
    }
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            int c = arr[v][i];
            if (dist[v] + c < dist[i]) {
                dist[i] = dist[v] + c;
                q.push(i);
                parent[i] = v;
            }
        }
    }
    return dist[N];
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = LARGE;
        }
    }
    for (int i = 0; i < M; i++) {
        int s,e,c;
        cin >> s >> e >> c;
        arr[s][e] = c;
        arr[e][s] = c;
    }
    int initial = dijkstra();
    int ans = 0;
    for (int i = 2; i <= N; i++) {
        arr[parent[i]][i] *= 2;
        int p = parent[i];
        ans = max(ans,dijkstra());
        arr[p][i] /= 2;
    }
    cout << ans-initial << endl;
    return 0;
}