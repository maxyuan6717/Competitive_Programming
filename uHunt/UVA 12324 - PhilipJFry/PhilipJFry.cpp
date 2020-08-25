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

#define LARGE 100000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,t[101],b[101];
int dp[101][101];

int main() {
	while (cin >> N,N) {
		for (int i = 1; i <= N; i++) cin >> t[i] >> b[i];
		int tot = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = LARGE;
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				if (tot < j) break;
				dp[i][j] = dp[i-1][j] + t[i];
				if (j) dp[i][j] = min(dp[i][j],dp[i-1][j-1] + t[i]/2);
			}
			tot += b[i];
		}
		int ans = LARGE;
		for (int i = 0; i <= N; i++) ans = min(ans,dp[N][i]);
		cout << ans << endl;
	}
    return 0;
}
