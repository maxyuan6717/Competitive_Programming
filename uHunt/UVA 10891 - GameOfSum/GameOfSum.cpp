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

int N;
int arr[101];
int memo[101][101];
int vis[101][101];

int rec(int l, int r) {
	if (l > r) return 0;
	if (vis[l][r]) return memo[l][r];
	int res = -LARGE;
	vis[l][r] = 1;
	int sum = 0;
	for (int i = l; i <= r; i++) {
		sum += arr[i];
		res = max(res,sum - rec(i+1,r));
	}
	sum = 0;
	for (int i = r; i >= l; i--) {
		sum += arr[i];
		res = max(res,sum - rec(l,i-1));
	}
	return memo[l][r] = res;
}

int main() {
	while (cin >> N, N) {
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		memset(vis,0,sizeof(vis));
		cout << rec(0,N-1) << endl;
	}
    return 0;
}
