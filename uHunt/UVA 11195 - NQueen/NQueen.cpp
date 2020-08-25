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
int caseNum = 1;
//bool bad[16][16];
int bad[16];
int ans = 0;

int LSOne(int x) {
	return x & (-x);
}

void solve(int rw, int ld, int rd,int col) {
	if (rw == (1<<N)-1) {
		ans++;
		return;
	}
	int possible = ((1<<N)-1) & (~(rw|ld|rd) & bad[col]);
	while (possible) {
		int r = LSOne(possible);
		possible -= r;
		solve(rw|r,(ld|r)*2,(rd|r)/2,col+1);
	}
}

int main() {
	cin >> N;
	while (N) {
		for (int i = 0; i <= N; i++) bad[i] = (i<<N)-1;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				char c;
				cin >> c;
				if (c == '*') {
					bad[j] &= ~(1<<i);
				}
			}
		}
		ans = 0;
		solve(0,0,0,1);
		cout << "Case " << caseNum << ": " << ans << endl;
		caseNum++;
		cin >> N;
	}
    return 0;
}
