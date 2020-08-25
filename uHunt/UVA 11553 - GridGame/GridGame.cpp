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

int N,arr[8][8];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
		vector<int> v;
		for (int i = 0; i < N; i++) v.push_back(i);
		int ans = LARGE;
		do {
			int cur = 0;
			for (int i = 0; i < N; i++) cur += arr[i][v[i]];
			ans = min(ans,cur);
		} while (next_permutation(v.begin(),v.end()));
		cout << ans << endl;
	}
    return 0;
}
