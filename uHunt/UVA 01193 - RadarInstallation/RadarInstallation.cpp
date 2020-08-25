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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct island {
	double x,y;
};

struct interval {
	double s,e;
};

island islands[1000];
vector<interval> intervals;
int N,D;

bool comp (interval a, interval b) {
	if (a.s != b.s) return a.s < b.s;
	return a.e > b.e;
}

int main() {
	int caseNum = 1;
	while (cin >> N >> D, N || D) {
		cout << "Case " << caseNum++ << ": ";
		intervals.clear();
		for (int i = 0; i < N; i++) cin >> islands[i].x >> islands[i].y;
		bool cant = 0;
		for (int i = 0; i < N; i++) {
			island c = islands[i];
			if (c.y > D) {
				cant = 1;
				break;
			}
			long double d = sqrt(D*D - c.y*c.y) + 1e-8;
			interval add = {c.x-d, c.x+d};
			intervals.push_back(add);
		}
		if (cant) {
			cout << -1 << endl;
			continue;
		}
		sort(intervals.begin(),intervals.end(),comp);
		int ans = 0;
		double last = -(1e60);
		for (int i = 0; i < N; i++) {
			if (intervals[i].s <= last) {
				last = min(intervals[i].e,last);
				continue;
			}
			ans++;
			last = intervals[i].e;
		}
		cout << ans << endl;
	}
    return 0;
}
