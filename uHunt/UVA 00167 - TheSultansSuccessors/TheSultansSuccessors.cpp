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

int score[9][9];
int indx[9];
int ans = 0;
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
	if (cur == 9) {
		int sum = 0;
		for (int i = 1; i <= 8; i++) {
			sum += score[indx[i]][i];
		}
		ans = max(ans,sum);
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
	int T;
	scanf("%d",&T);
	for (int t = 0; t < T; t++) {
		for (int i = 1; i <= 8; i++) {
			indx[i] = 0;
			for (int j = 1; j <= 8; j++) {
				scanf("%d",&score[i][j]);
			}
		}
		ans = 0;
		solve(1);
		printf("%5d\n",ans);
	}
    return 0;
}
