#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

#define LARGE 999999999

char arr[31][31];

int N,A,B;

bool inBounds(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int dist[31][31];
bool vis[31][31];
int ans = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct edge {
    int x,y,ox,oy;
};

bool operator< (edge a, edge b) {
    if (arr[a.x][a.y] == arr[a.ox][a.oy]) {
        if (arr[b.x][b.y] == arr[b.ox][b.oy]) {
            return dist[a.ox][a.oy]+A>dist[b.ox][b.oy]+A;
        } else {
                return dist[a.ox][a.oy]+A>dist[b.ox][b.oy]+B;
        }
    } else {
        if (arr[b.x][b.y] == arr[b.ox][b.oy]) {
            return dist[a.ox][a.oy]+B>dist[b.ox][b.oy]+A;
        } else {
            return dist[a.ox][a.oy]+B>dist[b.ox][b.oy]+B;
        }
    }
}

void dijkstra(int bx, int by) {
    priority_queue<edge> p;
    for (int i = 0; i<4; i++) {
        int nx = bx+dx[i];
        int ny = by+dy[i];
        if (inBounds(nx, ny)) {
            edge e1;
            e1.x = nx;
            e1.y = ny;
            e1.ox = bx;
            e1.oy = by;
            p.push(e1);
        }
    }
    vis[bx][by] = true;
    dist[bx][by] = 0;
    while (!p.empty()) {
        edge e = p.top();
        p.pop();
        if (vis[e.x][e.y]) {
            continue;
        }
        vis[e.x][e.y] = true;
        if (arr[e.ox][e.oy] == arr[e.x][e.y]) {
            dist[e.x][e.y] = dist[e.ox][e.oy]+A;
        } else {
            dist[e.x][e.y] = dist[e.ox][e.oy]+B;
        }
        for (int i = 0; i<4; i++) {
            int nx = e.x+dx[i];
            int ny = e.y+dy[i];
            if (inBounds(nx, ny) && !vis[nx][ny]) {
                edge ne;
                ne.ox = e.x;
                ne.oy = e.y;
                ne.x = nx;
                ne.y = ny;
                p.push(ne);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = max(ans,dist[i][j]);
        }
    }
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
}


int main() {
    ifstream fin ("distant.in");
    ofstream fout ("distant.out");
    fin >> N >> A >> B;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            fin >> arr[i][j];
        }
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            dijkstra(i,j);
        }
    }
    fout << ans << endl;
    return 0;
}