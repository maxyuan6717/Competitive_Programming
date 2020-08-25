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

int main() {
    int N,K;
    cin >> N >> K;
    int scores[N+1];
    for (int i = 1; i <= N; i++) cin >> scores[i];
    int s = scores[K];
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (scores[i] >= s && scores[i] > 0) ans++;
        else break;
    }
    cout << ans << endl;
    
    return 0;
}