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

vector<int> primes;
bool isPrime[1121];
int dp[1121][15];

void genPrimes(int n) {
	memset(isPrime,true,sizeof(isPrime));
	for (int p = 2; p*p <= n; p++) {
		if (isPrime[p]) {
			for (int i = p*2; i <= n; i+=p) {
				isPrime[i] = 0;
			}
		}
	}
	for (int i = 2; i <= n; i++) if (isPrime[i]) primes.push_back(i);
}

int N,K;

int main() {
	genPrimes(1120);
	memset(dp,0,sizeof(dp));
	int M = primes.size();
	dp[0][0] = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 1120; j >= primes[i]; j--) {
			for (int k = 1; k <= 14; k++) {
				dp[j][k] += dp[j-primes[i]][k-1];
			}
		}
	}
	while (cin >> N >> K, N || K) {
		cout << dp[N][K] << endl;
	}
    return 0;
}
