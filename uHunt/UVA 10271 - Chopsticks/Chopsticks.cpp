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

int N,K,len[5001];
int dp[1009][5001];
int val[5001];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> K >> N;
		K+=8;
		for (int i = N; i >= 1; i--) cin >> len[i];
		for (int i = 1; i <= K; i++) for (int j = 0; j <= N; j++) dp[i][j] = LARGE;
		for (int i = 0; i <= N; i++) dp[0][i] = 0;
		for (int i = 2; i <= N; i++) val[i] = pow(len[i]-len[i-1],2);
		for (int i = 1; i <= K; i++) {
			for (int j = 3*i; j <= N; j++) {
				dp[i][j] = min(dp[i][j-1],dp[i-1][j-2] + val[j]);
			}
		}
		cout << dp[K][N] << endl;
	}
    return 0;
}
