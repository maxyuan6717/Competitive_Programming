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

int main() {
    int M,N;
    int nc = 0;
    while (cin >> M >> N) {
    	nc++;
    	pii arr[101];
    	int dp[101][10001];
    	for (int i = 1; i <= N; i++) {
    		cin >> arr[i].first >> arr[i].second;
    	}
    	for (int i = 0; i <= N; i++) {
    		for (int j = 0; j <= M; j++) {
    			if (j != 0) dp[i][j] = -1;
    			else dp[i][j] = 0;
    		}
    	}
    	sort(arr+1,arr+N+1);
    	int ans = 0;
    	for (int i = 1; i <= N; i++) {
    		int weight = arr[i].first;
    		int val = arr[i].second;
    		for (int j = 1; j <= M + 200; j++) {
    			if (weight > j) {
    				dp[i][j] = dp[i-1][j];
    				continue;
    			}
    			if (dp[i-1][j-weight] == -1) {
    				dp[i][j] = dp[i-1][j];
    				continue;
    			}
    			if (j > M && j <= 2000) continue;
    			if (j > 10000) continue;
    			dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight] + val);
    			ans = max(ans,dp[i][j]);
    		}
    	}
    	cout << ans << endl;
    }
    return 0;
}
