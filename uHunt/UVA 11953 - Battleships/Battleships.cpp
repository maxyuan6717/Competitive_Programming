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

int N;
char arr[100][100];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

bool inbounds(int r, int c) {
	return (r >= 0 && r < N && c >= 0 && c < N);
}

void flood(int cr, int cc) {
	arr[cr][cc] = '.';
	for (int i = 0; i < 4; i++) {
		int nr = cr+dr[i];
		int nc = cc+dc[i];
		if (!inbounds(nr,nc)) continue;
		if (arr[nr][nc] == '.') continue;
		flood(nr,nc);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 'x') {
					ans++;
					flood(i,j);
				}
			}
		}
		cout << "Case " << t << ": " << ans << endl;
	}
    
    return 0;
}
