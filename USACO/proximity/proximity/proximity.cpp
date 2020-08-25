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
int arr[50001];
map<int,int> m;

int main() {
    cin >> N >> K;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        int n = arr[i];
        if (m[n] != 0 && i > m[n] && i-m[n] > K) m[n] = i;
        else if (m[n] != 0 && i-m[n] <= K && n > ans) ans = n;
        else if (m[n] == 0) m[n] = i;
    }
    cout << ans << endl;
    return 0;
}