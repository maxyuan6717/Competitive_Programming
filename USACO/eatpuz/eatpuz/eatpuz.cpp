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

#define LARGE 9999999

using namespace std;

int C,B;
int arr[21];
vector<int> used[35001];
int dp[35001];
int ans = 0;

int partof(vector<int> v,int a) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == a) return 1;
    }
    return 0;
}

int main() {
    cin >> C >> B;
    for (int i = 0; i < B; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+B);
    for (int i = 0; i <= C; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= C; i++) {
        for (int j = 0; j < B; j++) {
            if (arr[j] > i) break;
            if (!partof(used[i-arr[j]],j) && dp[i-arr[j]] == 1) {
                dp[i] = 1;
                used[i] = used[i-arr[j]];
                used[i].push_back(j);
            }
            if (dp[i] && i > ans) ans = i;
        }
    }
    //for (int i = 0; i <= C; i++) cout << dp[i] << endl;
    cout << ans << endl;
    
    return 0;
}