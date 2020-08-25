#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int R,C,arr[100][100],stop;
int startr,startc,ansr,ansc;
int dr[4] = {1,0,0,-1};
int dc[4] = {0,-1,1,0};
bool vis[100][100];

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

void rec(int r, int c) {
	if (r == R-1) {
		ansr = r, ansc = min(ansc,c);
		return;
	}
	int cur = arr[r][c];
	int nxt = arr[r][c] + 1;
	bool changed = 0;
	if (cur == stop) {
		nxt = 1;
		changed = 1;
		stop++;
	}
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc) || vis[nr][nc] || arr[nr][nc] != nxt) continue;
		vis[nr][nc] = 1;
		rec(nr,nc);
		vis[nr][nc] = 0;
	}
	if (changed) stop--;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t) cout << endl;
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < C; i++) {
			stop = 1;
			if (arr[0][i] == 1) {
				ansr = ansc = 10000;
				memset(vis,0,sizeof(vis));
				startr = 0, startc = i;
				vis[0][i] = 1;
				rec(0,i);
				if (ansc != 10000) break;
			}
		}
		cout << startr + 1 << " " << startc + 1 << endl << ansr+1 << " " << ansc+1 << endl;
	}
    return 0;
}
