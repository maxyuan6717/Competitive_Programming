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
    int x,y,dir;
};

bool operator< (pair<int,point> a, pair<int,point> b) {
    return a.first < b.first;
}

int N, M;
char arr[501][501];
bool vis[501][501][2];
int dis[501][501][2];

point start, dest;

bool inbounds1(int y) {
    return (y >= 0 && y < N);
}

bool inbounds2(int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N);
}

pair<int,point> mp(int a, point p) {
    return make_pair(a,p);
}

int grav(int x, int y, int dir) {
    while (inbounds1(y)) {
        y+=dir;
        if (arr[y][x] == '#') {
            return (y-dir);
        }
    }
    return -1;
}

int dijkstra() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 2; k++) {
                dis[i][j][k] = LARGE;
            }
        }
    }
    dis[start.y][start.x][1] = 0;
    priority_queue<pair<int,point> , vector<pair<int,point> >, greater<pair<int,point> > > pq;
    pq.push(mp(0,start));
    while(!pq.empty()) {
        point cur = pq.top().second;
        int dir = cur.dir;
        //cout << cur.x << " " << cur.y << " " << dir << endl;
        int d;
        if (dir == 1) d = 1;
        else d = 0;
        pq.pop();
        if (vis[cur.y][cur.x][d]) continue;
        vis[cur.y][cur.x][d] = 1;
        if (cur.y == dest.y && cur.x == dest.x) return dis[cur.y][cur.x][d];
        int nx = cur.x;
        int ny = cur.y + dir;
        
        if (!inbounds2(nx,ny)) continue;
        //cout << cur.x << " " << cur.y << " " << nx << " " << ny << " " << dir  << " " << dis[cur.y][cur.x][d]<< endl;
        if (arr[ny][nx] == '.') {
            //cout << ny << " " << nx << endl;
            if (dis[ny][nx][d] > dis[cur.y][cur.x][d]) {
                //cout << ny << " " << nx << endl;
                dis[ny][nx][d] = dis[cur.y][cur.x][d];
                point n;
                n.y = ny;
                n.x = nx;
                n.dir = dir;
                pq.push(mp(dis[ny][nx][d],n));
            }
            continue;
        }
        ny = cur.y;
        nx = cur.x-1;
        if (inbounds2(nx,ny) && arr[ny][nx] == '.') {
            if (dis[ny][nx][d] > dis[cur.y][cur.x][d]) {
                dis[ny][nx][d] = dis[cur.y][cur.x][d];
                point n;
                n.y = ny;
                n.x = nx;
                n.dir = dir;
                pq.push(mp(dis[ny][nx][d],n));
            }
        }
        nx = cur.x+1;
        if (inbounds2(nx,ny) && arr[ny][nx] == '.') {
            if (dis[ny][nx][d] > dis[cur.y][cur.x][d]) {
                dis[ny][nx][d] = dis[cur.y][cur.x][d];
                point n;
                n.y = ny;
                n.x = nx;
                n.dir = dir;
                pq.push(mp(dis[ny][nx][d],n));
            }
        }
        nx = cur.x;
        if (dis[ny][nx][d] + 1 < dis[ny][nx][1-d]) {
            dis[ny][nx][1-d] = dis[ny][nx][d]+1;
            point n;
            n.y = ny;
            n.x = nx;
            n.dir = -dir;
            pq.push(mp(dis[ny][nx][d],n));
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'C') {
                start.y = grav(j,i,1);
                start.x = j;
                start.dir = 1;
                arr[i][j] = '.';
            }
            else if (arr[i][j] == 'D') {
                dest.y = i;
                dest.x = j;
                arr[i][j] = '.';
            }
        }
    }
    //cout << start.x << " " << start.y << endl;
    cout << dijkstra() << endl;
    
    return 0;
}