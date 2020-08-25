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
	unsigned long long N,K;
	while (cin >> N >> K, N || K) {
		K = min(K,N-K);
		unsigned long long ans = 1;
		for (unsigned long long i = 1; i <= K; i++) {
			ans *= (N-K+i);
			ans /= i;
		}
		cout << ans << endl;
	}
    return 0;
}
