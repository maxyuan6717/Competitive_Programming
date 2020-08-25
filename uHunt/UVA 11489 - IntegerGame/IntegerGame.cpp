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
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		N = s.size();
		int total = 0;
		int cnt = 0;
		bool first = 0;
		for (int i = 0; i < N; i++) {
			int num = s[i]-'0';
			total += num;
			if (!(num%3)) cnt++;
		}
		for (int i = 0; i < N; i++) {
			int num = s[i] - '0';
			if ((total - num)%3 == 0) {
				first = 1;
				if (num % 3 == 0) cnt--;
				break;
			}
		}
		cout << "Case " << t << ": ";
		if (!first) {
			cout << "T" << endl;
		}
		else {
			if (cnt%2 == 0) cout << "S" << endl;
			else cout << "T" << endl;
		}
	}
    return 0;
}
