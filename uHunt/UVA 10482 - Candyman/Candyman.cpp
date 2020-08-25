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

int N,w[32];
int total = 0;
int ans = LARGE;
bool dp[645][645];

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		total = 0;
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		ans = LARGE;
		for (int i = 0; i < N; i++) {
			cin >> w[i];
			total += w[i];
		}
		for (int i = 0; i < N; i++) {
			int val = w[i];
			for (int j = total-val; j >= 0; j--) {
				for (int k = total-val; k >= 0; k--) {
					if (!dp[j][k]) continue;
					dp[j+val][k] = 1;
					dp[j][k+val] = 1;
					int l = total - (j+k);
					int mi = min(j,min(k,l));
					int ma = max(j,max(k,l));
					ans = min(ans,ma-mi);
				}
			}
		}
		cout << "Case " << t << ": " << ans << endl;
	}
    return 0;
}
