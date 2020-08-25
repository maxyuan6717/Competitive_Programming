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

int sum[10001];
int num[10001];

bool isPrime[100001];

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

int main() {
	genPrimes(100000);
	isPrime[0] = isPrime[1] = 0;
	int T,N;
	int ansLen;
	pii ans;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> sum[0];
		num[0] = sum[0];
		for (int i = 1; i < N; i++) {
			cin >> num[i];
			sum[i] = sum[i-1] + num[i];
		}
		ansLen = LARGE;
		for (int i = 0; i < N; i++) {
			for (int l = 2; l <= min(ansLen-1,N-i); l++) {
				int j = i+l-1;
				int cur;
				if (!i) cur = sum[j];
				else cur = sum[j] - sum[i-1];
				if (!isPrime[cur]) continue;
				else {
					ansLen = l;
					ans.first = i;
					ans.second = j;
				}
			}
		}
		if (ansLen == LARGE) cout << "This sequence is anti-primed." << endl;
		else {
			cout << "Shortest primed subsequence is length " << ansLen << ": ";
			for (int i = ans.first; i <= ans.second; i++) {
				cout << num[i];
				if (i != ans.second) cout << " ";
			}
			cout << endl;
		}
	}
    return 0;
}
