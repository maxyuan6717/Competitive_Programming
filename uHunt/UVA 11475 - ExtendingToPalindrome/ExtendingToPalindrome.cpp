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

string s,r;
int lps[100001];
int N,M;

void kmpPre() {
	lps[0] = 0;
	int len = 0, i = 1;
	while (i < M) {
		if (r[i] == r[len]) {
			len++;
			lps[i++] = len;
		}
		else {
			if (len) len = lps[len-1];
			else lps[i++] = 0;
		}
	}
}

int kmp() {
	kmpPre();
	int i = 0, j = 0;
	while (i < N) {
		if (s[i] == r[j]) i++,j++;
		if (i == N) return j;
		else if (i < N && s[i] != r[j]) {
			if (j) j = lps[j-1];
			else i++;
		}
	}
	return 0;
}

int main() {
	while (cin >> s) {
		r = s;
		reverse(r.begin(),r.end());
		N = s.size();
		M = r.size();
		int len = kmp();
		string add = s.substr(0,N-len);
		reverse(add.begin(),add.end());
		string ans = s + add;
		cout << ans << endl;
	}
    return 0;
}
