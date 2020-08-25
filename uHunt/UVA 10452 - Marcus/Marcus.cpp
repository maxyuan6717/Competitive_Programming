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
char arr[8][8];
int dr[3] = {0,-1,0};
int dc[3] = {-1,0,1};
string str = "IEHOVA";
int sr,sc;

bool inbounds(int r, int c) {
	return (r >= 0 && r < N && c >= 0 && c < M);
}

void rec(int r, int c, int indx) {
	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (indx == 6) {
			if (arr[nr][nc] != '#') continue;
			if (i == 0) cout << "left" << endl;
			else if (i == 1) cout << "forth" << endl;
			else if (i == 2) cout << "right" << endl;
			return;
		}
		if (arr[nr][nc] != str[indx]) continue;
		if (i == 0) cout << "left" << " ";
		else if (i == 1) cout << "forth" << " ";
		else if (i == 2) cout << "right" << " ";
		rec(nr,nc,indx+1);
		break;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') sr = i, sc = j;
			}
		}
		rec(sr,sc,0);
	}
    return 0;
}
