/*
 ID: yuanmax1
 PROG: bbreeds
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

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

string s;
int open[1001],dp[1000][1001],N;

int rec(int indx, int G) {
    if (indx == N) return 1;
    if (dp[indx][G] != -1) return dp[indx][G];
    int H = open[indx] - G;
    if (s[indx] == '(') return dp[indx][G] = ( rec(indx+1,G+1) + rec(indx+1,G) ) % 2012;
    int sum = 0;
    if (G) sum += rec(indx+1,G-1);
    if (H) sum += rec(indx+1,G);
    return dp[indx][G] = sum % 2012;
}

int main() {
    ofstream fout ("bbreeds.out");
    ifstream fin ("bbreeds.in");
    fin >> s;
    N = (int) s.length();
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < N; i++) {
        if (s[i] == '(') open[i+1] = open[i] + 1;
        else open[i+1] = open[i] - 1;
    }
    fout << rec(0,0) << endl;
    return 0;
}