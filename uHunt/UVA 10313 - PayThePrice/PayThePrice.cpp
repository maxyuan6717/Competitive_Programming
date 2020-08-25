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

long long N,L1 = -1,L2 = -1,dp[301][301];

int main() {
	for (int i = 0; i <= 300; i++) {
		for (int j = 0; j <= 300; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int v = 1; v <= 300; v++) {
		for (int i = v; i <= 300; i++) {
			for (int j = 1; j <= 300; j++) {
				dp[i][j] += dp[i-v][j-1];
			}
		}
	}
	string s;
	while (getline(cin,s)) {
		stringstream ss(s);
		L1 = L2 = -1;
		ss >> N >> L1 >> L2;
		long long ans = 0;
		if (L1 == -1 && L2 == -1) {
			for (int i = 0; i <= N; i++) ans += dp[N][i];
		}
		else if (L2 == -1) {
			for (int i = 0; i <= min(L1,(long long)300); i++) ans += dp[N][i];
		}
		else {
			for (int i = min(L1,(long long)300); i <= min(L2,(long long)300); i++) ans += dp[N][i];
		}
		cout << ans << endl;
	}
    return 0;
}
