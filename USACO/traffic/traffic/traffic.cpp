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
vector<int> adj1[5001];
vector<int> adj2[5001];
vector<pair<int,int>> edges;
set<int> graze;
int indeg[5001];
int in[5001];
int out[5001];

void bfs1() {
    out[N] = 1;
    for (int i = N-1; i >= 1; i--) {
        for (int j = 0; j < adj1[i].size(); j++) {
            out[i] += out[adj1[i][j]];
        }
    }
}

void bfs2() {
    set<int>::iterator it;
    for (it = graze.begin(); it != graze.end(); it++) in[*it] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < adj2[i].size(); j++) {
            in[i] += in[adj2[i][j]];
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) graze.insert(i);
    for (int i = 0; i < M; i++) {
        int i1,i2;
        cin >> i1 >> i2;
        edges.push_back(make_pair(i1,i2));
        indeg[i2]++;
        if (indeg[i2] == 1) graze.erase(graze.find(i2));
        adj1[i1].push_back(i2);
        adj2[i2].push_back(i1);
    }
    bfs1();
    bfs2();
    //for (int i = 1; i <= N; i++) cout << out[i] << endl;
    //for (int i = 1; i <= N; i++) cout << in[i] << endl;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        pair<int,int> p = edges[i];
        int p1 = p.first, p2 = p.second;
        ans = max(ans,in[p1]*out[p2]);
        //cout << p1 << " " << p2 << " " << in[p1] << " " << out[p2] << endl;
    }
    cout << ans << endl;
    return 0;
}