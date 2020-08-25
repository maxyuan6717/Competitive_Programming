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

int indx[63000];
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
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n,P,Q;
		cin >> n >> P >> Q;
		for (int i = 0; i <= n*n; i++) indx[i] = -1;
		for (int i = 0; i <= P; i++) {
			int num;
			cin >> num;
			indx[num] = i;
		}
		vector<int> v;
		for (int i = 0; i <= Q; i++) {
			int num;
			cin >> num;
			if (indx[num] == -1) continue;
			v.push_back(indx[num]);
		}
		N = v.size();
	    cout << "Case " << t << ": " << lis(v) << endl;
	}
    return 0;
}
