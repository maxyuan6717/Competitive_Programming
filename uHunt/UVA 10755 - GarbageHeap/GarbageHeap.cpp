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

int A,B,C;
long long dp1[20][20][20];
long long dp2[20][20];
long long dp3[20];
long long ans;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = INT_MIN;
		cin >> A >> B >> C;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				for (int k = 0; k < C; k++) {
					cin >> dp1[i][j][k];
				}
			}
		}
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) for (int k = 0; k < C; k++) dp2[j][k] = 0;
			for (int j = i; j < A; j++) {
				for (int k = 0; k < B; k++) for (int l = 0; l < C; l++) dp2[k][l] += dp1[j][k][l];
				for (int k = 0; k < B; k++) {
					for (int l = 0; l < C; l++) dp3[l] = 0;
					for (int l = k; l < B; l++) {
						for (int m = 0; m < C; m++) dp3[m] += dp2[l][m];
						long long curSum = 0;
						for (int m = 0; m < C; m++) {
							curSum += dp3[m];
							ans = max(ans,curSum);
							if (curSum < 0) curSum = 0;
						}
					}
				}
			}
		}
		cout << ans << endl;
		if (t != T-1) cout << endl;
	}
    return 0;
}
