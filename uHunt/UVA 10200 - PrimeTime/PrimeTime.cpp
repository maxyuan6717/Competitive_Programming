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

int a,b;
int res[10005];

bool check(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (!(n%i)) return 0;
	}
	return 1;
}

int main() {
	res[0] = 1;
	for (int i = 1; i <= 10000; i++) {
		res[i] = res[i-1];
		int num = i*i + i + 41;
		if (check(num)) res[i]++;
	}
	while (cin >> a >> b) {
		double n,d;
		d = b-a+1;
		if (!a) {
			n = res[b];
		}
		else {
			n = res[b] - res[a-1];
		}
		cout << setprecision(2) << fixed << 100*n/d + 1e-6 << endl;
	}
    return 0;
}
