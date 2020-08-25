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

struct state {
	int r,c,d;
};

int arr[100][100],R,C,P,sr,sc;
int dis[100][100];
bool stop[100][100];
int dr[8] = {0,0,1,0,0,2,2,2};
int dc[8] = {-1,1,0,-2,2,-2,0,2};
vector<state> ans;

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

void bfs() {
	queue<pii> q;
	q.push(mp(sr-1,sc-1));
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		//cout << r << " " << c << endl;
		q.pop();
		if (dis[r][c] == 0) {
			for (int i = 0; i < 3; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (!inbounds(nr,nc) || arr[nr][nc] || dis[nr][nc]) continue;
				dis[nr][nc] = dis[r][c] + 1;
				state add = {nr,nc,dis[nr][nc]};
				ans.push_back(add);
			}
		}
		for (int i = 3; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			//cout << nr << " " << nc << endl;
			if (!inbounds(nr,nc) || arr[nr][nc] || dis[nr][nc] || !arr[r+dr[i]/2][c+dc[i]/2]) continue;
			dis[nr][nc] = dis[r][c] + 1;
			state add = {nr,nc,dis[nr][nc]};
			ans.push_back(add);
			q.push(mp(nr,nc));
		}
	}
}

bool comp(state a, state b) {
	if (a.r != b.r) return a.r > b.r;
	return a.c < b.c;
}

int main() {
	int caseNum = 0;
	while (cin >> R >> C) {
		if (caseNum++) cout << endl;
		ans.clear();
		P = 2*C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				dis[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < 2*P; i++) {
			int r,c;
			cin >> r >> c;
			arr[r-1][c-1] = 1;
		}
		cin >> sr >> sc;
		bfs();
		sort(ans.begin(),ans.end(),comp);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].r+1 << " " << ans[i].c+1 << " " << ans[i].d << endl;
		}
	}
    return 0;
}
