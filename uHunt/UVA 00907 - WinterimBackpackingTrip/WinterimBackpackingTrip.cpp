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

int N,K;
int dist[602];

bool binsearch(int target) {
	int cur = 0;
	int days = 0;
	for (int i = 0; i <= N; i++) {
		if (dist[i] > target) return 0;
		if (cur + dist[i] <= target) cur += dist[i];
		else cur = dist[i], days++;
	}
	days++;
	return days <= K + 1;
}

int main() {
	while (cin >> N >> K) {
		for (int i = 0; i <= N; i++) {
			cin >> dist[i];
		}
		int l = 0, r = 1e7;
		while (l <= r) {
			int target = (l+r)/2;
			if (binsearch(target)) r = target-1;
			else l = target + 1;
		}
		int ans = r + 1;
		cout << ans << endl;
	}
    return 0;
}
