#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
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

using namespace std;

const int MAXN = 51;
int main() {
	int testcase;
	int N, M, P;
	int u, v, a, b;
	cin >> testcase;
	while (testcase--) {
		cin >> N >> M;
		int g[MAXN][MAXN], profit[MAXN] = {};
		int dp[1<<12][12];
		memset(g, 0x3f, sizeof(g));
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d.%d", &u, &v, &a, &b);
			g[u][v] = min(g[u][v], a * 100 + b);
			g[v][u] = min(g[v][u], a * 100 + b);
		}

		cin >> P;
		for (int i = 0; i < P; i++) {
			scanf("%d %d.%d", &u, &a, &b);
			profit[u] += a * 100 + b;
		}
		for (int i = 0; i <= N; i++)
			g[i][i] = 0;
		for (int k = 0; k <= N; k++)
			for (int i = 0; i <= N; i++)
				for (int j = 0; j <= N; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		vector<int> S;
		for (int i = 0; i <= N; i++) {
			if (profit[i] > 0)
				S.push_back(i);
		}
		vector< pair<int, int> > o;
		for (int i = 0; i < (1<<S.size()); i++) {
			for (int j = 0; j < S.size(); j++)
				dp[i][j] = -0x3f3f3f3f;
			o.push_back(make_pair(__builtin_popcount(i), i));
		}

		int ret = -0x3f3f3f3f;
		for (int i = 0; i < S.size(); i++) {
			u = S[i];
			dp[1<<i][i] = -g[0][u] + profit[u];
		}

		sort(o.begin(), o.end());
		for (int i = 0; i < o.size(); i++) {
			int state = o[i].second;
			for (int j = 0; j < S.size(); j++) {
				if (dp[state][j] == -0x3f3f3f3f)
					continue;

				u = S[j];
				ret = max(ret, dp[state][j] - g[u][0]);
				for (int k = 0; k < S.size(); k++) {
					if ((state>>k)&1)
						continue;
					v = S[k];
					dp[state|(1<<k)][k] = max(dp[state|(1<<k)][k], dp[state][j] - g[u][v] + profit[v]);
				}
			}
		}
		if (ret > 0)
			printf("Daniel can save $%d.%02d\n", ret/100, ret%100);
		else
			cout << "Don't leave the house" << endl;
	}
	return 0;
}
