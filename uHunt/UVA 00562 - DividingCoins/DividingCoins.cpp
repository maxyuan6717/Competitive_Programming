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

int v[100];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		int total = 0;
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
			total += v[i];
		}
		int tot = total;
		total/=2;
		bool dp[N+1][total+1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= total; j++) {
				dp[i][j] = 0;
				if (!j) dp[i][j] = 1;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= total; j++) {
				if (v[i] > j) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				dp[i][j] = dp[i-1][j] | dp[i-1][j-v[i]];
				if (dp[i][j]) ans = max(ans,j);
			}
		}
		cout << tot - 2*ans << endl;
	}
    return 0;
}
