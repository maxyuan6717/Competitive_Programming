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
	int N,K;
	cin >> N >> K;
	while (N || K) {
		int dp[K+1][N+1];
		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = 0;
				if (i == 1) dp[i][j] = 1;
			}
		}
		for (int i = 2; i <= K; i++) {
			for (int j = 0; j <= N; j++) {
				for (int k = 0; k <= N-j; k++) {
					if (dp[i-1][k]) {
						dp[i][j+k] = (dp[i][j+k] + dp[i-1][k]) % 1000000;
					}
				}
			}
		}
		cout << dp[K][N] << endl;;
		cin >> N >> K;
	}
    return 0;
}
