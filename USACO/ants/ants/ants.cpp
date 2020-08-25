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

int T,A,S,B;
vector<int> ants;
int counter[1001];
int dp[2][100001];
int prefix[100001];

int main() {
    cin >> T >> A >> S >> B;
    for (int i = 0; i < A; i++) {
        int num;
        cin >> num;
        counter[num]++;
        ants.push_back(num);
    }
    sort(ants.begin(),ants.end());
    for (int i =0; i <= T; i++) {
        dp[0][0] = 1;
        dp[1][0] = 1;
        prefix[0] = 1;
        for (int j = 1; j <= B; j++) prefix[j] = (prefix[j-1] + dp[0][j])%1000000;
        for (int j = 1; j <= B; j++) {
            if (j-counter[i]-1 < 0) dp[1][j] = (prefix[j])%1000000;
            else dp[1][j] = (prefix[j]-prefix[j-counter[i]-1])%1000000;
        }
        for (int j = 0; j <= B; j++) {
            //cout << dp[0][j] << " ";
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
            prefix[j] = 0;
        }
        //cout << endl;
    }
    int ans = 0;
    for (int i = S; i <= B; i++) {
        ans = (ans + dp[0][i])%1000000;
    }
    cout << ans << endl;
    return 0;
}