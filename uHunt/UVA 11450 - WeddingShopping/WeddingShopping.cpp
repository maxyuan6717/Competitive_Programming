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

vector<int> garments[21];

int main() {
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
    	int M,C;
    	cin >> M >> C;
    	for (int i = 0; i < C; i++) {
    		garments[i].clear();
    		int k;
    		cin >> k;
    		for (int j = 0; j < k; j++) {
    			int num;
    			cin >> num;
    			garments[i].push_back(num);
    		}
    	}
    	int dp[21][201];
    	for (int i = 0; i < C; i++) {
    		for (int j = 0; j <= M; j++) {
    			dp[i][j] = 0;
    		}
    	}
    	for (int i = 0; i < garments[0].size(); i++) {
    		if (M-garments[0][i] >= 0) {
    			dp[0][garments[0][i]] = 1;
    		}
    	}
    	for (int i = 1; i < C; i++) {
    		for (int j = 0; j < garments[i].size(); j++) {
    			int cost = garments[i][j];
    			for (int m = 0; m <= M-cost; m++) {
    				if (dp[i-1][m]) {
    					dp[i][m+cost] = 1;
    					//cout << m+cost << endl;
    				}
    			}
    		}
    	}
    	int ans = -1;
    	for (int i = M; i >= 0; i--) {
    		if (dp[C-1][i]) {
    			ans = i;
    			break;
    		}
    	}
    	if (ans == -1) cout << "no solution" << endl;
    	else cout << ans << endl;
    }
    return 0;
}
