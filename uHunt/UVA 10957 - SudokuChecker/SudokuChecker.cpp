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

int N,M;
int arr[9][9];
bool h[9][10];
bool v[9][10];
bool s[3][3][10];
int r,c;
int ans = 0;

bool find() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!arr[i][j]) {
				r = i, c = j;
				return 1;
			}
		}
	}
	return 0;
}

bool check(int nr, int nc, int val) {
	if (h[nr][val]) return 0;
	if (v[nc][val]) return 0;
	int sr = nr/M;
	int sc = nc/M;
	if (s[sr][sc][val]) return 0;
	return 1;
}

void rec() {
	if (ans > 2) return;
	if (!find()) {
		ans++;
		return;
	}
	int cr = r, cc = c;
	for (int i = 1; i <= N; i++) {
		if (check(cr,cc,i)) {
			//cout << cr << " " << cc << " " << i << endl;
			arr[cr][cc] = i;
			h[cr][i] = 1;
			v[cc][i] = 1;
			int sr = cr/M;
			int sc = cc/M;
			s[sr][sc][i] = 1;
			rec();
			arr[cr][cc] = 0;
			h[cr][i] = 0;
			v[cc][i] = 0;
			s[sr][sc][i] = 0;
		}
	}
	return;
}

bool legal() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			//cout << arr[i][j] << " ";
			if (arr[i][j]) {
				for (int k = 0; k < 9; k++) {
					if (k != j && arr[i][k] == arr[i][j]) return 0;
					if (k != i && arr[k][j] == arr[i][j]) return 0;
				}
				int sr = 3*(i/M);
				int sc = 3*(j/M);
				for (int k = sr; k < sr + 3; k++) {
					for (int l = sc; l < sc+3; l++) {
						if (k == i && l == j) continue;
						if (arr[k][l] == arr[i][j]) return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main() {
	M = 3, N = 9;
	int caseNum = 1;
	while (cin >> arr[0][0]) {
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(s,0,sizeof(s));
		ans  = 0;
		if (arr[0][0]) {
			h[0][arr[0][0]] = 1;
			v[0][arr[0][0]] = 1;
			int sr = 0;
			int sc = 0;
			s[sr][sc][arr[0][0]] = 1;
		}
		for (int i = 1; i < 9; i++) {
			cin >> arr[0][i];
			if (arr[0][i]) {
				h[0][arr[0][i]] = 1;
				v[i][arr[0][i]] = 1;
				int sr = 0/M;
				int sc = i/M;
				s[sr][sc][arr[0][i]] = 1;
			}
		}
		for (int i = 1; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
				if (arr[i][j]) {
					h[i][arr[i][j]] = 1;
					v[j][arr[i][j]] = 1;
					int sr = i/M;
					int sc = j/M;
					s[sr][sc][arr[i][j]] = 1;
				}
			}
		}
		cout << "Case " << caseNum++ << ": ";
		if (!legal()) {
			cout << "Illegal." << endl;
			continue;
		}
		rec();
		if (!ans) cout << "Impossible." << endl;
		else if (ans == 1) cout << "Unique." << endl;
		else cout << "Ambiguous." << endl;
	}
    return 0;
}
