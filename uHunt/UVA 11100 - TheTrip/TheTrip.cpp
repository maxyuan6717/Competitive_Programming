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

int N,arr[10001];

int main() {
	int caseNum = 0;
	while (cin >> N, N) {
		if (caseNum++) cout << endl;
		for (int i = 0; i < N; i++) cin >> arr[i];
		arr[N] = -1;
		sort(arr,arr+N);
		int cnt = 1,ans = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] == arr[i+1]) cnt++;
			else {
				ans = max(ans,cnt);
				cnt = 1;
			}
		}
		cout << ans << endl;
		for (int i = 0; i < ans; i++) {
			bool first = 1;
			for (int j = i; j < N; j += ans) {
				if (first) first = 0;
				else cout << " ";
				cout << arr[j];
			}
			cout << endl;
		}
	}
    return 0;
}
