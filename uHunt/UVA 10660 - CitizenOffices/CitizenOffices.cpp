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

struct area {
	int r,c,p;
};

int ans[5];
vector<area> areas;

int dist(int a,int b,int c,int d) {
	return (abs(a-c) + abs(b-d));
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int mn = LARGE;
		int M;
		cin >> M;
		areas.clear();
		for (int i = 0; i < M; i++) {
			int r,c,p;
			cin >> r >> c >> p;
			area a = {r,c,p};
			areas.push_back(a);
		}
		for (int i = 0; i < 21; i++) {
			for (int j = i+1; j < 22; j++) {
				for (int k = j+1; k < 23; k++) {
					for (int l = k+1; l < 24; l++) {
						for (int m = l+1; m < 25; m++) {
							int temp = 0;
							for (int a = 0; a < M; a++) {
								int n = areas[a].r;
								int o = areas[a].c;
								int cur = dist(n,o,i/5,i%5);
								cur = min(cur,dist(n,o,j/5,j%5));
								cur = min(cur,dist(n,o,k/5,k%5));
								cur = min(cur,dist(n,o,l/5,l%5));
								cur = min(cur,dist(n,o,m/5,m%5));
								cur *= areas[a].p;
								temp += cur;
							}
							if (temp < mn) {
								mn = temp;
								ans[0] = i, ans[1] = j, ans[2] = k, ans[3] = l, ans[4] = m;
							}
						}
					}
				}
			}
		}
		printf("%d %d %d %d %d\n",ans[0],ans[1],ans[2],ans[3],ans[4]);
	}
    return 0;
}
