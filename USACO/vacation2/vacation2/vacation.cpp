/*
 ID: yuanmax1
 PROG: vacation
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

#define LARGE 1000000000000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,K,Q;
long long dis[201][201];

int main() {
    ifstream fin ("vacation.in");
    ofstream fout ("vacation.out");
    fin >> N >> M >> K >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dis[i][j] = LARGE;
            if (i == j) dis[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int u,v,d;
        fin >> u >> v >> d;
        dis[u][v] = d;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    long long ans = 0, tot = 0;
    for (int i = 0; i < Q; i++) {
        int u,v;
        fin >> u >> v;
        long long minD = LARGE;
        for (int k = 1; k <= K; k++) {
            minD = min(minD,dis[u][k] + dis[k][v]);
        }
        if (minD != LARGE) {
            ans++;
            tot += minD;
        }
    }
    fout << ans << endl << tot << endl;
    return 0;
}