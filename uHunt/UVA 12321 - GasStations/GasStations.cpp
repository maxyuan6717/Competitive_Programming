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

struct station {
	int l,r;
};

int L,G;
station stations[10000];

bool comp(station a, station b) {
	if (a.l != b.l) return a.l < b.l;
	return a.r > b.r;
}

int main() {
	while (cin >> L >> G, L || G) {
		for (int i = 0; i < G; i++) {
			int x,r;
			cin >> x >> r;
			stations[i].l = x-r;
			stations[i].r = x+r;
		}
		sort(stations,stations+G,comp);
		int left = 0, right = -1, i = 0,ans = 0;
		while (i < G && right < L) {
			//cout << stations[i].l << " " << stations[i].r << " " << left << " " << right << endl;
			if (stations[i].r <= left) i++;
			else {
				if (stations[i].l > left) break;
				while (i < G && right < L && stations[i].l <= left) {
					right = max(right,stations[i].r);
					i++;
				}
				if (left != right) {
					ans++;
					left = right;
				}
			}
		}
		if (right < L) cout << -1 << endl;
		else cout << G-ans << endl;
	}
    return 0;
}
