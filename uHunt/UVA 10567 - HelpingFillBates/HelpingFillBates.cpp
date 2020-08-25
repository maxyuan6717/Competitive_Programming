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

string S,SS;
int Q;
vector<int> arr[52];

int indx(char c) {
	if (c > 97) return c-'a';
	else return c-'A' + 26;
}

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) arr[indx(S[i])].push_back(i);
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> SS;
		int ans1,ans2,cindx = -1;
		bool matched = 1;
		vector<int>::iterator it;
		for (int i = 0; i < SS.size(); i++) {
			int charindx = indx(SS[i]);
			it = upper_bound(arr[charindx].begin(),arr[charindx].end(),cindx);
			if (it == arr[charindx].end()) {
				matched = 0;
				break;
			}
			int indx2 = it - arr[charindx].begin();
			cindx = arr[charindx][indx2];
			if (!i) ans1 = cindx;
		}
		ans2 = cindx;
		if (!matched) cout << "Not matched" << endl;
		else cout << "Matched " << ans1 << " " << ans2 << endl;
	}
    return 0;
}
