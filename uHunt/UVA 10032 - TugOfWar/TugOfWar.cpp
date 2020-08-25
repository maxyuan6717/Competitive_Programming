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
int weight[100];
bool dp[22600];
int minN[22600];
int maxN[22600];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t) cout << endl;
		cin >> N;
		int total = 0;
		for (int i = 0; i < N; i++) {
			cin >> weight[i];
			total += weight[i];
		}
		int goal = total/2;
		int lim = N/2 + N%2;
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < goal+100; i++) {minN[i] = LARGE; maxN[i] = 0;}
		minN[0] = 0;
		for (int i = 0; i < N; i++) {
			int w = weight[i];
			for (int j = goal; j >= 0; j--) {
				if (!dp[j]) continue;
				int mi = minN[j], ma = maxN[j];
				dp[j+w] = 1;
				minN[j+w] = min(mi+1,minN[j+w]);
				maxN[j+w] = max(ma+1,maxN[j+w]);
			}
		}
		int ans1 = 0, ans2 = total;
		for (int i = goal; i >= 0; i--) {
			if (!dp[i]) continue;
			int mi = minN[i], ma = maxN[i];
			if (mi <= lim && ma >= lim) {
				ans1 = i, ans2 = total-i;
				break;
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
    return 0;
}
