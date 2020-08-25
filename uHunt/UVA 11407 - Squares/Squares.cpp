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
	int T,N;
	int squares[100];
	int dp[10001];
	for (int i = 1; i <= 100; i++) squares[i-1] = i*i;
	for (int i = 0; i <= 10000; i++) dp[i] = i;
	for (int i = 0; i < 100; i++) {
		int c = squares[i];
		for (int j = 0; j <= 10000-c; j++) {
			dp[j+c] = min(dp[j+c],dp[j] + 1);
		}
	}
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		cout << dp[N] << endl;
	}
    return 0;
}
