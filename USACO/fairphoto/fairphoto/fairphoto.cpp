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

struct cow {
    int pos;
    int color;
};

int N;
vector<cow> fence;
int dp[100002];

bool compare(cow a, cow b) {
    return a.pos < b.pos;
}

pair<int, int> mp(int a, int b) {
    return make_pair(a,b);
}

int main() {
    fstream fin("test.in");
    cin >> N;
    for (int i = 0; i < N; i++) {
        int pos;
        char ch;
        cin >> pos >> ch;
        cow c;
        if (ch == 'W') c.pos = pos, c.color = 0;
        else c.pos = pos, c.color = 1;
        fence.push_back(c);
    }
    sort(fence.begin(),fence.end(),compare);
    if (!fence[0].color) dp[0] = -1;
    else dp[0] = 1;
    //cout << dp[0] << " ";
    for (int i = 1; i < N; i++) {
        if (!fence[i].color) dp[i] = dp[i-1]-1;
        else dp[i] = dp[i-1]+1;
        //cout << dp[i] << " ";
    }
    //cout << endl;
    int ans = 0;
    multiset<pair<int,int>> even;
    multiset<pair<int,int>> odd;
    for (int i = 0; i < N; i++) {
        //cout << dp[i] << endl;
        cow c = fence[i];
        int pos = c.pos;
        if(i == 0) {
            even.insert(mp(0,pos));
            pair<int,int> p = *even.rbegin();
            if (dp[i] <= p.first) {
                ans = max(ans,pos-odd.lower_bound(mp(dp[i],-LARGE))->second);
            }
        }
        else if (dp[i-1]%2 == 0) {
            pair<int,int> p = *even.rbegin();
            //cout << p.first << " " << p.second << endl;
            if (dp[i-1] > p.first) {
                even.insert(mp(dp[i-1],pos));
            }
            if (dp[i] <= p.first) {
                ans = max(ans,pos-odd.lower_bound(mp(dp[i],-LARGE))->second);
            }
        }
        else {
            if (odd.empty()) odd.insert(mp(dp[i-1],pos));
            else {
                pair<int,int> p = *odd.rbegin();
                if (dp[i-1] > p.first) {
                    odd.insert(mp(dp[i-1],pos));
                }
                if (dp[i] <= p.first) {
                    ans = max(ans,pos-even.lower_bound(mp(dp[i],-LARGE))->second);
                }
            }
        }
    }
    /*multiset<pair<int,int>>::iterator it;
    for (it = odd.begin(); it != odd.end(); it++) {
        cout << it->first << " ";
    }
    cout << endl;*/
    cout << ans << endl;
    return 0;
}