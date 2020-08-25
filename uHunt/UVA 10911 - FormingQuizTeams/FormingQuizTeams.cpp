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

struct house {
	double x,y;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
house houses[16];
double dis[16][16];
double dp[1<<16];
int maxbm;

double dist(house a, house b) {
	return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}

double solve(int used) {
	if (used == maxbm - 1) return 0;
	if (dp[used] != -1) return dp[used];
	double ret = LARGE;
	for (int i = 0; i < N; i++) {
		if (used & (1<<i)) continue;
		for (int j = i+1; j < N; j++) {
			if (used & (1<<j)) continue;
			int newUsed = used | 1<<i;
			newUsed |= 1<<j;
			ret = min(ret,dis[i][j] + solve(newUsed));
		}
	}
	return dp[used] = ret;
}

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		string name;
		N*=2;
		for (int i = 0; i < N; i++) {
			cin >> name >> houses[i].x >> houses[i].y;
		}
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				dis[i][j] = dist(houses[i],houses[j]);
				dis[j][i] = dis[i][j];
			}
		}
		maxbm = 1<<N;
		for (int i = 0; i < maxbm; i++) dp[i] = -1;
		cout << setprecision(2) << fixed;
		cout << "Case " << caseNum++ << ": " << solve(0) << endl;
	}
    return 0;
}
