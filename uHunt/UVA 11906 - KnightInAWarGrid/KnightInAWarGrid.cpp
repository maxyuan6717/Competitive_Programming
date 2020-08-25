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

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

int R,C,M,N,W;

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ": ";
		cin >> R >> C >> M >> N >> W;
		int bad[R][C];
		int visited[R][C];
		int counter[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				visited[i][j] = 0;
				bad[i][j] = 0;
				counter[i][j] = 0;
			}
		}
		for (int w = 0; w < W; w++) {
			int x,y;
			cin >> x >> y;
			bad[x][y] = 1;
		}
		int dx[8] = {N,N,-N,-N,M,M,-M,-M};
		int dy[8] = {M,-M,M,-M,N,-N,N,-N};
		queue<pii> q;
		q.push(mp(0,0));
		visited[0][0] = 1;
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			set<pii> unique;
			for (int i = 0; i < 8; i++) {
				int nr = r + dy[i];
				int nc = c + dx[i];
				if (inbounds(nr,nc) && !bad[nr][nc]) unique.insert(mp(nr,nc));
			}
			set<pii>::iterator it;
			for (it = unique.begin(); it != unique.end(); it++) {
				int nr = it->first;
				int nc = it->second;
				counter[nr][nc]++;
				if (!visited[nr][nc]) {
					q.push(mp(nr,nc));
					visited[nr][nc] = 1;
				}
			}
		}
		int odd = 0, even = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (bad[i][j] || !visited[i][j]) continue;
				if (counter[i][j]%2) odd++;
				else even++;
			}
		}
		cout << even << " " << odd << endl;
	}
    return 0;
}
