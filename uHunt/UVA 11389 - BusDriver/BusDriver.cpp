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

int N,D,R;
int morning[100];
int evening[100];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin >> N >> D >> R;
	while (N || D || R) {
		for (int i = 0; i < N; i++) cin >> morning[i];
		for (int i = 0; i < N; i++) cin >> evening[i];
		sort(morning,morning+N);
		sort(evening,evening+N,compare);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int overtime = morning[i] + evening[i] - D;
			if (overtime > 0) ans += overtime * R;
		}
		cout << ans << endl;
		cin >> N >> D >> R;
	}
    return 0;
}
