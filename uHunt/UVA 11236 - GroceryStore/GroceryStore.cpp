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

#define LARGE long_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int main() {
	long cnt = 0;
	cout << setprecision(2) << fixed;
	for (long i = 1; i*i*i*i <= 2*1e9; i++) {
		for (long j = i; i*j*j*j <= 2*1e9; j++) {
			for(long k = j; i*j*k*k <= 2*1e9; k++) {
				long sum = i+j+k;
				long product = i*j*k;
				long c = 1e6;
				if (product == c) continue;
				long numerator = c*sum;
				long denominator = product - c;
				if (numerator%denominator != 0) continue;
				long l = numerator/denominator;
				if (l < k || sum + l > 2000 || product*l > 2*1e9) continue;
				cout << i/100.0 << " " << j/100.0 << " " << k/100.0 << " " << l/100.0 << endl;
				cnt++;
			}
		}
	}
    return 0;
}
