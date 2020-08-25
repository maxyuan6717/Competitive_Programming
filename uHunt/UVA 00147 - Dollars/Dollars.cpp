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

int coins[11] = {10000,5000,2000,1000,500,200,100,50,20,10,5};

int main() {
	int C = 30000;
	long long dp[C+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < 11; i++) {
		for (int j = coins[i]; j <= C; j++) {
			dp[j] += dp[j-coins[i]];
		}
	}
	double target;
	while (cin >> target, target) {
		C = (target+.001)*100;
		cout << setprecision(2) << fixed << setw(6) << right << target;
		cout << setprecision(0) << fixed << setw(17) << right << dp[C] << endl;
	}
    return 0;
}
