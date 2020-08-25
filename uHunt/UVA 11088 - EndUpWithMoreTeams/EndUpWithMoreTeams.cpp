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

int N,A[15],dp[1<<15];

int rec(int mask) {
	if (dp[mask] != -1) return dp[mask];
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (mask & (1 << i)) continue;
		for (int j = i+1; j < N; j++) {
			if (mask & (1 << j)) continue;
			for (int k = j+1; k < N; k++) {
				if (mask & (1 << k)) continue;
				int add = A[i] + A[j] + A[k] >= 20;
				int newMask = mask | (1 << i) | (1 << j) | (1 << k);
				ret = max(ret, add + rec(newMask));
			}
		}
	}
	return dp[mask] = ret;
}

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		for (int i = 0; i < N; i++) cin >> A[i];
		memset(dp,-1,sizeof(dp));
		cout << "Case " << caseNum++ << ": " << rec(0) << endl;
	}
    return 0;
}
