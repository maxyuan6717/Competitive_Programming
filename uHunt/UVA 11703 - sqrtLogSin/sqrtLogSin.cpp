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

int main() {
	int dp[1000001];
	dp[0] = 1;
	for (double i = 1; i <= 1000000; i++) {
		dp[(int)i] = (dp[(int) (i-sqrt(i))] + dp[(int) log(i)] + dp[(int)( i * (sin(i) * sin(i)))])%1000000;
	}
	int i;
	while (cin >> i, i != -1) {
		cout << dp[i] << endl;
	}
    return 0;
}
