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
	string s;
	while (cin >> s) {
		int N = s.size();
		int cnt3 = 0, cnt4 = 0;
		string pal3, pal4;
		bool works = 0;
		for (int i = 1; i < N-1; i++) {
			if (s[i-1] == s[i+1]) {
				string sub = s.substr(i-1,3);
				if (cnt4) {
					works = 1;
					break;
				}
				if (cnt3 && sub != pal3) {
					works = 1;
					break;
				}
				else if (!cnt3) {
					cnt3++;
					pal3 = sub;
				}
			}
			if (i == N-2) continue;
			if (s[i-1] == s[i+2] && s[i] == s[i+1]) {
				string sub = s.substr(i-1,4);
				if (s[i] == s[i-1]) continue;
				if (cnt3) {
					works = 1;
					break;
				}
				if (cnt4 && sub != pal4) {
					works = 1;
					break;
				}
				else if (!cnt4) {
					cnt4++;
					pal4 = sub;
				}
			}
		}
		if (works) cout << s << endl;
	}
    return 0;
}
