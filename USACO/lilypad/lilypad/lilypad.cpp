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

#define LARGE 9999999

using namespace std;

int M,N;
int arr[31][31];
int visited[31][31];

int start[2];
int dest[2];

int mx[8] = {-1,1,-2,2,-2,2,-1,1};
int my[8] = {2,2,1,1,-1,-1,-2,-2};

int ans1 = LARGE;
int ans2 = LARGE;
long long ans3 = 0;

int inbounds(int y, int x) {
    if (y >= 0 && y < M && x >= 0 && x < N) return 1;
    return 0;
}

struct point {
    int x,y;
};

struct best {
    int pads = LARGE;
    int jumps = LARGE;
    long long ways = 1;
    bool visited = 0;
};

best points[31][31];

void bfs() {
    queue< point > q;
    point p;
    p.y = start[0];
    p.x = start[1];
    points[p.y][p.x].visited = 1;
    points[p.y][p.x].pads = 0;
    points[p.y][p.x].jumps = 0;
    q.push(p);
    while (!q.empty()) {
        point a = q.front();
        q.pop();
        int py = a.y;
        int px = a.x;
        points[py][px].visited = 0;
        //cout << py << " " << px << " " << points[py][px].pads << endl;
        for (int i = 0; i < 8; i++) {
            int nx = px+mx[i];
            int ny = py+my[i];
            if (inbounds(ny,nx) && (arr[ny][nx] == 1 || arr[ny][nx] == 4)) {
                if (points[py][px].pads < points[ny][nx].pads) {
                    points[ny][nx].pads = points[py][px].pads;
                    points[ny][nx].ways = points[py][px].ways;
                    points[ny][nx].jumps = points[py][px].jumps+1;
                    if (!points[ny][nx].visited) {
                        points[ny][nx].visited = 1;
                        point n;
                        n.y = ny;
                        n.x = nx;
                        q.push(n);
                    }
                }
                else if (points[py][px].pads == points[ny][nx].pads) {
                    points[ny][nx].ways+=points[py][px].ways;
                    if (!points[ny][nx].visited) {
                        points[ny][nx].visited = 1;
                        point n;
                        n.y = ny;
                        n.x = nx;
                        q.push(n);
                    }
                }
            }
            else if (inbounds(ny,nx) && arr[ny][nx] == 0) {
                //if (py == 4 && px == 8 && points[py][px].pads == 2) cout << ny << " " << nx << " " << points[ny][nx].pads << endl;
                if (points[py][px].pads +1 < points[ny][nx].pads) {
                    points[ny][nx].pads = points[py][px].pads + 1;
                    points[ny][nx].ways = points[py][px].ways;
                    points[ny][nx].jumps = points[py][px].jumps+1;
                    if (!points[ny][nx].visited) {
                        points[ny][nx].visited = 1;
                        point n;
                        n.y = ny;
                        n.x = nx;
                        q.push(n);
                    }
                    
                }
                //if (py == 4 && px == 8 && points[py][px].pads == 2) cout << ny << " " << nx << " " << points[ny][nx].pads << endl;
                else if (points[py][px].pads + 1 == points[ny][nx].pads) {
                    points[ny][nx].ways+=points[py][px].ways;
                    if (!points[ny][nx].visited) {
                        points[ny][nx].visited = 1;
                        point n;
                        n.y = ny;
                        n.x = nx;
                        q.push(n);
                    }
                    
                }
            }
        }
    }
    int dy = dest[0];
    int dx = dest[1];
    if (points[dy][dx].pads != LARGE) {
        ans1 = points[dy][dx].pads;
        ans2 = points[dy][dx].jumps;
        ans3 = points[dy][dx].ways;
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            //cout << i << " " << j << endl;
            visited[i][j] = 0;
            cin >> arr[i][j];
            if (arr[i][j] == 3) {
                start[0] = i;
                start[1] = j;
            }
            else if (arr[i][j] == 4) {
                dest[0] = i;
                dest[1] = j;
            }
        }
    }
    //dfs(start[0],start[1]);
    bfs();
    if (ans1 == LARGE) cout << -1 << endl;
    else {
        cout << ans1 << endl;
        //cout << ans2 << endl;
        cout << ans3 << endl;
    }
    return 0;
}