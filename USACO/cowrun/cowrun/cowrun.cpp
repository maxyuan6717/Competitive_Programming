/*
 ID: yuanmax1
 PROG: cowrun
 LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <iomanip>
#include <climits>

#define LARGE 1000000000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,pos[1001],st;
int dp[2][1001][1001];

int rec(bool p, int l, int r) {
    if (dp[p][l][r] != -1) return dp[p][l][r];
    if (l >= r) return LARGE;
    int mult = N+1-(r-l);
    if (p == 0) dp[p][l][r] = min(mult*(pos[l+1] - pos[l]) + rec(0,l+1,r), mult*(pos[r] - pos[l]) + rec(1,l+1,r));
    else dp[p][l][r] = min(mult*(pos[r] - pos[l]) + rec(0,l,r-1),mult*(pos[r] - pos[r-1]) + rec(1,l,r-1));
    return dp[p][l][r];
}

int main() {
    ifstream fin ("cowrun.in");
    ofstream fout ("cowrun.out");
    fin >> N;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[0][i][j] = dp[1][i][j] = -1;
        }
    }
    pos[0] = 0;
    for (int i = 1; i <= N; i++) fin >> pos[i];
    sort(pos,pos+N+1);
    for (int i = 0; i <= N; i++) {
        if (pos[i] == 0) {
            st = i;
            break;
        }
    }
    dp[0][st][st] = 0;
    dp[1][st][st] = 0;
    fout << min(rec(0,0,N),rec(1,0,N)) << endl;
    //cout << dp[0][1][2] << endl;
    return 0;
}