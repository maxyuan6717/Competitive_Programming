/*
 ID: yuanmax1
 PROG: gravity
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

int R,C,dis[500][500];
bool vis[500][500];
char arr[500][500];
int dc[3] = {1,-1,0};
pii st,en;

struct pnt {
    int r,c,dir;
    pnt(int row, int col, int direction) {
        r = row, c = col, dir = direction;
    }
};

bool operator<(pair<int,pnt> a, pair<int,pnt> b) {
    return a.f > b.f;
}

bool inbounds(int r, int c) {
    return (r >= 0 && r < R && c >= 0 && c < C);
}

int fall(int r, int c, int dir) {
    while (arr[r+dir][c] != '#') {
        r += dir;
        if (!inbounds(r,c)) return -1;
        if (arr[r][c] == 'D') return r;
    }
    return r;
}

int dijkstra() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dis[i][j] = LARGE;
            vis[i][j] = 0;
        }
    }
    dis[st.f][st.s] = 0;
    priority_queue< pair<int,pnt> > pq;
    pnt start(st.f,st.s,1);
    pq.push(mp(0,start));
    while (!pq.empty()) {
        pnt p = pq.top().s;
        pq.pop();
        int r = p.r, c = p.c, dir = p.dir;
        int d = (dir == -1) ? 0 : 1;
        //cout << r << " " << c << " " << dir << " " << dis[r][c][dir] << endl;
        if (vis[r][c]) continue;
        vis[r][c] = 1;
        if (arr[r][c] == 'D') return dis[r][c];
        for (int i = 0; i < 3; i++) {
            int nc = c + dc[i];
            if (!inbounds(r,nc) || arr[r][nc] == '#') continue;
            int ndir = dir;
            int nd = d;
            int add = 0;
            if (nc == c) {
                ndir = 0 - dir;
                nd = 1-d;
                add++;
            }
            int nr = fall(r,nc,ndir);
            if (!inbounds(nr,nc) || vis[nr][nc]) continue;
            if (dis[r][c] + add < dis[nr][nc]) {
                dis[nr][nc] = dis[r][c] + add;
                p = pnt(nr,nc,ndir);
                pq.push(mp(dis[nr][nc],p));
            }
        }
    }
    return -1;
}

int main() {
    ifstream fin ("gravity.in");
    ofstream fout ("gravity.out");
    fin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fin >> arr[i][j];
            if (arr[i][j] == 'C') st = mp(i,j);
            if (arr[i][j] == 'D') en = mp(i,j);
        }
    }
    st.f = fall(st.f,st.s,1);
    if (st.f == -1) {
        fout << -1 << endl;
        return 0;
    }
    fout << dijkstra() << endl;
    return 0;
}