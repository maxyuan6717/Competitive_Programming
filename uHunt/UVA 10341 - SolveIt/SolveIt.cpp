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

double p,q,r,s,t,u;

double f(double x) {
	return (p/exp(x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int main() {
	while (cin >> p >> q >> r >> s >> t >> u) {
		double l = 0.0, r = 1.0, error = .00000001;
		if (f(l) * f(r) > 0 || (!p && !q && !r && !s && !t && !u)) {
			cout << "No solution" << endl;
			continue;
		}
		while (r-l > error) {
			double mid = (l+r)/2;
			if (f(mid) > 0) l = mid;
			else r = mid;
		}
		cout << setprecision(4) << fixed;
		cout << l << endl;
	}
    return 0;
}
