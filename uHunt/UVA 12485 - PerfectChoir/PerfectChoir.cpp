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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,tot,arr[10000];
vector<int> dif;

int main() {
	while (cin >> N) {
		tot = 0;
		dif.clear();
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			tot += arr[i];
		}
		if (tot%N) {
			cout << -1 << endl;
			continue;
		}
		tot /= N;
		for (int i = 0; i < N; i++) {
			int add = arr[i]-tot;
			if (add > 0) dif.push_back(add);
		}
		int ans = 1;
		for (int i = 0; i < dif.size(); i++) ans += dif[i];
		cout << ans << endl;
	}
    return 0;
}
