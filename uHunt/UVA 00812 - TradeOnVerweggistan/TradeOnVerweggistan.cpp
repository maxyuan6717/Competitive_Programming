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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
int cnt[50],price[50][21],dp[50][21],profit[50][21],maxP[50],maxI[50];
vector<int> dups[50];
bool pos[50][1001];

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		for (int i = 0; i < N; i++) for (int j = 0; j <= 1000; j++) pos[i][j] = 0;
		if (caseNum > 1) cout << endl;
		cout << "Workyards " << caseNum++ << endl;
		for (int i = 0; i < N; i++) {
			dups[i].clear();
			maxP[i] = 0;
			maxI[i] = 0;
			cin >> cnt[i];
			for (int j = 1; j <= cnt[i]; j++) {
				cin >> price[i][j];
				dp[i][j] = dp[i][j-1] + price[i][j];
				profit[i][j] = 10*j - dp[i][j];
				if (profit[i][j] > maxP[i]) {
					maxP[i] = profit[i][j];
					maxI[i] = j;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= cnt[i]; j++) {
				if (profit[i][j] == maxP[i]) {
					dups[i].push_back(j);
				}
			}
		}
		int ans1 = 0;
		for (int i = 0; i < N; i++) ans1 += profit[i][maxI[i]];
		for (int i = 0; i < dups[0].size(); i++) pos[0][dups[0][i]] = 1;
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < dups[i].size(); j++) {
				int cur = dups[i][j];
				for (int k = 1000; k >= cur; k--) {
					if (pos[i-1][k-cur]) pos[i][k] = 1;
				}
			}
		}
		cout << "Maximum profit is " << ans1 << "." << endl;
		cout << "Number of pruls to buy:";
		int cnt = 1;
		for (int i = 0; i <= 1000 && cnt <= 10; i++) {
			if (pos[N-1][i]) {
				cout << " " << i;
				cnt++;
			}
		}
		cout << endl;
	}
    return 0;
}
