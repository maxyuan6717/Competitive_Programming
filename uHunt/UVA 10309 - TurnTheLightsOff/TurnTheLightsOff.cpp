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

string name;
bool arr[10][10];
int dr[5] = {0,0,0,1,-1};
int dc[5] = {0,1,-1,0,0};
int ans;
char c;
int cnt;

bool inbounds(int r, int c) {
	return (r >= 0 && r < 10 && c >= 0 && c < 10);
}

void toggle(int r, int c) {
	for (int i = 0; i < 5; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		arr[nr][nc] = !arr[nr][nc];
	}
}

void rec(int len, int r, int col) {
	if (col == 10) {
		r++;
		col = 0;
	}
	if (len >= ans) return;
	if (!r) {
		rec(len,r,col+1);
		toggle(r,col);
		rec(len+1,r,col+1);
		toggle(r,col);
	}
	else if (r == 10) {
		for (int i = 0; i < 10; i++) {
			if (arr[r-1][i]) return;
		}
		ans = min(ans,len);
	}
	else {
		if (arr[r-1][col]) {
			toggle(r,col);
			rec(len+1,r,col+1);
			toggle(r,col);
		}
		else rec(len,r,col+1);
	}
}

int main() {
	while (getline(cin,name), name != "end") {
		cnt = 10;
		ans = LARGE;
		string s;
		for (int i = 0; i < 10; i++) {
			getline(cin,s);
			for (int j = 0; j < 10; j++) {
				arr[i][j] = (s[j] == 'O');
			}
		}
		rec(0,0,0);
		if (ans == LARGE) ans = -1;
		cout << name << " " << ans << endl;
	}
    return 0;
}
