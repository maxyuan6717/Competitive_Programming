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

string s1,s2;
map<string,int> dp;

int main() {
	//ifstream fin("in");
	dp.clear();
	int ans = 0;
	while (cin >> s1) {
		int len = 1;
		for (int i = 0; i <= s1.size(); i++) {
			for (char add = 'a'; add <= 'z'; add++) {
				s2 = s1;
				s2.insert(i,1,add);
				if (s2>s1) break;
				if (dp.count(s2)) len = max(len,dp[s2]+1);
			}
		}
		for (int i = 0; i < s1.size(); i++) {
			for (char change = 'a'; change <= 'z'; change++) {
				if (change == s1[i]) continue;
				s2 = s1;
				s2[i] = change;
				if (s2>s1) break;
				if (dp.count(s2)) len = max(len,dp[s2]+1);
			}
		}
		for (int i = 0; i < s1.size(); i++) {
			s2 = s1;
			s2.erase(i,1);
			if (dp.count(s2)) len = max(len,dp[s2]+1);
		}
		dp[s1] = len;
		ans = max(ans,len);
	}
	cout << ans << endl;
    return 0;
}
