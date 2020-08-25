/*
 ID: yuanmax1
 PROG: tractor
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

int N,arr[500][500];
bool vis[500][500];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool inbounds(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N);
}

int flood(int r, int c, int d) {
    if (vis[r][c]) return 0;
    vis[r][c] = 1;
    int cnt  = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!inbounds(nr,nc) || abs(arr[nr][nc]-arr[r][c]) > d) continue;
        cnt += flood(nr,nc,d);
    }
    return cnt;
}

bool works(int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vis[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            if (flood(i,j,M)*2 >= N*N) return 1;
        }
    }
    return 0;
}

int main() {
    ifstream fin ("tractor.in");
    ofstream fout ("tractor.out");
    fin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> arr[i][j];
        }
    }
    int l = -1, r = 1000000;
    while (l+1 < r) {
        int m = (l+r)/2;
        if (works(m)) r = m;
        else l = m;
    }
    fout << r << endl;
    return 0;
}