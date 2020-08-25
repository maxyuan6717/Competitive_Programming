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

struct box {
	int w,m;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

box boxes[1001];
int dp[6005];
int N;

int main() {
	while (cin >> N, N) {
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= N; i++) cin >> boxes[i].w >> boxes[i].m;
		dp[boxes[N].w] = 1;
		int ans = 1;
		for (int i = N-1; i >= 1; i--) {
			box b = boxes[i];
			for (int j = b.m; j >= 0; j--) {
				if (dp[j]) {
					dp[j+b.w] = max(dp[j+b.w],dp[j] + 1);
					ans = max(ans,dp[j+b.w]);
				}
			}
			dp[b.w] = max(1,dp[b.w]);
		}
		cout << ans << endl;
	}
    return 0;
}
