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

int N,B;
int arr[100][100];
int dp[100];

int main() {
	int P;
	cin >> P;
	for (int p = 0; p < P; p++) {
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = 1;
			}
		}
		for (int i = 0; i < B; i++) {
			int r1,r2,c1,c2;
			cin >> r1 >> c1 >> r2 >> c2;
			for (int i = r1-1; i < r2; i++) {
				for (int j = c1-1; j < c2; j++) {
					arr[i][j] = -100000;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) dp[j] = 0;
			for (int j = i; j < N; j++) {
				for (int k = 0; k < N; k++) dp[k] += arr[j][k];
				int curSum = 0;
				for (int k = 0; k < N; k++) {
					curSum += dp[k];
					ans = max(ans,curSum);
					if (curSum < 0) curSum = 0;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}
