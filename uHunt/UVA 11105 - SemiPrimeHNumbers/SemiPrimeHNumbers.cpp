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

bool isPrime[1000005];
int cnt[1000005];

void genPrimes(int n) {
	memset(isPrime,true,sizeof(isPrime));
	for (int p = 5; p*p <= n; p+=4) {
		if (isPrime[p]) {
			for (int i = p*2; i <= n; i+=p) {
				isPrime[i] = 0;
			}
		}
	}
}

int H;

int main() {
	genPrimes(1000001);
	set<long long> semiP;
	for (long long i = 5; i <= 1000001; i += 4) {
		if (!isPrime[i]) continue;
		for (long long j = i; j <= 1000001; j += 4) {
			if (!isPrime[j]) continue;
			if (i*j > 1000001) break;
			semiP.insert(i*j);
		}
	}
	for (long long i = 5; i <= 1000001; i+= 4) {
		cnt[i] = cnt[i-4];
		if (semiP.find(i) != semiP.end()) cnt[i]++;
	}
	while (cin >> H, H) {
		cout << H << " " << cnt[H] << endl;
	}
    return 0;
}
