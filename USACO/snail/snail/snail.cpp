#include <iostream>
#include <fstream>
#include <sstream>
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

#define LARGE 9999999


using namespace std;

int N,B;
char grid[121][121];
vector<int> barriern[121];
vector<int> barrierl[27];
int visited[121][121];
int ans = 0;
int cur = 0;

int toint(string s) {
    int ret;
    istringstream convert(s);
    convert >> ret;
    return ret;
}
void dfs(int x, int y, int dx, int dy) {
    
    if (visited[y][x]) {
        if (cur > ans) ans = cur;
        return;
    }
    visited[y][x] = 1;
    cur++;
    if (x+dx <= N && x+dx >= 1 && y+dy <= N && y+dy >= 1 && grid[y+dy][x+dx] != '#') {
        dfs(x+dx,y+dy,dx,dy);
    }
    else {
        if (cur > ans) ans = cur;
        int newdx = 1-abs(dx);
        int newdy = 1-abs(dy);
        if (y+newdy <= N && x+newdx <= N && grid[y+newdy][x+newdx] != '#') {
            dfs(x+newdx,y+newdy,newdx,newdy);
        }
        newdx = abs(dx)-1;
        newdy = abs(dy)-1;
        if (y+newdy >= 1 && x+newdx >= 1 && grid[y+newdy][x+newdx] != '#') {
            dfs(x+newdx,y+newdy,newdx,newdy);
        }
    }
    visited[y][x] = 0;
    cur--;
}

int main() {
    cin >> N >> B;
    for (int i = 0; i < B; i++) {
        string s;
        cin >> s;
        int w = s[0]-64;
        s = s.substr(1,s.size()-1);
        int h = toint(s);
        grid[h][w] = '#';
        barriern[h].push_back(w);
        barrierl[w].push_back(h);
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            visited[i][j] = 0;
        }
    }
    int x= 1,y = 1;
    int xdir = 1, ydir = 0;
    dfs(x,y,xdir,ydir);
    x = 1;
    y=1;
    cur = 0;
    xdir = 0;
    ydir = 1;
    visited[y][x] = 0;
    dfs(x,y,xdir,ydir);
    cout << ans << endl;

    return 0;
}