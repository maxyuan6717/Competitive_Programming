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

struct rect {
	int t,b,l,r;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int main() {
	rect r1,r2,ans;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t) cout << endl;
		cin >> r1.l >> r1.b >> r1.r >> r1.t;
		cin >> r2.l >> r2.b >> r2.r >> r2.t;
		if (r1.l >= r2.r || r1.r <= r2.l || r1.b >= r2.t || r1.t <= r2.b) {
			cout << "No Overlap" << endl;
			continue;
		}
		ans.l = max(r1.l,r2.l);
		ans.r = min(r1.r,r2.r);
		ans.t = min(r1.t,r2.t);
		ans.b = max(r1.b,r2.b);
		cout << ans.l << " " << ans.b << " " << ans.r << " " << ans.t << endl;
	}
    return 0;
}
