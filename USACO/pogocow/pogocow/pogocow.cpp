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

#define LARGE 999999999

using namespace std;

int dp[1001][1001];

int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > targets(N);
    for(int i = 0; i < N; i++) {
        cin >> targets[i].first >> targets[i].second;
    }
    sort(targets.begin(), targets.end());
    
    int ans = 0;
    for(int loop = 0; loop < 2; loop++) {
        for(int i = N - 1; i >= 0; i--) {
            int k = N;
            int change = 0;
            for(int j = 0; j <= i; j++) {
                while(k - 1 > i && abs(targets[k - 1].first - targets[i].first) >= abs(targets[i].first - targets[j].first)) {
                    k--;
                    change = max(change, targets[k].second + dp[k][i]);
                }
                dp[i][j] = change;
            }
            ans= max(ans, targets[i].second + change);
        }
        reverse(targets.begin(), targets.end());
    }
    
    cout << ans << endl;
    return 0;
}