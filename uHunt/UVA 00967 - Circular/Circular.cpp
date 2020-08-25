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

bool isPrime[1000001];

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

int cnt[1000001];

vector<int> genDig(int x) {
	vector<int> ret;
	while (x) {
		ret.push_back(x%10);
		x/=10;
	}
	return ret;
}

bool works(int x) {
	vector<int> dig = genDig(x);
	int len = dig.size();
	for (int i = 0; i < len; i++) {
		int indx = i, num  = 0;
		for (int j = 0; j < len; j++) {
			num += dig[indx%len] * pow(10,j);
			indx++;
		}
		if (!isPrime[num]) return 0;
	}
	return 1;
}

int main() {
	genPrimes(1000000);
	cnt[99] = cnt[100] = 0;
	for (int i = 101; i <= 1000000; i++) {
		cnt[i] = cnt[i-1];
		if (works(i)) cnt[i]++;
	}
	int a,b;
	while (cin >> a, a != -1) {
		cin >> b;
		int ans = cnt[b] - cnt[a-1];
		if (!ans) cout << "No Circular Primes." << endl;
		else if (ans == 1) cout << "1 Circular Prime." << endl;
		else cout << ans << " Circular Primes." << endl;
	}
    return 0;
}
