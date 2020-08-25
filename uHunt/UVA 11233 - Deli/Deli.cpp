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
	int L,N;
	cin >> L >> N;
	map<string,string> irreg;
	string s,s1,s2;
	set<char> vowels;
	vowels.insert('a'), vowels.insert('e'), vowels.insert('i'), vowels.insert('o'), vowels.insert('u');
	for (int i = 0; i < L; i++) {
		cin >> s1 >> s2;
		irreg[s1] = s2;
	}
	for (int i = 0; i < N; i++) {
		cin >> s;
		int l = s.size();
		char c = s[l-1];
		string ans,l2 = s.substr(l-2,2);
		if (irreg[s] != "") {
			cout << irreg[s] << endl;
			continue;
		}
		if (vowels.find(s[l-2]) == vowels.end() && s[l-1] == 'y') ans = s.substr(0,l-1) + "ies";
		else if (c == 'o' || c == 'x' || c == 's') ans = s + "es";
		else if (l2 == "ch" || l2 == "sh") ans = s + "es";
		else ans = s + "s";
		cout << ans << endl;
	}
    return 0;
}
