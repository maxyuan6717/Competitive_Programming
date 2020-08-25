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

int board,ans,cnt;
bool vis[1<<12];
char num;

bool inbounds(int x) {
	return (x >= 0 && x < 12);
}

void rec(int used, int left) {
	if (vis[used]) return;
	vis[used] = 1;
	//cout << used << " " << left << endl;
	ans = min(ans,left);
	for (int i = 0; i < 12; i++) {
		if (!(used&(1<<i))) continue;
		for (int j = -1; j <= 1; j+=2) {
			int ni = i + j;
			if (!inbounds(ni)) continue;
			if (!inbounds(ni+j)) continue;
			if (!(used&(1<<ni)) || used&(1<<(ni+j))) continue;
			int nUsed = used;
			nUsed ^= (1<<i);
			nUsed ^= (1<<ni);
			nUsed ^= (1<<(ni+j));
			rec(nUsed,left-1);
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(vis,0,sizeof(vis));
		board = cnt = 0, ans = LARGE;
		for (int i = 0; i < 12; i++) {
			cin >> num;
			if (num == 'o') {
				board |= (1<<i);
				cnt++;
			}
		}
		rec(board,cnt);
		cout << ans << endl;
	}
    return 0;
}
