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
int arr[11][101];
int dp[11][101];
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				if (i && j) cin >> arr[i][j];
				dp[i][j] = -1;
			}
		}
		dp[0][0]= 0;
		for (int i = 1; i <= N; i++) {
			for (int j = M; arr[i][j] > 4 && j >= 0; j--) {
				for (int k = M; k >= j; k--) {
					if (dp[i-1][k-j] == -1) continue;
					dp[i][k] = max(dp[i][k],dp[i-1][k-j] + arr[i][j]);
				}
			}
		}
		if (dp[N][M] == -1) {
			cout << "Peter, you shouldn't have played billiard that much." << endl;
			continue;
		}
		double ans = (dp[N][M]+1e-9)/N;
		cout << "Maximal possible average mark - " << setprecision(2) << fixed << ans << "." << endl;
	}
    return 0;
}
