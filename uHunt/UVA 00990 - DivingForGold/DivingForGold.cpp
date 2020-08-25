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

int T,W,N;
int w[31];
int v[31];

int main() {
	int caseNum = 0;
	while (cin >> T >> W) {
		if (caseNum++) cout << endl;
		cin >> N;
		W*=3;
		for (int i = 1; i <= N; i++) {
			cin >> w[i] >> v[i];
			w[i] *= W;
		}
		int dp[N+1][T];
		vector<int> seq[31][1001];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= T; j++) {
				seq[i][j].clear();
				dp[i][j] = -1;
				if (!j) dp[i][j] = 0;
			}
		}
		int ans = 0;
		vector<int> ansseq;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= T; j++) {
				if (w[i] > j || dp[i-1][j-w[i]] == -1) {
					dp[i][j] = dp[i-1][j];
					seq[i][j] = seq[i-1][j];
					if (i == N && dp[i][j] > ans) {
						ans = dp[i][j];
						ansseq = seq[i][j];
					}
					continue;
				}
				dp[i][j] = dp[i-1][j];
				seq[i][j] = seq[i-1][j];
				if (dp[i-1][j-w[i]] + v[i] > dp[i][j]) {
					dp[i][j] = dp[i-1][j-w[i]] + v[i];
					seq[i][j] = seq[i-1][j-w[i]];
					seq[i][j].push_back(i);
				}
				if (i == N && dp[i][j] > ans) {
					ans = dp[i][j];
					ansseq = seq[i][j];
				}
				//cout << i << " " << j << " " << dp[i][j] << " " << ans << endl;
			}
		}
		cout << ans << endl;
		cout << ansseq.size() << endl;
		for (int i = 0; i < ansseq.size(); i++) {
			int j = ansseq[i];
			cout << w[j]/W << " " << v[j] << endl;
		}
	}
    return 0;
}
