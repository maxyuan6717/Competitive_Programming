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

string ans;
int N,L,cnt;

bool easy(string s){
	int n = s.size();
	for (int i = 1; i <= n/2; i++) {
		string s1 = s.substr(n-i,i), s2 = s.substr(n-2*i,i);
		if (s1 == s2) return 1;
	}
	return 0;
}

void rec(string cur) {
	if (cnt == N) {
		ans = cur;
		return;
	}
	for (int i = 0; i < L; i++) {
		char c = 'A' + i;
		string str = cur + c;
		if (easy(str)) continue;
		cnt++;
		rec(str);
		if (cnt == N) return;
	}
}

int main() {
	while (cin >> N >> L, N || L) {
		ans = "";
		cnt = 0;
		rec("");
		int ans2 = ans.size();
		int indx = 0;
		while (indx != ans2) {
			if (indx == 64) cout << endl;
			else if (indx && indx % 4 == 0) cout << " ";
			cout << ans[indx++];
		}
		cout << endl << ans2 << endl;
	}
    return 0;
}
