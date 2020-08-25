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

int arr[10][15], color[3] = {'R','G','B'}, cnt;
int used[10][15];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int R,C;

void reset() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			used[i][j] = 0;
		}
	}
}

void init() {
	reset();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;
			if (c == 'R') arr[i][j] = 0;
			if (c == 'G') arr[i][j] = 1;
			if (c == 'B') arr[i][j] = 2;
		}
	}
}

bool inbounds(int r, int c) {
	return (r >= 0 && r < 10 && c >= 0 && c < 15);
}

void fill (int r, int c, int val) {
	//cout << r << " " << c << endl;
	used[r][c] = val;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (arr[nr][nc] == arr[r][c] && !used[nr][nc]) fill(nr,nc,val);
	}
}

void remove (int r, int c) {
	int orig = arr[r][c];
	arr[r][c] = -1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc) || arr[nr][nc] == -1) continue;
		if (arr[nr][nc] == orig) remove(nr,nc);
	}
}

void compress() {
	queue<int> col;
	for (int c = 0; c < C; c++) {
		queue<int> q;
		for (int r = 9; r >= 0; r--) {
			if (arr[r][c] != -1) q.push(arr[r][c]);
		}
		int r = 9;
		while (!q.empty()) {
			arr[r--][c] = q.front();
			q.pop();
		}
		for (int i = r; i >= 0; i--) arr[i][c] = -1;
		if (arr[9][c] != -1) col.push(c);
	}
	int c = 0;
	C = col.size();
	while (!col.empty()) {
		if (c == col.front()) {
			c++;
			col.pop();
			continue;
		}
		for (int i = 0; i < 10; i++) {
			arr[i][c] = arr[i][col.front()];
			arr[i][col.front()] = -1;
		}
		c++;
		col.pop();
	}
}

int pnts(int x) {
	return pow(x-2,2);
}

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	//freopen ("out","w",stdout);
	for (int t = 1; t <= T; t++) {
		R = 10, C = 15;
		init();
		if (t > 1) cout << endl;
		cout << "Game " << t << ":" << endl << endl;
		int total = 0;
		int move = 1;
		int remaining = 150;
		while (1) {
			int val = 1;
			int bi,bj;
			int maxCnt = 0;
			reset();
			for (int j = 0; j < C; j++) {
				for (int i = R-1; i >= 0; i--) {
					if (!used[i][j] && arr[i][j] != -1) {
						cnt = 0;
						fill(i,j,val++);
						if (cnt >= 2 && cnt > maxCnt) {
							maxCnt = cnt;
							bi = i, bj = j;
						}
					}
				}
			}
			if (!maxCnt) break;
			int points = pnts(maxCnt);
			remaining -= maxCnt;
			total += points;
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", move++, 10-bi, bj+1, maxCnt, color[arr[bi][bj]], points);
			remove(bi,bj);
			compress();
			//print();
		}
		if (!remaining) total += 1000;
		printf("Final score: %d, with %d balls remaining.\n", total, remaining);
	}
    return 0;
}
