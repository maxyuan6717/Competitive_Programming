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
int arr[25][25];
int dp[25];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string s;
		cin >> s;
		N = s.size();
		for (int i = 0; i < N; i++) {
			arr[0][i] = (s[i] == '1');
			if (!arr[0][i]) arr[0][i] = -100000;
		}
		for (int i = 1; i < N; i++) {
			cin >> s;
			for (int j = 0; j < N; j++) {
				arr[i][j] = (s[j] == '1');
				if (!arr[i][j]) arr[i][j] = -100000;
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) dp[j] = 0;
			for (int j = i; j < N; j++) {
				for (int k = 0; k < N; k++) dp[k] += arr[j][k];
				int sum = 0;
				for (int k = 0; k < N; k++) {
					sum += dp[k];
					ans = max(ans,sum);
					if (sum < 0) sum = 0;
				}
			}
		}
		cout << ans << endl;
		if (t != T-1) cout << endl;
	}
    return 0;
}
