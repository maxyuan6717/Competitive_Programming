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
int s1[100];
int s2[100];

int main() {
	int caseNum = 1;
	while (cin >> M >> N, N || M) {
		for (int i = 0; i < M; i++) cin >> s1[i];
		for (int i = 0; i < N; i++) cin >> s2[i];
		int dp[2][N+1];
		for (int i = 0; i < 2; i++) for (int j = 0; j <= N; j++) dp[i][j] = 0;
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (s1[i-1] == s2[j-1]) dp[1][j] = dp[0][j-1] + 1;
				else dp[1][j] = max(dp[1][j-1],dp[0][j]);
			}
			for (int j = 0; j <= N; j++) dp[0][j] = dp[1][j];
        }
        cout << "Twin Towers #" << caseNum++ << endl;
        cout << "Number of Tiles : " << dp[0][N] << endl << endl;
	}
    return 0;
}
