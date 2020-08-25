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
int share[101];
bool dp[101][10001];

int main() {
	cout << setprecision(2) << fixed;
	while (cin >> N >> M, N || M) {
		for (int i = 1; i <= N; i++) {
			double d;
			cin >> d;
			share[i] = 1000*d/10;
			//cout << d << " " << share[i] << endl;
		}
		if (share[M] > 5000) {
			cout << double(100) << endl;
			continue;
		}
		int target = 5000 - share[M];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= 10000-share[M]; j++) {
				dp[i][j] = 0;
				if (!j) dp[i][j] = 1;
			}
		}
		int ans = LARGE;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= 10000-share[M]; j++) {
				if (i == M) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				if (share[i] > j) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-share[i]]);
				if (dp[i][j] && j > target) {
					ans = min(ans,j);
					break;
				}
			}
		}
		//cout << ans << endl;
		double numerator = share[M]*100;
		double denominator = ans+share[M];
		cout << numerator/denominator << endl;
	}
    return 0;
}
