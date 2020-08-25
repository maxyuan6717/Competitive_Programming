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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t) cout << endl;
		int N;
		cin >> N;
		vector<int> ans;
		for (int add = 2; N-add >= 0; add++) {
			ans.push_back(add);
			N -= add;
		}
		for (int i = ans.size()-1; i >= 0 && N; i--) {
			ans[i]++;
			N--;
		}
		ans[ans.size()-1] += N;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size()-1) cout << " ";
		}
		cout << endl;
	}
    return 0;
}
