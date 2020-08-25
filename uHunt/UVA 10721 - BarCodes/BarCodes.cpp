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

int N,K,M;
long long dp[51][51];

int main() {
	while (cin >> N >> K >> M) {
		for (int i = 0; i <= K; i++) for (int j = 0; j <= N; j++) dp[i][j] = 0;
		dp[0][0] = 1;
		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= M; k++) {
					if (j < k) break;
					dp[i][j]  += dp[i-1][j-k];
				}
			}
		}
		cout << dp[K][N] << endl;
	}
    return 0;
}
