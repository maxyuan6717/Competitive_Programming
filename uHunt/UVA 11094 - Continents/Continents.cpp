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

using namespace std;

int M,N;
char in[20][20];
int arr[20][20];
int color[20][20];
int sy,sx;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int area = 0;

bool inbounds(int r, int c) {
	return (r >= 0 && r < M && c >= 0 && c < N);
}

void flood(int cr, int cc, int key) {
	color[cr][cc] = key;
	area++;
	for (int i = 0; i < 4; i++) {
		int nr = cr + dy[i];
		int nc = (N + cc + dx[i])%N;
		if (!inbounds(nr,nc) || color[nr][nc] || !arr[nr][nc]) continue;
		flood(nr,nc,key);
	}
}

int main() {
	while (cin >> M >> N) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> in[i][j];
			}
		}
		cin >> sy >> sx;
		char land = in[sy][sx];
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = (in[i][j] == land);
				color[i][j] = 0;
			}
		}
		flood(sy,sx,1);
		int ans = 0;
		int colorKey = 2;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!arr[i][j] || color[i][j]) continue;
				area = 0;
				flood(i,j,colorKey);
				colorKey++;
				ans = max(ans,area);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
