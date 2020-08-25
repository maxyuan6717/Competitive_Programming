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
int arr[100][100];
int dp2[100][100];
int dp[100];

int main() {
	while (cin >> N >> M, N || M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				if (arr[i][j]) arr[i][j] = -100000;
				else arr[i][j] = 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dp[j] = 0;
			}
			for (int j = i; j < N; j++) {
				for (int k = 0; k < M; k++) {
					dp[k] += arr[j][k];
				}
				int curSum = 0;
				for (int k = 0; k < M; k++) {
					curSum += dp[k];
					ans = max(ans,curSum);
					if (curSum < 0) curSum = 0;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}
