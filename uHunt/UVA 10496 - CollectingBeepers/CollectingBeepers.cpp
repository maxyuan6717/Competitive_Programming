#include <iostream>
#include <fstream>
#include <string>
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

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M;
int sx,sy;
int dis[11][11];
int dp[11][1<<11];
vii beepers;
int B;

int dist(int x1, int y1, int x2, int y2) {
	return (abs(x1-x2) + abs(y1-y2));
}

int solve(int cur, int vis) {
	if (vis == (1<<(B+1))-1) {
		return dis[cur][0];
	}
	if (dp[cur][vis] != -1) return dp[cur][vis];
	int ans = 10000000;
	for (int i = 0; i <= B; i++) {
		if ((vis & 1<<i) || i == cur) continue;
		ans = min(ans,dis[cur][i] + solve(i,vis|1<<i));
	}
	dp[cur][vis] = ans;
	return ans;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
    	cin >> N >> M;
    	cin >> sx >> sy;
    	cin >> B;
    	beepers.clear();
    	beepers.push_back(mp(sx,sy));
    	for (int i = 0; i < B; i++) {
    		int x,y;
    		cin >> x >> y;
    		beepers.push_back(mp(x,y));
    	}
    	for (int i = 0; i <= B; i++) {
    		for (int j = 0; j < 1<<(B+1); j++) {
    			dp[i][j] = -1;
    		}
    	}
    	for (int i = 0; i <= B; i++) {
    		for (int j = i+1; j <= B; j++) {
    			dis[i][j] = dist(beepers[i].first, beepers[i].second, beepers[j].first, beepers[j].second);
    			dis[j][i] = dis[i][j];
    		}
    	}
    	cout << "The shortest path has length " << solve(0,1) << endl;
    }
    return 0;
}
