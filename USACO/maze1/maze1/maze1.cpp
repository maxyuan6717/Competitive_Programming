#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

char maze[100*2+5][38*2+5];
int dist[2][105][42];
int start[2][2];
int W,H;
int exit1[2][2];
int counter = 0;
int total = 0;
int ans=0;
const int xx[] = {1,0,-1,0};
const int yy[] = {0,1,0,-1};
bool check(int x, int y) {
    return (x>0 && y > 0 && x < H*2 && y < W*2);
}
void flood(int total, int x, int y) {
    if (total < dist[counter][x/2][y/2]) {
        dist[counter][x/2][y/2] = total;
    }
    else {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (check(nx+xx[i],ny+yy[i]) && maze[nx][ny] == ' ') {
            nx += xx[i];
            ny += yy[i];
            flood(total+1, nx, ny);
        }
    }
}
int main() {
    cin >> W >> H;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                dist[i][j][k] = 5000;
            }
        }
    }
    string str;
    getline(cin,str);
    for (int i = 0; i < H*2+1; i++) {
        getline(cin,str);
        for (int j = 0; j < W*2+1; j++) {
            maze[i][j] = str[j];
            if ((j == 0 || j == W*2 || i == 0 || i == H*2) && str[j] == ' ') {
                if (counter == 0) {
                    exit1[0][0] = i;
                    exit1[0][1] = j;
                    counter++;
                }
                else {
                    exit1[1][0] = i;
                    exit1[1][1] = j;
                }
            }
        }
    }
    counter = 0;
    for (counter = 0; counter < 2; counter++) {
        total = 0;
        
        if (exit1[counter][0] == 0) {
            start[counter][0] = (exit1[counter][0]+1);
            start[counter][1] = (exit1[counter][1]);
        }
        else if (exit1[counter][0] == H*2) {
            start[counter][0] = (exit1[counter][0])-1;
            start[counter][1] = (exit1[counter][1]);
        }
        else if (exit1[counter][1] == 0) {
            start[counter][0] = (exit1[counter][0]);
            start[counter][1] = (exit1[counter][1])+1;
        }
        else if (exit1[counter][1] == W*2) {
            start[counter][0] = (exit1[counter][0]);
            start[counter][1] = (exit1[counter][1])-1;
        }
        
    }
    counter = 0;
    flood(1, start[0][0],start[0][1]);
    counter = 1;
    flood(1, start[1][0],start[1][1]);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[1][i][j] >= dist[0][i][j] && dist[0][i][j] > ans) {
                ans = dist[0][i][j];
            }
            if (dist[0][i][j] > dist[1][i][j] && dist[1][i][j] > ans) {
                ans = dist[1][i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}