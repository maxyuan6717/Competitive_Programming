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

int N;
int arr[100][100];
int cnt[100][100];
bool vis[100][100];
vii from[100][100];
int dr[2] = {-1,-1};
int dc[2] = {1,-1};
int sr,sc;
stack<pii> s;

bool inbounds(int r, int c) {
	return (r >= 0 && r < N && c >= 0 && c < N);
}

void dfs(int r, int c) {
	vis[r][c] = 1;
	for (int i = 0; i < 2; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (arr[nr][nc]) {
			from[nr][nc].push_back(mp(r,c));
			if (!vis[nr][nc]) {
				vis[nr][nc] = 1;
				dfs(nr,nc);
			}
		}
		else {
			nr = nr + dr[i];
			nc = nc + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (!arr[nr][nc]) continue;
			from[nr][nc].push_back(mp(r,c));
			if (!vis[nr][nc]) {
				vis[nr][nc] = 1;
				dfs(nr,nc);
			}
		}
	}
	s.push(mp(r,c));
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				char c;
				cin >> c;
				cnt[i][j] = 0;
				vis[i][j] = 0;
				from[i][j].clear();
				if (c == '.') arr[i][j] = 1;
				else if (c == 'W') {
					sr = i;
					sc = j;
					arr[i][j] = 1;
				}
				else {
					arr[i][j] = 0;
				}
			}
		}
		cnt[sr][sc] = 1;
		dfs(sr,sc);
		s.pop();
		int ans = 0;
		while (!s.empty()) {
			int r = s.top().first, c = s.top().second;
			s.pop();
			for (int i = 0; i < from[r][c].size(); i++) {
				int a = from[r][c][i].first, b = from[r][c][i].second;
				cnt[r][c] = (cnt[r][c] + cnt[a][b]) % 1000007;
			}
			//cout << r << " " << c << " " << cnt[r][c] << endl;
			if (r == 0) ans = (ans + cnt[r][c])%1000007;
		}
		cout << "Case " << t << ": " << ans << endl;
	}
    return 0;
}
