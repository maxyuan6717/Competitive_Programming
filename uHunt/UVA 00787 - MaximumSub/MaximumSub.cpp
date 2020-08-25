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

long long dp[100],arr[101],N;

int main() {
	while (cin >> arr[0]) {
		N = 1;
		dp[0] = arr[0];
		while (cin >> arr[N],arr[N] != -999999) {
			dp[N] = dp[N-1] * arr[N];
			N++;
		}
		long long ans = arr[0];
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {

			}
		}
	}
    return 0;
}
