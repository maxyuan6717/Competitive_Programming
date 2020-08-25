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

int N,M;
int arr[1000][1000];
int dp[1000][1000];

int main() {
	int caseNum = 0;
	while (cin >> N >> M) {
		if (caseNum++) cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = 0;
				cin >> arr[i][j];
				dp[i][j] += arr[i][j];
				if (i) dp[i][j] += dp[i-1][j];
				if (j) dp[i][j] += dp[i][j-1];
				if (i && j) dp[i][j] -= dp[i-1][j-1];
				//cout << dp[i][j] << " ";
			}
			//cout << endl;
		}
		int total = 0;
		for (int i = 0; i < N-M+1; i++) {
			for (int j = 0; j < N-M+1; j++) {
				int u = i + M - 1;
				int v = j + M - 1;
				int sum = dp[u][v];
				if (i) sum -= dp[i-1][v];
				if (j) sum -= dp[u][j-1];
				if (i && j) sum += dp[i-1][j-1];
				cout << sum << endl;
				total += sum;
			}
		}
		cout << total << endl;
	}
    return 0;
}
