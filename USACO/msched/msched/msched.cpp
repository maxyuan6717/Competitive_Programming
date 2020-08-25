/*
 ID: yuanmax1
 PROG: msched
 LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,T[100001],minT[100001],ans = 0;
vector<int> adj[100001];

int rec(int u) {
    if (minT[u] != -1) return minT[u];
    int start = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        start = max(start,rec(v));
    }
    return minT[u] = start + T[u];
}

int main() {
    ifstream fin ("msched.in");
    ofstream fout ("msched.out");
    fin >> N >> M;
    for (int i = 1; i <= N; i++) {
        fin >> T[i];
        minT[i] = -1;
    }
    for (int i = 0; i < M; i++) {
        int u,v;
        fin >> u >> v;
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        ans = max(ans,rec(i));
    }
    fout << ans << endl;
    return 0;
}