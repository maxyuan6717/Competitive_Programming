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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,O,o[14][6],cost[14];
int dp[11][11][11][11][11][11];

int main() {
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			cin >> cost[i];
			for (int j = 0; j < 6; j++) o[i][j] = 0;
			o[i][i] = 1;
		}
		cin >> M;
		for (int i = N; i < N+M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> o[i][j];
			}
			for (int j = N; j < 6; j++) o[i][j] = 0;
			cin >> cost[i];
		}
		N += M;
		memset(dp,-1,sizeof(dp));
		dp[0][0][0][0][0][0] = 0;
		for (int c = 0; c < N; c++) {
			for (int i = o[c][0]; i <= 10; i++) {
				for (int j = o[c][1]; j <= 10; j++) {
					for (int k = o[c][2]; k <= 10; k++) {
						for (int l = o[c][3]; l <= 10; l++) {
							for (int m = o[c][4]; m <= 10; m++) {
								for (int n = o[c][5]; n <= 10; n++) {
									if (dp[i-o[c][0]][j-o[c][1]][k-o[c][2]][l-o[c][3]][m-o[c][4]][n-o[c][5]] != -1) {
										if (dp[i][j][k][l][m][n] == -1) dp[i][j][k][l][m][n] = LARGE;
										dp[i][j][k][l][m][n] = min(dp[i][j][k][l][m][n],dp[i-o[c][0]][j-o[c][1]][k-o[c][2]][l-o[c][3]][m-o[c][4]][n-o[c][5]] + cost[c]);
									}
								}
							}
						}
					}
				}
			}
		}
		cin >> O;
		for (int i = 0; i < O; i++) {
			for (int j = 0; j < N-M; j++) cin >> o[i][j];
			for (int j = N-M; j < 6; j++) o[i][j] = 0;
			cout << dp[o[i][0]][o[i][1]][o[i][2]][o[i][3]][o[i][4]][o[i][5]] << endl;
		}
	}
    return 0;
}
