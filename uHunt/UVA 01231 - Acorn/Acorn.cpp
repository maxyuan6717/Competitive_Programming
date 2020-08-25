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

int t,h,f,n,num;

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> t >> h >> f;
		int acorns[t][h+1];
		int dp[h+1];
		memset(acorns,0,sizeof(acorns));
		memset(dp,0,sizeof(dp));
		for (int i = 0; i < t; i++) {
			cin >> n;
			for (int j = 0; j < n; j++) {
				cin >> num;
				acorns[i][num]++;
			}
		}
		for (int i = 0; i < t; i++) dp[h] = max(dp[h],acorns[i][h]);
		for (int i = h-1; i >= 0; i--) {
			for (int j = 0; j < t; j++) {
				if (i + f <= h) acorns[j][i] += max(acorns[j][i+1],dp[i+f]);
				else acorns[j][i] += acorns[j][i+1];
				dp[i] = max(dp[i],acorns[j][i]);
			}
		}
		cout << dp[0] << endl;
	}
	cin >> C;
    return 0;
}
