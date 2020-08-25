#include <iostream>
#include <fstream>
#include <string>
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

#define LARGE (1<<31)-1

using namespace std;

int cuts[52];
int dp[52][52];

int solve(int l, int r) {
	if (l + 1 == r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	int ret = LARGE;
	for (int i = l+1; i < r; i++) {
		int sum = cuts[r]-cuts[l] + solve(l,i) + solve(i,r);
		ret = min(ret,sum);
	}
	dp[l][r] = ret;
	return ret;
}

int main() {
	int L;
	cin >> L;
	while (L) {
		int N;
		cin >> N;
		cuts[0] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> cuts[i];
		}
		cuts[N+1] = L;
		for (int i = 0; i <= N+1; i++) {
			for (int j = 0; j <= N+1; j++) {
				dp[i][j] = -1;
			}
		}
		cout << "The minimum cutting is " << solve(0,N+1) << "." << endl;
		cin >> L;
	}
    
    return 0;
}
