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

long long dp[66][66][2];

int main() {
	dp[1][0][0] = dp[1][1][1] = 1;
	for (int i = 2; i <= 65; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j][0] = dp[i-1][j][0];
			if (j) dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1];
			if (j < i) dp[i][j][0] += dp[i-1][j+1][1];
		}
	}
	int N,S;
	while (cin >> N >> S, N >= 0 && S >= 0) {
		cout << dp[N][S][0] + dp[N][S][1] << endl;
	}
    return 0;
}
