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

int N;

int lis(vector<int> v) {
	int len = 0;
	vector<int> seq;
	for (int i = 0; i < N; i++) {
		int indx = upper_bound(seq.begin(),seq.end(),v[i]) - seq.begin();
		if (indx == len) {
			seq.push_back(v[i]);
			len++;
		}
		else {
			seq[indx] = v[i];
		}
	}
	return len;
}


int main() {
	int caseNum = 1, num;
	while (cin >> num, num != -1) {
		if (caseNum > 1) cout << endl;
		vector<int> v;
		v.push_back(num);
		while (cin >> num, num != -1) {
			v.push_back(num);
		}
		N = v.size();
		reverse(v.begin(),v.end());
		int ans = lis(v);
		cout << "Test #" << caseNum++ << ":" << endl;
		cout << "  " << "maximum possible interceptions: " << ans << endl;
	}
    return 0;
}
