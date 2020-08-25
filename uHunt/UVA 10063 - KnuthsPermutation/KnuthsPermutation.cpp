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
char ans[10];
int N;

void rec(int indx, vector<char> v) {
	if (indx == N) {
		for (int i = 0; i < N; i++) cout << v[i];
		cout << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		v.insert(v.begin()+i,s[indx]);
		rec(indx+1,v);
		v.erase(v.begin()+i);
	}
	v.push_back(s[indx]);
	rec(indx+1,v);
	v.pop_back();
}

int main() {
	int caseNum = 0;
	while (cin >> s) {
		if (caseNum++) cout << endl;
		N = s.size();
		for (int i = 0; i < N; i++) ans[i] = ' ';
		vector<char> v;
		v.push_back(s[0]);
		rec(1,v);
	}
    return 0;
}
