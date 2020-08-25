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

int main() {
    int total = 0;
    ifstream fin("test.in");
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    int dp[total/2+1];
    bool visited[total/2+1];
    for (int i = 0; i < total/2+1; i++) dp[i] = 0,visited[i] = 0;
    sort(arr,arr+N);
    dp[0] = 1;
    visited[0] = 1;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = total/2; j >= arr[i]; j--) {
            dp[j]=(dp[j]+dp[j-arr[i]])%1000000;
            if (visited[j-arr[i]]) visited[j] = 1;
            if (visited[j] && j >= ans1) ans1 = j, ans2 = dp[j];
        }
    }
    //for (int i = 0; i < total/2+1; i++) cout << dp[i] << " ";
    //cout << endl;
    cout << abs(total-2*ans1) << endl << ans2 << endl;
    return 0;
}