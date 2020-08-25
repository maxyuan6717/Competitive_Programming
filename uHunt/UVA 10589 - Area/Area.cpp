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

long long N,a;

double dist(double x1, double y1, double x2, double y2) {
	return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
	while (cin >> N >> a, N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			double x,y;
			cin >> x >> y;
			double dis = dist(x,y,0,0);
			if (dis > a*a) continue;
			dis = dist(x,y,0,a);
			if (dis > a*a) continue;
			dis = dist(x,y,a,0);
			if (dis > a*a) continue;
			dis = dist(x,y,a,a);
			if (dis > a*a) continue;
			cnt++;
		}
		cout << setprecision(5) << fixed << (double)cnt*a*a/N << endl;
	}
    return 0;
}
