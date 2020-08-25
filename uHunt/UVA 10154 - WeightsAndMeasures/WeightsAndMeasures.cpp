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
//#define cin fin

using namespace std;

struct turtle {
	int w,s;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

vector<turtle> t;
//ifstream fin ("in");

bool comp (turtle a, turtle b) {
	if (a.s == b.s) return a.w < b.w;
	return a.s < b.s;
}

int dp[5607];

int main() {
	int tCnt = 0;
	int curStack = 0;
	turtle add;
	while (cin >> add.w >> add.s) {
		if (add.s >= add.w) t.push_back(add);
	}
	tCnt = t.size();
	sort(t.begin(),t.end(),comp);
	for (int i = 1; i < tCnt; i++) dp[i] = LARGE;
	for (int i = 0; i < tCnt; i++) {
		turtle cur = t[i];
		for (int j = curStack; j >= 0; j--) {
			if (cur.s < dp[j] + cur.w) continue;
			dp[j+1] = min(dp[j+1],cur.w + dp[j]);
			curStack = max(curStack,j+1);
		}
	}
	cout << curStack << endl;
    return 0;
}
