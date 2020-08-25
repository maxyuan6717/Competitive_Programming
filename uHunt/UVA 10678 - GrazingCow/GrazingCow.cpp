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
	int T;
	double D,L,a,b,pi;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> D >> L;
		L/=2;
		a = D/2;
		b = sqrt((L*L)-(a*a));
		a += (L-a);
		pi = 2*acos(0);
		cout << setprecision(3) << fixed << pi*a*b << endl;
	}
    return 0;
}
