#include <iostream>
#include <fstream>
#include <string>
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

#define LARGE (1<<31)-1

using namespace std;

int main() {
	int N;
	while (cin >> N) {
		int arr[N][N];
		int dp[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = 0;
				cin >> arr[i][j];
				dp[i][j] += arr[i][j];
				if (i > 0) dp[i][j] += dp[i-1][j];
				if (j > 0) dp[i][j] += dp[i][j-1];
				if (i>0 && j>0) dp[i][j] -= dp[i-1][j-1];
			}
		}
		int ans = -1000000;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = i; k < N; k++) {
					for (int l = j; l < N; l++) {
						int sum = dp[k][l];
						if (i > 0) sum -= dp[i-1][l];
						if (j > 0) sum -= dp[k][j-1];
						if (i > 0 && j > 0) sum += dp[i-1][j-1];
						if (sum > ans) {
							ans = sum;
							//cout << i << " " << j << " " << k << " " << l << " " << ans << endl;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
    
    return 0;
}
