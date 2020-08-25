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

int N,M,K;
long long cost[100][100];
long long dp[100][100];

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dp[i][j] = 0;
				cin >> cost[i][j];
				dp[i][j] += cost[i][j];
				if (i > 0) dp[i][j] += dp[i-1][j];
				if (j > 0) dp[i][j] += dp[i][j-1];
				if (i>0 && j>0) dp[i][j] -= dp[i-1][j-1];
			}
		}
		long long ans1 = 0, ans2 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				bool done = 0;
				for (int k = i; k < N; k++) {
					for (int l = j; l < M; l++) {
						long long sum = dp[k][l];
						if (i > 0) sum -= dp[i-1][l];
						if (j > 0) sum -= dp[k][j-1];
						if (i > 0 && j > 0) sum += dp[i-1][j-1];
						if (sum > K) {
							done = 1;
							break;
						}
						int area = (k+1-i)*(l+1-j);
						if (area > ans1) {
							ans1 = area;
							ans2 = sum;
						}
						else if (area == ans1) ans2 = min(ans2,sum);
					}
					//if (done) break;
				}
			}
		}
		cout << "Case #" << t << ": " << ans1 << " " << ans2 << endl;
	}
    return 0;
}
