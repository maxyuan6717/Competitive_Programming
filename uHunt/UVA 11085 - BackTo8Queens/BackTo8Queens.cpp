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

using namespace std;

int t;
int mr,mc;
int indx[9];
int start[9];
int counter = 1;
int ans = 20;

bool check(int r, int c) {
	//HORIZONTAL
	for (int i = 1; i <= 8; i++) {
		if (i != c && indx[i] == r) return 0;
	}
	//DIAGONAL
	for (int i = 1; i <= 8; i++) {
		int nr = r + (i-c);
		if (nr >= 1 && nr <= 8) {
			if (i != c && indx[i] == nr) return 0;
		}
		nr = r + (c-i);
		if (nr >= 1 && nr <= 8) {
			if (i != c && indx[i] == nr) return 0;
		}
	}
	return 1;
}

void solve(int cur) {
	//cout << cur << endl;
	if (cur == 9) {
		int cnt = 0;
		for (int i = 1; i <= 8; i++) {
			//cout << indx[i] << " ";
			if (start[i] != indx[i]) cnt++;
		}
		ans = min(ans,cnt);
		//cout << endl;
		//cout << cnt << endl;
		return;
	}
	for (int i = 1; i <= 8; i++) {
		if (!check(i,cur)) continue;
		indx[cur] = i;
		//cout << i << " " << cur << endl;
		solve(cur+1);
		//indx[cur] = 0;
	}
	indx[cur] = 0;
}

int main() {
	int caseNum = 1;
	while (cin >> start[1]) {
		for (int i = 2; i <= 8; i++) cin >> start[i];
    	for (int i = 1; i <= 8; i++) indx[i] = 0;
    	ans = 10;
    	solve(1);
    	cout << "Case " << caseNum++ << ": " << ans << endl;
    }
    return 0;
}
