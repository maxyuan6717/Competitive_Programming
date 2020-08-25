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

int arr[5001];
int coins[5001];
int dp[2][5001];

int sum(int a, int b) {
    if (a == 0) return arr[b];
    else return abs(arr[b]-arr[a-1]);
}

int main() {
    int N;
    cin >> N >> arr[0];
    coins[0] = arr[0];
    for (int i = 1; i < N; i++) {
        int num;
        cin >> num;
        coins[i] = num;
        arr[i] = arr[i-1] + num;
        //cout << arr[i] << " ";
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            int sum1;
            int sum2;
            if (i == j) {
                dp[1][j] = coins[j];
            }
            else {
                if (j == 0) sum1 = arr[i];
                else sum1 = abs(arr[i]-arr[j-1]);
                sum2 = sum1;
                sum1 -= dp[1][j+1];
                sum2 -= dp[0][j];
                dp[1][j] = max(sum1,sum2);
            }
        }
        for (int j = 0; j < N; j++) {
            dp[0][j] = dp[1][j];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}