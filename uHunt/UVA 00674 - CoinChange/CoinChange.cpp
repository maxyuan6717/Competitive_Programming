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

#define LARGE 100000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int val[5] = {1,5,10,25,50},dp[7490],ans;

int main() {
	for (int i = 0; i < 7490; i++) dp[i] = 0;
	dp[0] = 1;
	for (int i = 0; i < 5; i++) {
		int v = val[i];
		for (int j = v; j < 7490; j++) {
			dp[j] += dp[j-v];
		}
	}
	while (cin >> ans) cout << dp[ans] << endl;
    return 0;
}
