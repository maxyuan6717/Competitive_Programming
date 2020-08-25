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
#include <bitset>
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct point {
	int l,r,c,time;
};

int L,R,C;
int maze[30][30][30];
int vis[30][30][30];
int dl[6] = {0,0,0,0,1,-1};
int dr[6] = {0,0,1,-1,0,0};
int dc[6] = {1,-1,0,0,0,0};

int sl,sr,sc;
int el,er,ec;

bool inbounds(int l, int r, int c) {
	return (l >= 0 && l < L && r >= 0 && r < R && c >= 0 && c < C);
}

int bfs() {
	queue<point> q;
	point start = {sl,sr,sc,0};
	vis[sl][sr][sc] = 1;
	q.push(start);
	while (!q.empty()) {
		point u = q.front();
		q.pop();
		if (u.l == el && u.r == er && u.c == ec) return u.time;
		for (int i = 0; i < 6; i++) {
			int nl = u.l + dl[i];
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nl,nr,nc)) continue;
			if (!maze[nl][nr][nc]) continue;
			if (vis[nl][nr][nc]) continue;
			vis[nl][nr][nc] = 1;
			point v = {nl,nr,nc,u.time+1};
			q.push(v);
		}
	}
	return -1;
}

int main() {
    cin >> L >> R >> C;
    while (L || R || C) {
    	for (int i = 0; i < L; i++) {
    		for (int j = 0; j < R; j++) {
    			for (int k = 0; k < C; k++) {
    				vis[i][j][k] = 0;
    				char c;
    				cin >> c;
    				if (c == '#') maze[i][j][k] = 0;
    				else if (c == '.') maze[i][j][k] = 1;
    				else if (c == 'S') {
    					maze[i][j][k] = 1;
    					sl = i, sr = j, sc = k;
    				}
    				else {
    					maze[i][j][k] = 1;
    					el = i, er = j, ec = k;
    				}
    			}
    		}
    	}
    	int ans = bfs();
    	if (ans == -1) cout << "Trapped!" << endl;
    	else cout << "Escaped in " << ans << " minute(s)." << endl;
    	cin >> L >> R >> C;
    }
    return 0;
}
