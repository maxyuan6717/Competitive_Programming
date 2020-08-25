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

struct farm {
    int x,y;
};

int N;
vector<farm> farms;
set<pair<int,int>> farms2;
vector<pair<int,int>> points;
vector<int> adjlist[501];
int dis[501][501];
int adjx[4] = {0,0,1,-1};
int adjy[4] = {1,-1,0,0};
int s;

int dist(pair<int,int> a, pair<int,int> b) {
    return (abs(a.first-b.first) + abs(a.second-b.second));
}

pair<int,int> mp(int a, int b) {
    return make_pair(a,b);
}

int inrange(int a, int b, int c) {
    return (a > b && a < c);
}

int intersect(farm f, pair<int,int> p1, pair<int,int> p2) {
    int fx = f.x, fy = f.y;
    int p1x = p1.first, p1y = p1.second;
    int p2x = p2.first, p2y = p2.second;
    if (p1x == p2x) return (fx == p1x) && inrange(fy,min(p1y,p2y),max(p1y,p2y));
    if (p1y == p2y) return (fy == p1y) && inrange(fx,min(p1x,p2x),max(p1x,p2x));
    return 1;
}

int cando(int a, int b) {
    pair<int,int> p1 = points[a];
    pair<int,int> p2 = points[b];
    int p1x = p1.first, p1y = p1.second;
    int p2x = p2.first, p2y = p2.second;
    int ret = 0;
    if (p1x == p2x || p1y == p2y || farms2.find(mp(p1x,p2y)) == farms2.end()) ret = 1;
    for (int i = 0; i < N; i++) {
        farm f = farms[i];
        if (intersect(f,p1,mp(p1x,p2y)) || intersect(f,mp(p1x,p2y),p2)) {
            ret = 0;
            break;
        }
    }
    if (ret) return 1;
    if (p1x == p2x || p1y == p2y || farms2.find(mp(p2x,p1y)) == farms2.end()) ret = 1;
    for (int i = 0; i < N; i++) {
        farm f = farms[i];
        if (intersect(f,p1,mp(p2x,p1y)) || intersect(f,mp(p2x,p1y),p2)) {
            ret = 0;
            break;
        }
    }
    if (ret) return 1;
    
    return 0;
}

int dijkstra(int a, int b) {
    int dis[501];
    int vis[501];
    for (int i = 0; i < s; i++) {
        dis[i] = LARGE;
        vis[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        if (i != a && i != b) vis[i] = 1;
    }
    dis[a] = 0;
    for (int i = 0; i < s-1; i++) {
        int mindis = LARGE;
        int indx = 0;
        for (int j = 0; j < s; j++) {
            if (dis[j] <= mindis && !vis[j]) {
                mindis = dis[j];
                indx = j;
            }
        }
        if (vis[indx] || dis[indx] == LARGE) return -1;
        if (indx == b) return dis[indx];
        vis[indx] = 1;
        for (int j = 0; j < adjlist[indx].size(); j++) {
            int v = adjlist[indx][j];
            if (!vis[v] && dis[indx] != LARGE && dis[indx] + dist(points[indx],points[v]) < dis[v]) dis[v] = dis[indx] + dist(points[indx],points[v]);
        }
    }
    return -1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        farm f;
        cin >> f.x >> f.y;
        farms.push_back(f);
        farms2.insert(mp(f.x,f.y));
        points.push_back(mp(f.x,f.y));
    }
    for (int i = 0; i < N; i++) {
        int x = farms[i].x;
        int y = farms[i].y;
        for (int j = 0; j < 4; j++) {
            int nx = x+adjx[j];
            int ny = y+adjy[j];
            pair<int,int> p = mp(nx,ny);
            if (farms2.find(p) == farms2.end()) points.push_back(p);
        }
    }
    s = int(points.size());
    int counter = 0;
    for (int i = 0; i < s; i++) {
        for (int j = i+1; j < s; j++) {
            if (cando(i,j)) {
                //cout << points[i].first << " " << points[i].second << " " << points[j].first << " " << points[j].second << endl;
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
                counter++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int num = dijkstra(i,(i+1)%N);
        //cout << i << " " << num << endl;
        if (num == -1) {
            ans = -1;
            break;
        }
        else {
            ans += num;
        }
        
    }
    cout << ans << endl;
    return 0;
}