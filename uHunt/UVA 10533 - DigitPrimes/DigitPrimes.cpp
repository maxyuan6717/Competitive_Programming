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
	for (int p = 2; p*p <= n; p++) {
		if (isPrime[p]) {
			for (int i = p*2; i <= n; i+=p) {
				isPrime[i] = 0;
			}
		}
	}
}

int sum(int x) {
	int ret = 0;
	while (x) {
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int main() {
	genPrimes(1000000);
	cnt[0] = 0;
	isPrime[0] = isPrime[1] = 0;
	for (int i = 1; i <= 1000000; i++) {
		cnt[i] = cnt[i-1];
		if (isPrime[i] && isPrime[sum(i)]) cnt[i]++;
	}
	int T;
	scanf("%d",&T);
	for (int t = 0; t < T; t++) {
		int a,b,ans;
		scanf("%d %d",&a,&b);
		if (!a) ans = cnt[b];
		else ans = cnt[b] - cnt[a-1];
		printf("%d\n",ans);
	}
    return 0;
}
