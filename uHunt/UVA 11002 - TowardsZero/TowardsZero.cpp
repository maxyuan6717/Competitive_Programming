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

int N,arr[60][60];
bool dp[60][60][6001];

int main() {
	while (cin >> N, N) {
		for (int i = 2*N-1; i >= N+1; i--) {
			for (int j = 0; j < 2*N - i; j++) {
				cin >> arr[i-1][j];
			}
		}
		for (int i = N; i >= 1; i--) {
			for (int j = 0; j < i; j++) {
				cin >> arr[i-1][j];
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][0][arr[0][0]+3000] = 1;
		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k <= 6000; k++) {
					if (!dp[i][j][k]) continue;
					int ni = i+1, nj = j, val = arr[ni][nj];
					if (k + val >= 0 && k + val <= 6000) dp[ni][nj][k+val] = 1;
					if (k - val >= 0 && k - val <= 6000) dp[ni][nj][k-val] = 1;
					nj++; val = arr[ni][nj];
					if (k + val >= 0 && k + val <= 6000) dp[ni][nj][k+val] = 1;
					if (k - val >= 0 && k - val <= 6000) dp[ni][nj][k-val] = 1;
				}
			}
		}
		for (int i = N-1; i < 2*N-2; i++) {
			for (int j = 0; j < 2*N - 1- i; j++) {
				for (int k = 0; k <= 6000; k++) {
					if (!dp[i][j][k]) continue;
					if (!j) {
						int ni = i+1, nj = j, val = arr[ni][nj];
						if (k + val >= 0 && k + val <= 6000) dp[ni][nj][k+val] = 1;
						if (k - val >= 0 && k - val <= 6000) dp[ni][nj][k-val] = 1;
					}
					else if (j == 2*N-i-2) {
						int ni = i+1, nj = j-1, val = arr[ni][nj];
						if (k + val >= 0 && k + val <= 6000) dp[ni][nj][k+val] = 1;
						if (k - val >= 0 && k - val <= 6000) dp[ni][nj][k-val] = 1;
					}
					else {
						int ni = i+1, nj = j-1, val = arr[ni][nj];
						if (k + val >= 0 && k + val <= 6000) dp[ni][nj][k+val] = 1;
						if (k - val >= 0 && k - val <= 6000) dp[ni][nj][k-val] = 1;
						nj++; val = arr[ni][nj];
						if (k + val >= 0 && k + val <= 6000) dp[ni][nj][k+val] = 1;
						if (k - val >= 0 && k - val <= 6000) dp[ni][nj][k-val] = 1;
					}
				}
			}
		}
		int ans = LARGE;
		for (int i = 0; i <= 6000; i++) {
			if (!dp[2*N-2][0][i]) continue;
			ans = min(ans,abs(i-3000));
		}
		cout << ans << endl;
	}
    return 0;
}
