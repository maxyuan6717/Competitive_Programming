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

int R,C,K;
int arr[101][101];
int dp[101][101];

int main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < R; i++) dp[i][0] = 0;
    for (int i = 0; i < C; i++) dp[0][i] = 0;
    dp[0][0] = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int a = i+1; a < R; a++) {
                for (int b = j + 1; b < C; b++) {
                    if (arr[i][j] != arr[a][b]) dp[a][b] = (dp[a][b]+dp[i][j])%1000000007;
                }
            }
        }
    }
    cout << dp[R-1][C-1] << endl;
    
    
    return 0;
}