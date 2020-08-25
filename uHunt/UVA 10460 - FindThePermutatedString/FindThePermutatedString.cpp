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
char ans[27];
int N,I;
int cnt = 0;
bool done = 0;

void rec(int indx, vector<char> v) {
	if (indx == N) {
		cnt++;
		if (cnt == I) {
			for (int i = 0; i < N; i++) cout << v[i];
			cout << endl;
			done = 1;
		}
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		v.insert(v.begin()+i,s[indx]);
		rec(indx+1,v);
		if (done) return;
		v.erase(v.begin()+i);
	}
	v.push_back(s[indx]);
	rec(indx+1,v);
	if (done) return;
	v.pop_back();
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> s >> I;
		N = s.size();
		cnt = 0;
		done = 0;
		for (int i = 0; i < N; i++) ans[i] = ' ';
		vector<char> v;
		v.push_back(s[0]);
		rec(1,v);
	}
    return 0;
}
