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

int N,K;
int arr[75][75];
int dp[75][75][6];
int kcnt[75][75];
int di[3] = {-1,0,0};
int dj[3] = {0,-1,1};

bool inbounds(int i, int j) {
	return (i >= 0 && i < N && j >= 0 && j < N);
}

int main() {
	cin >> N >> K;
	while (N || K) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				kcnt[i][j] = 0;
				for (int k = 0; k <= K; k++) dp[i][j][k] = 0;
			}
		}
		if (arr[0][0] >= 0) dp[0][0][0] = arr[0][0];
		else {
			dp[0][0][1] = arr[0][0];
			kcnt[0][0] = 1;
		}
		for (int i = 1; i < N; i++) {
			 if (arr[0][i] >= 0) {
				 dp[0][i][kcnt[0][i-1]] = dp[0][i-1][kcnt[0][i-1]] + arr[0][i];
				 kcnt[0][i] = kcnt[0][i-1];
			 }
			 else {
				 int cnt = kcnt[0][i-1];
				 dp[0][i][cnt+1] = dp[0][i-1][cnt] + arr[0][i];
				 kcnt[0][i] = cnt+1;
			 }
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 2; k++) {
					int ni = i + di[k];
					int nj = j + dj[k];
					if (!inbounds(ni,nj)) continue;
					int cnt = kcnt[ni][nj];
					if (arr[i][j] >= 0) {
						dp[i][j][cnt] = max(dp[i][j][cnt],dp[ni][nj][cnt] + arr[i][j]);
					}
				}
			}
		}
		cin >> N >> K;
	}
    return 0;
}
