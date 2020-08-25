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

long long K,C,N,a[100001];

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K >> C >> N >> a[0];
		for (int i = 1; i < N; i++) a[i] = (K*a[i-1]+C)%1000007;
		sort(a,a+N);
		long long ans = 0,cur = 0;
		for (long long i = 1; i < N; i++) {
			long long dif = a[i]-a[i-1];
			cur += dif*i;
			ans += cur;
		}
		cout << "Case " << t << ": " << ans << endl;
	}
    return 0;
}
