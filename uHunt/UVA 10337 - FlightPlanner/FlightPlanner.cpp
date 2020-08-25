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

int dr[3] = {-1,0,1};
int dc[3] = {-1,-1,-1};
int cost[3] = {20,30,60};
int N;

bool inbounds(int r, int c) {
	return (r >= 0 && r < 10 && c >= 0 && c < N);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		N /= 100;
		int arr[10][N];
		int dp[10][N+1];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				dp[i][j] = LARGE;
			}
			dp[i][N] = LARGE;
		}
		dp[9][0] = 0;
		for (int c = 1; c <= N; c++) {
			for (int r = 0; r < 10; r++) {
				for (int i = 0; i < 3; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (!inbounds(nr,nc)) continue;
					if (dp[nr][nc] == LARGE) continue;
					dp[r][c] = min(dp[r][c],dp[nr][nc] + cost[i] - arr[nr][nc]);
				}
			}
		}
		/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= N; j++) {
				cout << dp[i][j] <<  " ";
			}
			cout << endl;
		}*/
		cout << dp[9][N] << endl << endl;
	}
    return 0;
}
