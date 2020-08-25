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

struct block {
	int x,y,z;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

block blocks[180];
int N;

bool compare(block a, block b) {
	if (a.x != b.x) return a.x > b.x;
	if (a.y != b.y) return a.y > b.y;
	if (a.z != b.z) return a.z > b.z;
	return 0;
}

bool works(block a, block b) {
	return ((a.x > b.x && a.y > b.y) || (a.y > b.x && a.x > b.y));
}

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		N*=6;
		for (int i = 0; i < N; i+=6) {
			int x,y,z;
			cin >> x >> y >> z;
			blocks[i].x = x, blocks[i].y = y, blocks[i].z = z;
			blocks[i+1].x = x, blocks[i+1].y = z, blocks[i+1].z = y;
			blocks[i+2].x = y, blocks[i+2].y = x, blocks[i+2].z = z;
			blocks[i+3].x = y, blocks[i+3].y = z, blocks[i+3].z = x;
			blocks[i+4].x = z, blocks[i+4].y = x, blocks[i+4].z = y;
			blocks[i+5].x = z, blocks[i+5].y = y, blocks[i+5].z = x;
		}
		sort(blocks,blocks+N,compare);
		int dp[180];
		int ans = 0;
		for (int i = 0; i < N; i++) {
			dp[i] = blocks[i].z;
			for (int j = 0; j < i; j++) {
				if (works(blocks[j],blocks[i])) {
					dp[i] = max(dp[i],dp[j] + blocks[i].z);
					ans = max(ans,dp[i]);
				}
			}
		}
		cout << "Case " << caseNum++ << ": maximum height = " << ans << endl;
	}
    return 0;
}
