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

map<string,bool> in;
map<string,int> indx;
vector<string> d;
int N,Q;
string s;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		in[s] = 1;
		indx[s] = i;
		d.push_back(s);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> s;
		if (in[s]) {
			cout << s << " is correct" << endl;
			continue;
		}
		int ans = LARGE;
		// insert
		for (int i = 0; i <= s.size(); i++) {
			for (int j = 0; j < 26; j++) {
				char add = 'a' + j;
				string str = s;
				if (i == s.size()) str += add;
				else str.insert(i,1,add);
				if (in[str]) ans = min(ans,indx[str]);
			}
		}
		// delete
		for (int i = 0; i < s.size(); i++) {
			string str = s;
			str.erase(i,1);
			if (in[str]) ans = min(ans,indx[str]);
		}
		// replace
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < 26; j++) {
				char add = 'a' + j;
				string str = s;
				str[i] = add;
				if (in[str]) ans = min(ans,indx[str]);
			}
		}
		// swap
		for (int i = 0; i < s.size()-1; i++) {
			string str = s;
			swap(str[i],str[i+1]);
			if (in[str]) ans = min(ans,indx[str]);
		}
		if (ans != LARGE) cout << s << " is a misspelling of " << d[ans] << endl;
		else cout << s << " is unknown" << endl;
	}
    return 0;
}
