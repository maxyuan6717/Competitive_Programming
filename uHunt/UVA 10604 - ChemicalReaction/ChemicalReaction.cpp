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
#define fi first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int dp[11][11][11][11][11][11];
bool vis[11][11][11][11][11][11];
pii arr[6][6];
int cnt[6];
int N,M;

int rec(int a, int b, int c, int d, int e, int f) {
	if (vis[a][b][c][d][e][f]) return dp[a][b][c][d][e][f];
	int ret = LARGE;
	int temp[6] = {a,b,c,d,e,f};
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j && temp[i] < 2) continue;
			if (temp[i] && temp[j]) {
				temp[i]--;temp[j]--;temp[arr[i][j].fi]++;
				int pos = rec(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]);
				if (pos != LARGE) ret = min(ret, pos + arr[i][j].s);
				temp[i]++;temp[j]++;temp[arr[i][j].fi]--;
			}
		}
	}
	vis[a][b][c][d][e][f] = 1;
	if (ret == LARGE) ret = 0;
	return dp[a][b][c][d][e][f] = ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j].fi >> arr[i][j].s;
				arr[i][j].fi--;
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int chem;
			cin >> chem;
			cnt[chem-1]++;
		}
		char useless;
		cin >> useless;
		cout << rec(cnt[0],cnt[1],cnt[2],cnt[3],cnt[4],cnt[5]) << endl;
	}
    return 0;
}
