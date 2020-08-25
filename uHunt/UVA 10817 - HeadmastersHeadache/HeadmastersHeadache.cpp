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

#define LARGE 1e8
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int S,M,N;
vector<int> sub[101];
int cost[101];
int dp[101][1<<9][1<<9];
int ans = 0;

int rec(int cur, int bm1, int bm2) {
	if (bm1 == (1 << (S+1)) - 1 && bm2 == (1 << (S+1)) -1) return 0;
	if (cur > N) return LARGE;
	if (dp[cur][bm1][bm2] != -1) return dp[cur][bm1][bm2];
	int tmp1 = bm1, tmp2 = bm2;
	for (int i = 0; i < sub[cur].size(); i++) {
		int subject = sub[cur][i];
		if (tmp1 & (1 << subject)) tmp2 |= (1 << subject);
		else tmp1 |= (1 << subject);
	}
	int ret = min(rec(cur+1,bm1,bm2), rec(cur+1,tmp1,tmp2) + cost[cur]);
	return dp[cur][bm1][bm2] = ret;
}

int main() {
	while (cin >> S >> M >> N, S || M || N) {
		cin.ignore();
		int bm1 = 1,bm2 = 1;
		ans = 0;
		for (int i = 0; i < M; i++) {
			string str;
			getline(cin,str);
			stringstream ss(str);
			int c,subject;
			ss >> c;
			ans += c;
			while (ss >> subject) {
				if (bm1 & (1 << subject)) bm2 |= (1 << subject);
				else bm1 |= (1 << subject);
			}
		}
		for (int i = 1; i <= N; i++) {
			sub[i].clear();
			string str;
			getline(cin,str);
			stringstream ss(str);
			int subject;
			ss >> cost[i];
			while (ss >> subject) sub[i].push_back(subject);
		}
		memset(dp,-1,sizeof(dp));
		cout << ans + rec(1,bm1,bm2) << endl;
	}
    return 0;
}
