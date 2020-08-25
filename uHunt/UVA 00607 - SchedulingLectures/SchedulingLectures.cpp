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

#define LARGE 100000000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,L,C;
int t[1001],l[1001],h[1001],psum[1001];
int dp[1001][1001];
int cost(int left) {
	if (!left) return 0;
	if (left > 10) return pow(left-10,2);
	return -C;
}

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		if (caseNum > 1) cout << endl;
		cout << "Case " << caseNum++ << ":" << endl;
		cin >> L >> C;
		int ans1 = 1;
		psum[0] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> t[i];
			psum[i] = psum[i-1] + t[i];
		}
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += t[i];
			if (sum > L) {
				ans1++;
				sum = t[i];
			}
			l[i] = ans1;
		}
		sum = 0;
		for (int i = N; i >= 1; i--) {
			sum += t[i];
			if (sum > L) {
				ans1--;
				sum = t[i];
			}
			h[i] = ans1;
		}
		ans1 = l[N];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = LARGE;
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = l[i]; j <= h[i]; j++) {
				for (int k = i; k >= 1; k--) {
					if (psum[i] - psum[k-1] <= L) dp[i][j] = min(dp[i][j],dp[k-1][j-1] + cost(L - (psum[i]-psum[k-1])));
					else break;
				}
			}
		}
		cout << "Minimum number of lectures: " << ans1 << endl;
		cout << "Total dissatisfaction index: " << dp[N][ans1] << endl;
	}
    return 0;
}
