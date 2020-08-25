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

struct doll {
	int h,w;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
bool used[20000];

bool compare(doll a, doll b) {
	if (a.h != b.h) return a.h > b.h;
	else return a.w < b.w;
}

int lis(vector<doll> v) {
	int len = 0;
	vector<int> seq;
	for (int i = 0; i < N; i++) {
		int indx = upper_bound(seq.begin(),seq.end(),v[i].w) - seq.begin();
		if (indx == len) {
			seq.push_back(v[i].w);
			len++;
		}
		else {
			seq[indx] = v[i].w;
		}
	}
	return len;
}

int main() {
	int T;
	//ifstream fin("test");
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector<doll> dolls;
		vector<int> widths;
		set<int> left;
		for (int i = 0; i < N; i++) {
			left.insert(i);
			doll d;
			cin >> d.w >> d.h;
			dolls.push_back(d);
		}
		sort(dolls.begin(),dolls.end(),compare);
		cout << lis(dolls) << endl;
	}
    return 0;
}
