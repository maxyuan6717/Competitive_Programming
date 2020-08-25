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

int N,arr[250];
int dp[250][250];

int rec(int l, int r) {
	if (r <= l) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	int ret = LARGE;
	for (int i = l; i <= r; i++) {
		ret = min(ret, rec(l,i-1) + rec(i+1,r) + arr[i-1] - (l == 0 ? 0 : arr[l-1]) + arr[r] - arr[i]);
	}
	return dp[l][r] = ret;
}

int main() {
	while (cin >> N >> arr[0]) {
		for (int i = 1; i < N; i++) {
			int num;
			cin >> num;
			arr[i] = arr[i-1] + num;
		}
		memset(dp,-1,sizeof(dp));
		cout << rec(0,N-1) << endl;
	}
    return 0;
}
