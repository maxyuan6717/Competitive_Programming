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

int N;
map<int,map<int,int>> arr;
map<int,map<int,bool>> vis;
int sy = 0,sx = LARGE;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

bool inbounds(int x, int y) {
    return (x >= 0 && y >= 0);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x,y;
        cin >> x >> y;
        y++;
        arr[y][x] = 1;
        if (y > sy || (y == sy && x < sx)) {
            sy = y;
            sx = x;
        }
    }
    int cx = sx;
    int cy = sy;
    int dir = 0;
    int done = 0;
    int ans = 0;
    while (!done) {
        cx += dx[dir];
        cy += dy[dir];
        //cout << cx-10006 << " " << cy-200004 << " " << dir << endl;
        ans++;
        for (int i = (dir+3)%4; (i%4) != (dir+2)%4; i = (i+1)%4) {
            //cout << i << endl;
            if (i == 0 && arr[cy][cx]) {
                dir = 0;
                break;
            }
            else if (i == 1 && arr[cy][cx-1]) {
                dir = 1;
                break;
            }
            else if (i == 2 && arr[cy+1][cx-1]) {
                dir = 2;
                break;
            }
            else if (i == 3 && arr[cy+1][cx]) {
                dir = 3;
                break;
            }
        }
        if (cx == sx && cy == sy) done = 1;
    }
    cout << ans << endl;
    return 0;
}