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

int N,M;
int house[100000];

bool works(int x) {
	double d = x/2.0;
	int need = 1;
	double mark = house[0] + d;
	for (int i = 1; i < M; i++) {
		if (house[i] - d > mark) {
			need++;
			mark = house[i] + d;
		}
	}
	return need <= N;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) cin >> house[i];
		sort(house,house+M);
		int l = 0, r = (house[M-1] - house[0]);
		double ans;
		while (l <= r) {
			int m = (l+r)/2;
			if (works(m)) {
				ans = m;
				r = m-1;
			}
			else {
				l = m+1;
			}
		}
		cout << setprecision(1) << fixed << ans/2 << endl;
	}
    return 0;
}
