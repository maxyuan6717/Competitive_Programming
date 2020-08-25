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
int dp[1001][1001];

int palindrome(int l,int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 1;
	if (l + 1 == r) {
		if (s[l] == s[r]) return dp[l][r] = 2;
		else return dp[l][r] = 1;
	}
	if (s[l] == s[r]) {
		dp[l][r] = palindrome(l+1,r-1) + 2;
	}
	else {
		dp[l][r] = max(palindrome(l+1,r),palindrome(l,r-1));
	}
	return dp[l][r];
}

int main() {
	int T;
	cin >> T;
	cin.ignore();
	for (int t = 0; t < T; t++) {
		getline(cin,s);
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				dp[i][j] = -1;
			}
		}
		cout << palindrome(0,s.size()-1) << endl;
	}
    return 0;
}
