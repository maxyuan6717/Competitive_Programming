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
int arr[10][100];
int dp[10][100];
vector<int> seq[10][100];
int di[3] = {1,0,-1};

int main() {
	while (cin >> N >> M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				dp[i][j] = 100000;
				seq[i][j].clear();
				if (!j) {
					dp[i][j] = arr[i][j];
					seq[i][j].push_back(i);
				}
			}
		}
		int ans = LARGE;
		vector<int> ansseq;
		for (int j = 1; j < M; j++) {
			for (int i = 0; i < N; i++) {
				for (int k = 0; k < 3; k++) {
					int nj = j-1;
					int ni = (i + N + di[k])%N;
					if (dp[ni][nj] + arr[i][j] < dp[i][j] || (dp[ni][nj] + arr[i][j] == dp[i][j] && seq[ni][nj] < seq[i][j])) {
						dp[i][j] = dp[ni][nj] + arr[i][j];
						seq[i][j] = seq[ni][nj];
						seq[i][j].push_back(i);
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			int j = M-1;
			if (dp[i][j] < ans || (dp[i][j] == ans && seq[i][j] < ansseq)) {
				ans = dp[i][j];
				ansseq = seq[i][j];
			}
		}
		for (int i = 0; i < M; i++) {
			cout << ansseq[i]+1;
			if (i != M-1) cout << " ";
		}
		cout << endl << ans << endl;
	}
    return 0;
}
