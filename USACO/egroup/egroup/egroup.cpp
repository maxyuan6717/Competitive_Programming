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
vector<int> arr;
int dp[3][30000];
int input = 1;

int main() {
    cin >> N;
    int ans = LARGE;
    for (int a = 0; a < 2; a++) {
        for (int i = 0; i < N; i++) {
            if (input) {
                int num;
                cin >> num;
                arr.push_back(num);
            }
            if (i == 0) {
                if (arr[i] == 1) dp[0][i] = 0;
                else dp[0][i] = 1;
                if (arr[i] == 2) dp[1][i] = 0;
                else dp[1][i] = 1;
                if (arr[i] == 3) dp[2][i] = 0;
                else dp[2][i] = 1;
            }
            else {
                if (arr[i] == 1) dp[0][i] = dp[0][i-1];
                else dp[0][i] = dp[0][i-1]+1;
                if (arr[i] == 2) dp[1][i] = min(dp[0][i-1],dp[1][i-1]);
                else dp[1][i] = min(dp[0][i-1],dp[1][i-1])+1;
                if (arr[i] == 3) dp[2][i] = min(min(dp[0][i-1],dp[1][i-1]),dp[2][i-1]);
                else dp[2][i] = min(min(dp[0][i-1],dp[1][i-1]),dp[2][i-1])+1;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (dp[i][N-1] < ans) ans = dp[i][N-1];
            //for (int j = 0; j < N; j++) dp[i][j] = 0;
        }
        input = 0;
        reverse(arr.begin(),arr.end());
    }
    cout << ans << endl;
    return 0;
}