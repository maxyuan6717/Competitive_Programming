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

int V,E;
int arr[2501][2501];
int parent[2501];
int key[2501];
bool mst[2501];

int main() {
    cin >> V >> E;
    for (int i = 0; i <= V; i++) {
        key[i] = LARGE;
        mst[i] = 0;
        for (int j = 0; j <= V; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++) {
        int v1,v2,e;
        cin >> v1 >> v2 >> e;
        arr[v1][v2] = e;
        arr[v2][v1] = e;
    }
    key[1] = 0;
    parent[1] = -1;
    //mst[1] = 1;
    for (int i = 1; i <= V-1; i++) {
        int v = 0;
        int minv = LARGE;
        for (int j = 1; j <= V; j++) {
            if (!mst[j] && key[j] < minv) {
                minv = key[j];
                v = j;
            }
        }
        mst[v] = 1;
        for (int j = 1; j <= V; j++) {
            if (arr[v][j] && !mst[j] && arr[v][j] < key[j]) {
                key[j] = arr[v][j];
                parent[j] = v;
            }
        }
    }
    int ans = 0;
    //for (int i = 1; i <= V; i++) cout << mst[i] << " ";
    //cout << endl;
    for (int i = 1; i <= V; i++) {
        ans += arr[i][parent[i]];
    }
    cout << ans << endl;
    
    return 0;
}