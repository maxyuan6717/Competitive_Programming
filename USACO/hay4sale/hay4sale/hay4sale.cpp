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

int N,C;
int arr[5001];
bool dp[50001];

int main() {
    ifstream fin("test.in");
    cin >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N+1);
    int ans = 0;
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i] > j) continue;
            if (dp[j-arr[i]]) dp[j] = 1;
            if (dp[j] && j > ans) ans =j;
        }
    }
    cout << ans << endl;
    return 0;
}