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
int R,C;
char arr[51][51];
int mx[8] = {0,-1,0,1,-1,1,-1,1};
int my[8] = {-1,0,1,0,-1,-1,1,1};
pair<int,int> start;
pair<int,int> point;

bool inbounds(int x, int y)  {
    return (x >= 0 && x < C && y >= 0 && y < R);
}

pair<pair<int,int>,int> mp(int x, int y, int z) {
    return make_pair(make_pair(x,y),z);
}

int circumnavigate() {
    int dist[51][51][2];
    int crossed[51][51];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dist[i][j][0] = LARGE;
            dist[i][j][1] = LARGE;
            crossed[i][j] = 0;
        }
    }
    int sx = start.first;
    int sy = start.second;
    dist[sy][sx][0] = 0;
    queue<pair<pair<int,int>,int>> q;
    q.push(mp(sx,sy,0));
    while (!q.empty()) {
        pair<pair<int,int>,int> p = q.front();
        int cx = p.first.first, cy = p.first.second;
        int cc = p.second;
        int d = dist[cy][cx][cc];
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cx+mx[i];
            int ny = cy+my[i];
            int nc = cc;
            if (!inbounds(nx,ny)) continue;
            if (arr[ny][nx] == 'X') continue;
            if (cy < point.second && ny == point.second && nx < point.first) continue;
            if (cy == point.second && ny < point.second && cx < point.first) {
                nc++;
                if (nc > 1) continue;
            }
            if (d + 1  < dist[ny][nx][nc]) {
                dist[ny][nx][nc] = d+1;
                q.push(mp(nx,ny,nc));
            }
        }
    }
    return dist[start.second][start.first][1];
}

int main() {
    cin >> R >> C;
    point.first = LARGE;
    point.second = LARGE;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == '*') {
                start.first = j;
                start.second = i;
            }
            else if (arr[i][j] == 'X') {
                if (point.second == LARGE) {
                    point.first = j;
                    point.second = i;
                }
            }
        }
    }
    cout << circumnavigate() << endl;
    //cout << point.first << " " << point.second << endl;
    
    return 0;
}