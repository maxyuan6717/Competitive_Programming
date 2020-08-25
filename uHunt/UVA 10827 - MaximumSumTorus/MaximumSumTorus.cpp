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

int N;
int arr[150][150];
int dp[150];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				arr[i][j+N] = arr[i][j];
				arr[i+N][j] = arr[i][j];
				arr[i+N][j+N] = arr[i][j+N];
			}
		}
		int M = 2*N;
		int ans = INT_MIN;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dp[j] = 0;
			}
			for (int j = i; j < i+N; j++) {
				int total = 0;
				for (int k = 0; k < M; k++) {
					dp[k] += arr[j][k];
					total += dp[k];
				}
				total/=2;
				int curSum = 0,start = 0;
				for (int k = 0; k < M; k++) {
					if (k == start + N) break;
					curSum += dp[k];
					ans = max(ans,curSum);
					if (curSum < 0) {
						curSum = 0;
						start = k+1;
					}
				}
				curSum = start = 0;
				int bigneg = LARGE;
				for (int k = 0; k < M; k++) {
					if (k == start + N) break;
					curSum += dp[k];
					bigneg = min(bigneg,curSum);
					if (curSum > 0) {
						curSum = 0;
						start = k+1;
					}
				}
				if (total != bigneg) total -= bigneg;
				//if (i == 1 && j == 3) cout << total << " " << bigneg << endl;
				ans = max(ans,total);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
