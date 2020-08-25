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
	int N;
	while (cin >> N,N) {
		int arr[N];
		vector<int> ans;
		for (int i = 0; i < N ; i++) cin >> arr[i];
		for (int i = 0; i < N; i++) {
			if (!arr[i]) continue;
			ans.push_back(arr[i]);
		}
		if (ans.empty()) ans.push_back(0);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size()-1) cout << " ";
		}
		cout << endl;
	}
    return 0;
}
