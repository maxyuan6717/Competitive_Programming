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
int v[21];

int main() {
	string s;
	while (getline(cin,s),s != "") {
		stringstream ss(s);
		ss >> N >> M;
		for (int i = 1; i <= M; i++) ss >> v[i];
		bool dp[M+1][N+1];
		vector<int> seq[21][10001];
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = 0;
				if (!j) dp[i][j] = 1;
			}
		}
		int ans = 0;
		vector<int> ans2;
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				if (v[i] > j) {
					dp[i][j] = dp[i-1][j];
					seq[i][j] = seq[i-1][j];
					if (dp[i][j] && j > ans) {
						ans = j;
						ans2 = seq[i][j];
					}
					continue;
				}
				dp[i][j] = dp[i-1][j];
				seq[i][j] = seq[i-1][j];
				if (dp[i-1][j-v[i]] > dp[i][j]) {
					dp[i][j] = dp[i-1][j-v[i]];
					seq[i][j] = seq[i-1][j-v[i]];
					seq[i][j].push_back(i);
					//cout << i << " " << j << endl;
				}
				if (dp[i][j] && j > ans) {
					ans = j;
					ans2 = seq[i][j];
				}
			}
		}
		for (int i = 0; i < ans2.size(); i++) {
			cout << v[ans2[i]] << " ";
		}
		cout << "sum:" << ans << endl;
	}
    return 0;
}
