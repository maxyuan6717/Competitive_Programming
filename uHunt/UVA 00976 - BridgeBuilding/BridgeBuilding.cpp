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

#define LARGE 1e9
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int R,C,B,S;
int arr[1000][1000];
int memo[1000][100];
int dis[1000];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

void flood (int r, int c, int color) {
	arr[r][c] = color;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (arr[nr][nc] == 0 || arr[nr][nc] > 1) continue;
		flood(nr,nc,color);
	}
}

int dp(int c, int b) {
	if (c >= C) {
		if (b == B) return 0;
		else return LARGE;
	}
	if (b > B) return LARGE;
	if (b == B) return 0;
	if (memo[c][b] != -1) return memo[c][b];
	int ret = LARGE;
	ret = min(ret,dis[c] + dp(c+S+1,b+1));
	ret = min(ret,dp(c+1,b));
	return memo[c][b] = ret;
}

int main() {
	while (cin >> R >> C >> B >> S) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char ch;
				cin >> ch;
				arr[i][j] = ch == '#';
			}
		}
		flood(0,0,2);
		flood(R-1,0,3);
		for (int i = 0; i < C; i++) {
			int t = 0,b = R-1;
			for (int j = 0; j < R; j++) {
				if (arr[j][i] == 2) t=j;
			}
			for (int j = R-1; j >= 0; j--) {
				if (arr[j][i] == 3) b = j;
			}
			t++,b--;
			dis[i] = b-t+1;
		}
		memset(memo,-1,sizeof(memo));
		cout << dp(0,0) << endl;
	}
    return 0;
}
