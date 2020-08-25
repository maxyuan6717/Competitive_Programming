/*
 ID: yuanmax1
 PROG: hidden
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

int L, dp[200002];
int start,n[200002],p[200002];
char s[200002],minc = 'z';

void remove(int i) {
    if (start == i) start = n[i];
    if (n[i] != -1) p[n[i]] = p[i];
    if (p[i] != -1) n[p[i]] = n[i];
}

char findMin() {
    char ret = 'z';
    for (int i = start; i != -1; i = n[i]) ret = min(ret,s[i+dp[i]]);
    return ret;
}

int main() {
    memset(s,'z'+1,sizeof(s));
    ofstream fout ("hidden.out");
    ifstream fin ("hidden.in");
    fin >> L;
    for (int i = 0; i < L; i++) {
        fin >> s[i];
        s[i+L] = s[i];
    }
    L*=2;
    L++;
    for (int i = 0; i < L; i++) {
        n[i] = i+1;
        p[i] = i-1;
    }
    start = 0;
    n[L-1] = -1;
    int pMax = -1;
    bool done = 0;
    while (!done) {
        minc = findMin();
        int maxL = -1;
        for (int i = start; i != -1; i = n[i]) {
            if (i + dp[i] > L) continue;
            if (dp[i+dp[i]]) {
                remove(i+dp[i]);
                dp[i] += dp[i+dp[i]];
            }
            else if (s[i+dp[i]] == minc) dp[i]++;
            maxL = max(maxL,dp[i]);
        }
        for (int i = start; i != -1; i = n[i]) if (dp[i] < maxL) remove(i);
        if (maxL == (L-1)/2 || maxL == pMax) {
            done = 1;
        }
        else pMax = maxL;
    }
    cout << start << endl;
    fout << start << endl;
    return 0;
}