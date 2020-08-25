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

int N,M;
long long arr[1001],dp[1001][1001];

int main() {
	//ifstream fin ("in");
	while (cin >> N >> M, N || M) {
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			arr[i] %= M;
		}
		dp[0][0] = 1;
		for (int i = 1; i <= N; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*arr[i])%M;
			}
		}
		long long ans = 0;
		for (int i = 1; i <= N; i++) {
			ans = max(ans,dp[N][i]);
		}
		cout << ans << endl;
	}
    return 0;
}
