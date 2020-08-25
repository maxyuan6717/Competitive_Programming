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

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

string name;
int R,C;
int arr[100][100];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int dis[100][100];

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int dfs(int r, int c) {
	if (dis[r][c] != -1) return dis[r][c];
	dis[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (arr[nr][nc] >= arr[r][c]) continue;
		dis[r][c] = max(dis[r][c],dfs(nr,nc) + 1);
	}
	return dis[r][c];
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> name >> R >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> arr[i][j];
				dis[i][j] = -1;
			}
		}
		int ans = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				ans = max(ans,dfs(i,j)+1);
			}
		}
		cout << name << ": " << ans << endl;
	}
    return 0;
}
