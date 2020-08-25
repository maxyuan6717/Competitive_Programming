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

int N,H,W;
int piece[15];
int memo[101][2<<15];
int total,done;

int sum(int bitmask) {
	int ret = 0, cnt = 0;
	while (bitmask) {
		if (bitmask & 1) ret += piece[cnt];
		cnt++;
		bitmask >>= 1;
	}
	return ret;
}

bool rec(int h, int got) {
	if (memo[h][got] != -1) return memo[h][got];
	if (got == done) return memo[h][got] = 1;
	memo[h][got] = 0;
	int w = (total-sum(got))/h;
	cout << h << " " << w << " " << got << endl;
	for (int j = 0; j < (1<<N); j++) {
		if ((got&j) != got) continue;
		int k = (1<<N) - 1 - j;
		int s1 = sum(k);
		for (int i = 0; i <= w/2; i++) {
			int a1 = i*h;
			int a2 = h*w - a1;
			if (a1 && a1 == s1) {
				memo[h][got] = rec(h,got|k);
				if (memo[h][got]) return 1;
			}
			else if (a2 == s1) {
				memo[h][got] = rec(h,got|k);
				if (memo[h][got]) return 1;
			}
		}
		for (int i = 0; i <= h/2; i++) {
			int a1 = i*w;
			int a2 = h*w - a1;
			if (a1 && a1 == s1) {
				memo[h][got] = rec(i,got|k);
				if (memo[h][got]) return 1;
			}
			else if (a2 == s1) {
				memo[h][got] = rec(h-i,got|k);
				if (memo[h][got]) return 1;
			}
		}
	}

	return memo[h][got] = 0;
}

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		done = (1<<N)-1;
		cin >> H >> W;
		total = 0;
		for (int i = 0; i < N; i++) {
			cin >> piece[i];
			total += piece[i];
		}
		cout << "Case " << caseNum++ << ": ";
		if (total != H*W) {
			cout << "No" << endl;
			continue;
		}
		memset(memo,-1,sizeof(memo));
		if (rec(H,0)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}
