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
int rungs[100001];

int works(int target) {
	for (int i = 1; i <= N; i++) {
		if (rungs[i] - rungs[i-1] > target) return 0;
		if (rungs[i] - rungs[i-1] == target) target--;
	}
	return 1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> rungs[i];
		rungs[0] = 0;
		int l = 0, r = 1e7;
		while (l <= r) {
			int mid = (l+r)/2;
			if (works(mid)) {
				r = mid-1;
			}
			else {
				l = mid+1;
			}
		}
		cout << "Case " << t << ": " <<  r + 1 << endl;
	}
    return 0;
}
