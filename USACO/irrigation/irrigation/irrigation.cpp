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
//hi im max and im kinda stoopid
#define LARGE 9999999

using namespace std;

int V,C;
int arr[2001][2001];
pair<int,int> farms[2001];
int parent[2001];
int key[2001];
bool mst[2001];

int dist(int a, int b) {
    int x1 = farms[a].first, y1 = farms[a].second;
    int x2 = farms[b].first, y2 = farms[b].second;
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


int main() {
    ifstream fin("test.in");
    cin >> V >> C;
    for (int i = 0; i < V; i++) {
        key[i] = LARGE;
        mst[i] = 0;
        parent[i] = -1;
        cin >> farms[i].first >> farms[i].second;
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = dist(i,j);
            arr[j][i] = arr[i][j];
        }
    }
    key[0] = 0;
    //mst[1] = 1;
    for (int i = 1; i <= V-1; i++) {
        int v = 0;
        int minv = LARGE;
        for (int j = 0; j < V; j++) {
            if (!mst[j] && key[j] < minv) {
                minv = key[j];
                v = j;
            }
        }
        mst[v] = 1;
        for (int j = 0; j < V; j++) {
            if (arr[v][j] && !mst[j] && arr[v][j] < key[j] & arr[v][j] >= C) {
                key[j] = arr[v][j];
                parent[j] = v;
            }
        }
    }
    int ans = 0;
    //for (int i = 1; i <= V; i++) cout << mst[i] << " ";
    //cout << endl;
    for (int i = 1; i < V; i++) {
        //cout << parent[i] << endl;
        if (parent[i] != -1) ans += arr[i][parent[i]];
        else {
            ans = -1;
            break;
        }
    }
    if (ans) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}