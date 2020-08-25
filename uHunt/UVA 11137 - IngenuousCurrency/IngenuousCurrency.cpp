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

long long dp[10000],ans;

int main() {
	dp[0] = 1;
	for (int i = 1; i <= 21; i++) {
		int v = pow(i,3);
		for (int j = v; j <= 9999; j++) {
			dp[j] += dp[j-v];
		}
	}
	while (cin >> ans) cout << dp[ans] << endl;
    return 0;
}
