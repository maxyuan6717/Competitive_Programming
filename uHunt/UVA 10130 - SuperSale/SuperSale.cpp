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

int main() {
	int T,N,G;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		int w[N+1],p[N+1],dp[31];
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= N; i++) cin >> p[i] >> w[i];
		for (int i = 1; i <= N; i++) {
			for (int j = 30; j >= w[i]; j--) {
				dp[j] = max(dp[j],dp[j-w[i]] + p[i]);
			}
		}
		cin >> G;
		int ans = 0;
		for (int i = 0; i < G; i++) {
			int num;
			cin >> num;
			ans += dp[num];
		}
		cout << ans << endl;
	}
    return 0;
}
