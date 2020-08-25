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

map<int,int> m;
int arr[10000];
int N,M;

int main() {
	while (cin >> N) {
		m.clear();
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			m[arr[i]]++;
		}
		sort(arr,arr+N);
		cin >> M;
		int ans = 0;
		int dist = LARGE;
		for (int i = 0; i < N; i++) {
			m[arr[i]]--;
			if (m[M-arr[i]] && abs(arr[i] - (M-arr[i])) < dist) {
				ans = min((M-arr[i]),arr[i]);
				dist = (M-ans) - ans;
			}
		}
		cout << "Peter should buy books whose prices are " << ans << " and " << M-ans << "." << endl << endl;
	}
    return 0;
}
