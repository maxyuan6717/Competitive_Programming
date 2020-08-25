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

int C,a,b,c,total;
int dp[160][151][61];

int rec(int left, int fives, int tens) {
	if (!left) return dp[left][fives][tens] = 0;
	if (dp[left][fives][tens] != -1) return dp[left][fives][tens];
	int ones = total - (8*(C-left) + 5*fives + 10*tens);
	int ret = LARGE;
	if (ones >= 8) ret = min(ret,rec(left-1,fives,tens)+8);
	if (fives >= 2) ret = min(ret,rec(left-1,fives-2,tens)+2);
	if (tens >= 1) ret = min(ret,rec(left-1,fives,tens-1)+1);
	if (ones >= 3 && fives >= 1) ret = min(ret,rec(left-1,fives-1,tens)+4);
	if (ones >= 3 && tens >= 1) ret = min(ret,rec(left-1,fives+1,tens-1)+4);
	return dp[left][fives][tens] = ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> C >> a >> b >> c;
		total = a + 5*b + 10*c;
		memset(dp,-1,sizeof(dp));
		cout << rec(C,b,c) << endl;
	}
    return 0;
}
