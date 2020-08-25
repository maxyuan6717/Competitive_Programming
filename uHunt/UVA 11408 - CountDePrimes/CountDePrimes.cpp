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

int pfactors[5000005];
bool isPrime[5000005];
int cnt[5000005];

void genPrimes(int n) {
	memset(isPrime,true,sizeof(isPrime));
	for (int i = 2; i <= n; i+=2) {
		pfactors[i] = 2;
		if (i != 2) isPrime[i] = 0;
	}
	for (long long p = 3; p <= n; p+=2) {
		if (isPrime[p]) {
			pfactors[p] = p;
			for (long long q = p; q*p <= n; q+=2) {
				if (isPrime[p*q]) {
					isPrime[p*q] = 0;
					pfactors[p*q] = p;
				}
			}
		}
	}
}

int sum(int x) {
	int cur = pfactors[x];
	int ret = 0;
	while (x > 1) {
		x/=pfactors[x];
		if (cur == pfactors[x]) continue;
		ret += cur;
		cur = pfactors[x];
	}
	return ret;
}

int main() {
	genPrimes(5000000);
	isPrime[0] = isPrime[1] = 0;
	cnt[0] = 0;
	for (int i = 1; i <= 5000000; i++) {
		cnt[i] = cnt[i-1];
		if (isPrime[sum(i)]) cnt[i]++;
	}
	int a,b;
	while (cin >> a, a) {
		cin >> b;
		if (!a) cout << cnt[b] << endl;
		else cout << cnt[b] - cnt[a-1] << endl;
	}

    return 0;
}
