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
vector<string> group;

bool comp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	else return a < b;
}

int main() {
	int caseNum = 1;
	while (cin >> s) {
		group.clear();
		group.push_back(s);
		while (cin >> s, s != "9") {
			group.push_back(s);
		}
		sort(group.begin(),group.end(),comp);
		bool works = 1;
		for (int i = 0; i < group.size(); i++) {
			int l = group[i].size();
			string pre = group[i];
			if (pre.size() != l) break;
			for (int j = 0; j < group.size(); j++) {
				if (i == j) continue;
				string cur = group[j];
				if (pre == cur.substr(0,l)) {
					works = 0;
					break;
				}
			}
			if (!works) break;
		}
		if (works) cout << "Set " << caseNum++ << " is immediately decodable" << endl;
		else cout << "Set " << caseNum++ << " is not immediately decodable" << endl;
	}
    return 0;
}
