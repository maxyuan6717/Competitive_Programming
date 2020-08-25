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

int N,K;
long long ans = 0;
long long dp[100001];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    dp[1] = 2;
    for (int i = 2; i <= N; i++) {
        if (i-K-1 > 0) dp[i] = (dp[i-1] + dp[i-K-1])%5000011;
        else dp[i] = (dp[i-1]+1)%5000011;
        //cout << dp[i] << endl;
    }
    //cout << endl;
    cout << dp[N]%5000011 << endl;
    
    return 0;
}