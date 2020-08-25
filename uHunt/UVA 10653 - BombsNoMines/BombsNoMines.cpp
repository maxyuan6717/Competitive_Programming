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

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

struct point {
	int r,c,d;
};

int R,C;
int arr[1000][1000];
bool vis[1000][1000];
int sr,sc,er,ec;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int bfs() {
	queue<point> q;
	vis[sr][sc] = 1;
	point start = {sr,sc,0};
	q.push(start);
	while(!q.empty()) {
		point u = q.front();
		q.pop();
		if (u.r == er && u.c == ec) {
			return u.d;
		}
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (vis[nr][nc] || !arr[nr][nc]) continue;
			vis[nr][nc] = 1;
			point v = {nr,nc,u.d+1};
			q.push(v);
		}
	}
	return -1;
}

int main() {
	cin >> R >> C;
	while (R || C) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				arr[i][j] = 1;
				vis[i][j] = 0;
			}
		}
		int B;
		cin >> B;
		for (int i = 0; i < B; i++) {
			int r,n;
			cin >> r >> n;
			for (int j = 0; j < n; j++) {
				int num;
				cin >> num;
				arr[r][num] = 0;
			}
		}
		cin >> sr >> sc;
		cin >> er >> ec;
		cout << bfs() << endl;
		cin >> R >> C;
	}
    return 0;
}
