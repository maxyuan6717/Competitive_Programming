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

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
			if (j != N-1) cout << " ";
		}
		cout << endl;
	}
}

bool check(int nr, int nc, int val) {
	if (h[nr][val]) return 0;
	for (int i = 0; i < N; i++) {
		if (arr[nr][i] == val) return 0;
	}
	if (v[nc][val]) return 0;
	int sr = nr/M;
	int sc = nc/M;
	if (s[sr][sc][val]) return 0;
	return 1;
}

bool rec() {
	if (!find()) {
		print();
		return 1;
	}
	int cr = r, cc = c;
	for (int i = 1; i <= N; i++) {
		if (check(cr,cc,i)) {
			//cout << r << " " << c << " " << i << endl;
			//cout << h[r][i] << endl;
			arr[cr][cc] = i;
			h[cr][i] = 1;
			v[cc][i] = 1;
			int sr = cr/M;
			int sc = cc/M;
			s[sr][sc][i] = 1;
			if (rec()) return 1;
			arr[cr][cc] = 0;
			h[cr][i] = 0;
			v[cc][i] = 0;
			s[sr][sc][i] = 0;
		}
	}
	return 0;
}

int main() {
	int caseNum = 0;
	while (cin >> M) {
		if (caseNum++) cout << endl;
		N = M*M;
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(s,0,sizeof(s));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
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
		if (!rec()) cout << "NO SOLUTION" << endl;
	}
    return 0;
}
