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

int N;
int arr[20000];
int dp[20000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 0;
    }
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] <= dp[j])
                dp[i] = dp[j];
        }
        dp[i]++;
        if (dp[i] > ans) ans = dp[i];
    }
    cout << ans << endl;
    
    return 0;
}