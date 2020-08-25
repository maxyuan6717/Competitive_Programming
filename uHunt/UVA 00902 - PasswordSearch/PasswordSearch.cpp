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
	string s,ans;
	int N,anscnt = 0;
	while (cin >> N >> s) {
		map<string,int> cnt;
		anscnt = 0;
		for (int i = 0; i <= s.size()-N; i++) {
			string sub = s.substr(i,N);
			int num = ++cnt[sub];
			if (num > anscnt) {
				anscnt = num;
				ans = sub;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
