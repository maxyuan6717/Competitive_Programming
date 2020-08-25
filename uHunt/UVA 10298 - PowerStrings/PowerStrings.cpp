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

string s;
int N;

int main() {
	//ifstream fin("in");
	while (cin >> s, s != ".") {
		N = s.size();
		int ans = 1;
		for (int i = 1; i <= N; i++) {
			if (N%i != 0) continue;
			bool works = 1;
			for (int j = i; j <= N-i; j+=i) {
				for (int k = 0; k < i; k++) {
					if (s[k] != s[k+j]) {
						works = 0;
						break;
					}
				}
				if (!works) break;
			}
			if (works) {
				ans = N/i;
				break;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
