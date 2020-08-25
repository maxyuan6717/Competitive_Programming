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

struct point {
	int r,c,d;
};

bool operator < (point a, point b) {
	return a.d > b.d;
}

int N,M;
int arr[1000][1000];
int dis[1000][1000];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool inbounds(int r, int c) {
	return (r >= 0 && r < N && c >= 0 && c < M);
}

int dijkstra() {
	dis[0][0] = arr[0][0];
	priority_queue<point> pq;
	point start = {0,0,arr[0][0]};
	pq.push(start);
	while (!pq.empty()) {
		point u = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dr[i];
			int nc = u.c + dc[i];
			if (!inbounds(nr,nc)) continue;
			if (u.d + arr[nr][nc] < dis[nr][nc]) {
				dis[nr][nc] = u.d + arr[nr][nc];
				point v = {nr,nc,dis[nr][nc]};
				pq.push(v);
			}
		}
	}
	return dis[N-1][M-1];
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				dis[i][j] = LARGE;
			}
		}
		cout << dijkstra() << endl;
	}
    return 0;
}
