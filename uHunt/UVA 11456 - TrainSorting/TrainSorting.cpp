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
	vector<int> ret;
	ret.resize(N,1);
	for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) ret[j] = max(ret[j],ret[i]+1);
		}
	}
	return ret;
}

vector<int> lds() {
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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		v.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		int ans = 0;
		vector<int> up = lis();
		reverse(v.begin(),v.end());
		vector<int> down = lds();
		reverse(down.begin(),down.end());
		for (int i = 0; i < N; i++) {
			//cout << down[i] << " ";
			ans = max(ans,up[i] + down[i] - 1);
		}
		cout << ans << endl;
	}
    return 0;
}
