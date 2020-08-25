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

#define LARGE 9999999999

using namespace std;

struct pole {
    double x,y;
};

int N,W;
double M;
double dis[1001][1001];

double dist(pole a, pole b) {
    return sqrt((a.y-b.y)*(a.y-b.y) + (a.x-b.x)*(a.x-b.x));
}

vector<pole> poles;

double dijkstra() {
    double dis2[1001];
    for (int i = 0; i < N; i++) dis2[i] = LARGE;
    queue<int> q;
    q.push(0);
    dis2[0] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            double c = dis[v][i];
            if (c <= M && dis2[v]+c<dis2[i]) {
                dis2[i] = dis2[v]+c;
                q.push(i);
            }
        }
    }
    return dis2[N-1];
}


int main() {
    ifstream fin("pwrfail.in");
    cin >> N >> W >> M;
    //fin >> N >> W >> M;
    for (int i = 0; i < N; i++) {
        int x,y;
        cin >> x >> y;
        //fin >> x >> y;
        pole p;
        p.x = x;
        p.y = y;
        poles.push_back(p);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dis[i][j] = dist(poles[i],poles[j]);
        }
    }
    for (int i = 0; i < W; i++) {
        int s,e;
        cin >> s >> e;
        //fin >> s >> e;
        dis[s-1][e-1] = 0;
        dis[e-1][s-1] = 0;
    }
    double num = dijkstra();
    if (num == LARGE) cout << -1 << endl;
    else {
        int ans = num*1000;
        cout << ans << endl;
    }
    
    return 0;
}