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

double K,N;
double memo[11][101];
double tot,cnt;

double rec(int cur, int len) {
	if (memo[cur][len] != -1) {
		cnt += memo[cur][len];
		return memo[cur][len];
	}
	memo[cur][len] = 0;
	if (len == N) {
		cnt++;
		return memo[cur][len] = 1;
	}
	for (int i = -1; i <= 1; i++) {
		int ni = cur+i;
		if (ni < 0 || ni > K) continue;
		memo[cur][len] += rec(ni,len+1);
	}
	return memo[cur][len];
}

int main() {
	while (cin >> K >> N) {
		tot = pow(K+1,N);
		cnt = 0;
		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= N; j++) {
				memo[i][j] = -1;
			}
		}
		for (int i = 0; i <= K; i++) rec(i,1);
		//cout << cnt << " " << tot << endl;
		cout << setprecision(5) << fixed << 100*cnt/tot << endl;
	}
    return 0;
}
