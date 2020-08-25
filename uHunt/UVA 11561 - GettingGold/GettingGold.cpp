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

int R,C,sr,sc;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
char arr[50][50];
bool vis[50][50];
int ans;

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

bool trap(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (inbounds(nr,nc) && arr[nr][nc] == 'T') return 1;
	}
	return 0;
}

void rec(int r, int c) {
	if (arr[r][c] == 'G') ans++;
	//cout << r << " " << c << " " << ans << endl;
	if (trap(r,c)) return;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc) || arr[nr][nc] == '#' || vis[nr][nc]) continue;
		vis[nr][nc] = 1;
		rec(nr,nc);
	}
}

int main() {
	while (cin >> C >> R) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'P') {
					sr = i, sc = j;
				}
				vis[i][j] = 0;
			}
		}
		ans = 0;
		vis[sr][sc] = 1;
		rec(sr,sc);
		cout << ans << endl;
	}
    return 0;
}
