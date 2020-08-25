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
#define maxN 10000

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int main() {
	int N;
	while (cin >> N, N) {
		int ans = 0;
		double maxSize = 0;
		for (int i = 0; i < N; i++) {
			double w,h;
			cin >> w >> h;
			if (w > h) swap(w,h);
			//cout << w << " " << h << endl;
			double cur = w/2;
			if (h >= 4*w) cur = w;
			else cur = max(cur,h/4);
			if (cur > maxSize) {
				maxSize = cur;
				ans = i+1;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
