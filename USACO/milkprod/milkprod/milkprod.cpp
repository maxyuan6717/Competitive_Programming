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

struct interval {
    int s,e,ef;
};

int N,M,R;
int dp[1001];
vector<interval> schedule;

bool compare(interval a, interval b) {
    return a.s < b.s;
}

int main() {
    ifstream fin("test.in");
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++) {
        interval in;
        cin >> in.s >> in.e >> in.ef;
        schedule.push_back(in);
    }
    sort(schedule.begin(),schedule.end(),compare);
    dp[0] = schedule[0].ef;
    int ans = 0;
    for (int i = 1; i < M; i++) {
        interval i1 = schedule[i];
        dp[i] = schedule[i].ef;
        for (int j = 0; j < i; j++) {
            interval i2 = schedule[j];
            if (i1.s >= i2.e + R && dp[j] + i1.ef > dp[i]) dp[i] = dp[j] + i1.ef;
        }
        if (dp[i] > ans) ans = dp[i];
    }
    cout << ans << endl;
    
    return 0;
}