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
#define mp make_pair<int,int>

using namespace std;

struct track {
    long long s,e,f,c;
};

int L,N,B;
vector<track> coaster[1001];
long long dp[1001][1001];

int main() {
    cin >> L >> N >> B;
    for (int i = 0; i < N; i++) {
        track t;
        int len;
        cin >> t.s >> len >> t.f >> t.c;
        t.e = t.s + len;
        coaster[t.e].push_back(t);
    }
    for (int i = 0; i <= L; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k < coaster[i].size(); k++) {
                track t = coaster[i][k];
                if (t.c + j > B) continue;
                if (t.s == 0) {
                    dp[j+t.c][t.e] = max(dp[j+t.c][t.e],t.f);
                }
                else if (dp[j][t.s] && t.f + dp[j][t.s] > dp[j+t.c][i]) {
                    dp[j+t.c][i] = dp[j][t.s] + t.f;
                }
            }
        }
    }
    if (dp[B][L]) cout << dp[B][L] << endl;
    else cout << -1 << endl;
    
    return 0;
}