/*
 ID: yuanmax1
 PROG: ccski
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

int R,C,arr[500][500];
bool way[500][500],vis[500][500];
vii wpnts;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool inbounds(int r, int c) {
    return (r >= 0 && c >= 0 && r < R && c < C);
}

void rec(int r, int c, int m) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!inbounds(nr,nc) || vis[nr][nc] || abs(arr[nr][nc] - arr[r][c]) > m) continue;
        vis[nr][nc] = 1;
        rec(nr,nc,m);
    }
}

bool works(int m) {
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) vis[i][j] = 0;
    vis[wpnts[0].f][wpnts[0].s] = 1;
    rec(wpnts[0].f,wpnts[0].s,m);
    for (int i = 1; i < wpnts.size(); i++) {
        if (!vis[wpnts[i].f][wpnts[i].s]) return 0;
    }
    return 1;
}

int main() {
    ifstream fin ("ccski.in");
    ofstream fout ("ccski.out");
    fin >> R >> C;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) fin >> arr[i][j];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fin >> way[i][j];
            if (way[i][j]) wpnts.push_back(mp(i,j));
        }
    }
    int l = 0, r = 1e9;
    while (l < r) {
        int m = (r+l)/2;
        if (works(m)) r = m;
        else l = m+1;
    }
    fout << l << endl;
    return 0;
}