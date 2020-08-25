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

struct point {
    int x,y;
    bool o;
};

bool operator< (pair<int,point> a, pair<int,point> b) {
    return a.first < b.first;
}

int N,M;
char arr[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dis[1001][1001][2];
bool vis[1001][1001][2];

bool inbounds(int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N);
}

pair<int,point> mp(int a, point p) {
    return make_pair(a,p);
}

int dijkstra() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dis[i][j][0] = LARGE;
            dis[i][j][1] = LARGE;
        }
    }
    dis[0][0][0] = 0;
    point start;
    start.x = 0;
    start.y = 0;
    start.o = 0;
    priority_queue<pair<int,point> , vector<pair<int,point> >, greater<pair<int,point> > > pq;
    pq.push(mp(0,start));
    while (!pq.empty()) {
        point cur = pq.top().second;
        pq.pop();
        if (vis[cur.y][cur.x][cur.o]) continue;
        if (arr[cur.y][cur.x] != '4') vis[cur.y][cur.x][cur.o] = 1;
        if (cur.y == N-1 && cur.x == M-1) return dis[cur.y][cur.x][cur.o];
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (!inbounds(nx,ny)) continue;
            if (arr[ny][nx] == '0') continue;
            if (arr[ny][nx] == '1') {
                if (dis[cur.y][cur.x][cur.o] + 1 < dis[ny][nx][cur.o]) {
                    dis[ny][nx][cur.o] = dis[cur.y][cur.x][cur.o] + 1;
                    point n;
                    n.x = nx;
                    n.y = ny;
                    n.o = cur.o;
                    pq.push(mp(dis[ny][nx][n.o],n));
                }
            }
            else if (arr[ny][nx] == '2') {
                if (dis[cur.y][cur.x][cur.o]+1 < dis[ny][nx][1]) {
                    dis[ny][nx][1] = dis[cur.y][cur.x][cur.o] + 1;
                    point n;
                    n.x = nx;
                    n.y = ny;
                    n.o = 1;
                    pq.push(mp(dis[ny][nx][n.o],n));
                }
            }
            else if (arr[ny][nx] == '3') {
                if (dis[cur.y][cur.x][cur.o] + 1 < dis[ny][nx][cur.o] && cur.o) {
                    dis[ny][nx][cur.o] = dis[cur.y][cur.x][cur.o] + 1;
                    point n;
                    n.x = nx;
                    n.y = ny;
                    n.o = 1;
                    pq.push(mp(dis[ny][nx][n.o],n));
                }
            }
            else if (arr[ny][nx] == '4') {
                int moves = 1;
                while (inbounds(nx+dx[i],ny+dy[i]) && arr[ny+dy[i]][nx+dx[i]] == '4') {
                    nx += dx[i];
                    ny += dy[i];
                    moves++;
                }
                int nny = ny + dy[i];
                int nnx = nx + dx[i];
                if (!inbounds(nnx,nny) || arr[nny][nnx] == '0' || arr[nny][nnx] == '3') {
                    if (dis[cur.y][cur.x][cur.o] + moves < dis[ny][nx][0]) {
                        dis[ny][nx][0] = dis[cur.y][cur.x][cur.o] + moves;
                        point n;
                        n.x = nx;
                        n.y = ny;
                        n.o = 0;
                        pq.push(mp(dis[ny][nx][0],n));
                    }
                }
                else if (arr[nny][nnx] == '1') {
                    if (dis[cur.y][cur.x][cur.o] + moves + 1 < dis[nny][nnx][cur.o]) {
                        dis[nny][nnx][cur.o] = dis[cur.y][cur.x][cur.o] + moves + 1;
                        point n;
                        n.x = nnx;
                        n.y = nny;
                        n.o = cur.o;
                        pq.push(mp(dis[nny][nnx][n.o],n));
                    }
                }
                else {
                    if (dis[cur.y][cur.x][cur.o] + moves + 1 < dis[nny][nnx][1]) {
                        dis[nny][nnx][cur.o] = dis[cur.y][cur.x][cur.o] + moves + 1;
                        point n;
                        n.x = nnx;
                        n.y = nny;
                        n.o = 1;
                        pq.push(mp(dis[nny][nnx][n.o],n));
                    }
                }
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    cout << dijkstra() << endl;
    
    return 0;
}