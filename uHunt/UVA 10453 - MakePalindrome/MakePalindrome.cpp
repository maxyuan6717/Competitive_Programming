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
int dp[1000][1000];
pii p[1000][1000];

int palindrome(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 0;
	if (l + 1 == r && s[l] == s[r]) {
		p[l][r] = mp(l+1,r-1);
		return dp[l][r] = 0;
	}
	if (s[l] == s[r]) {
		p[l][r] = mp(l+1,r-1);
		return dp[l][r] = palindrome(l+1,r-1);
	}
	int ret1 = palindrome(l,r-1);
	int ret2 = palindrome(l+1,r);
	if (ret1 < ret2) {
		dp[l][r] = ret1 + 1;
		p[l][r] = mp(l,r-1);
	}
	else {
		dp[l][r] = ret2 + 1;
		p[l][r] = mp(l+1,r);
	}
	return dp[l][r];
}

void printans(int l, int r) {
	if (l == r) {
		cout << s[l];
		return;
	}
	if (l > r) return;
	int pl = p[l][r].first;
	int pr = p[l][r].second;
	if (pl == l+1 && pr == r) {
		cout << s[l];
		printans(pl,pr);
		cout << s[l];
	}
	else if (pl == l && pr == r-1) {
		cout << s[r];
		printans(pl,pr);
		cout << s[r];
	}
	else if (pl == l + 1 && pr == r-1) {
		cout << s[l];
		printans(pl,pr);
		cout << s[l];
	}
}

int main() {
	while (getline(cin,s)) {
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				dp[i][j] = -1;
				p[i][j] = mp(-1,-1);
			}
		}
		cout << palindrome(0,s.size()-1) << " ";
		printans(0,s.size()-1);
		cout << endl;
	}
    return 0;
}
