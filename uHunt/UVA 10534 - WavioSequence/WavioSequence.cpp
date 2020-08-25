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
vector<int> v;

vector<int> lis() {
	int len = 0;
	vector<int> seq;
	vector<int> ret;
	ret.resize(N);
	for (int i = 0; i < N; i++) {
		int indx = lower_bound(seq.begin(),seq.end(),v[i]) - seq.begin();
		if (indx == len) {
			seq.push_back(v[i]);
			len++;
		}
		else {
			seq[indx] = v[i];
		}
		ret[i] = indx+1;
		//cout << v[i] << " " << indx + 1 << endl;
	}
	return ret;
}

int main() {
	while (cin >> N) {
		v.clear();
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		int ans = 1;
		vector<int> up = lis();
		reverse(v.begin(),v.end());
		vector<int> down = lis();
		reverse(down.begin(),down.end());
		for (int i = 0; i < N; i++) {
			ans = max(ans, 2*min(up[i],down[i])-1);
		}
		cout << ans << endl;
	}
    return 0;
}
