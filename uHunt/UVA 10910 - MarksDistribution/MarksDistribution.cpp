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

long long N,G,P;
int dp[101][101];

void init() {
	dp[1][1] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
}

int main() {
	init();
	int  T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> G >> P;
		if (G < N*P) cout << 0 << endl;
		else cout << dp[N + G - N*P][N] << endl;
	}
    return 0;
}
