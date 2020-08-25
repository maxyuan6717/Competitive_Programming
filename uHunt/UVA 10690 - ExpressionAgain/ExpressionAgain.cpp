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

int N,M,val[101],tot;
bool dp[101][10001][51];

int main() {
	while (cin >> N >> M) {
		tot = 0;
		for (int i = 1; i <= N+M; i++) {
			cin >> val[i];
			tot += val[i];
		}
		for (int i = 0; i <= N + M; i++) {
			for (int j = 0; j <= 10000; j++) {
				for (int k = 0; k <= N; k++)  {
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][5000][0] = 1;
		for (int i = 1; i <= N + M; i++) {
			int v = val[i];
			for (int j = 0; j <= 10000; j++) {
				for (int k = 0; k <= N; k++) {
					if (j-v < 0 || j-v > 10000) {
						dp[i][j][k] = dp[i-1][j][k];
						continue;
					}
					dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-v][k-1]);
				}
			}
		}
		int ans1 = 0,ans2 = LARGE;
		for (int i = tot/2 + 5000; i >= 0; i--) {
			if (dp[N+M][i][N]) {
				ans1 = (i-5000) * (tot-(i-5000));
				break;
			}
		}
		for (int i = tot/2 + 5000; i <= 10000; i++) {
			if (dp[N+M][i][N]) {
				ans1 = max(ans1,(i-5000) * (tot-(i-5000)));
				break;
			}
		}
		for (int i = 0; i <= 10000; i++) {
			if (dp[N+M][i][N]) {
				ans2 = (i-5000) * (tot-(i-5000));
				break;
			}
		}
		for (int i = 10000; i >= 0; i--) {
			if (dp[N+M][i][N]) {
				ans2 = min(ans2,(i-5000) * (tot-(i-5000)));
				break;
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
    return 0;
}
