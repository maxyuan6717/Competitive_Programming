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

struct object {
    int s,v;
};

int N,C;
object arr[1001];
int dp[1001][5001];

bool compare(object a, object b) {
    return a.s < b.s;
}

int main() {
    ifstream fin("test.in");
    cin >> N >> C;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].s >> arr[i].v;
    }
    sort(arr,arr+N+1,compare);
    int ans = 0;
    for (int i = 0; i <= C; i++) dp[0][i] = 0;
    for (int i = 0; i <= N; i++) dp[i][0] = 0;
    
    for (int i = 1; i <= N; i++) {
        object o = arr[i];
        for (int j = 1; j <= C; j++) {
            if (o.s > j) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-o.s]+o.v);
            }
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}