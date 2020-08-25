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

int N,H;
string cur;

bool works(int x) {
	int cnt = 0;
	cur = "";
	for (int i = 0; i < N; i++) {
		if (x & (1<<i)) {
			cnt++;
			cur = '1' + cur;
		}
		else cur = '0' + cur;
		if (cnt > H) return 0;
	}
	if (cnt == H) return 1;
	return 0;
}

int main() {
	int T;
	cin >> T;
	//ofstream fout ("out");
	for (int t = 0; t < T; t++) {
		cin >> N >> H;
		for (int i = 0; i < 1<<N; i++) {
			if (works(i)) cout << cur << endl;
		}
		if (t != T-1) cout << endl;
	}
    return 0;
}
