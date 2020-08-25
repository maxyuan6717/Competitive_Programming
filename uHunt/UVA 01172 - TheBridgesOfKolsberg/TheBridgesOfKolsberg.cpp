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

#define LARGE 100000000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M;
string l[1001],r[1001],name;
int u[1001],v[1001];
int dp[1001][1001];
int cnt[1001][1001];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> name >> l[i] >> u[i];
		cin >> M;
		for (int i = 1; i <= M; i++) cin >> name >> r[i] >> v[i];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				dp[i][j] = cnt[i][j] = 0;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				dp[i][j] = dp[i-1][j];
				cnt[i][j] = cnt[i-1][j];
				if (dp[i][j-1] > dp[i][j]) {
					dp[i][j] = dp[i][j-1];
					cnt[i][j] = cnt[i][j-1];
				}
				if (l[i] == r[j] && dp[i-1][j-1] + u[i] + v[j] > dp[i][j]) {
					dp[i][j] = dp[i-1][j-1] + u[i] + v[j];
					cnt[i][j] = cnt[i-1][j-1] + 1;
				}
			}
		}
		cout << dp[N][M] << " " << cnt[N][M] << endl;
	}
    return 0;
}
