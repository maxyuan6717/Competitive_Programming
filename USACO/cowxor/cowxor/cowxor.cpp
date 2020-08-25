/*
 ID: yuanmax1
 PROG: cowxor
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

int N,id[100001],dp[1000001];

int main() {
    ofstream fout ("cowxor.out");
    ifstream fin ("cowxor.in");
    fin >> N;
    for (int i = 1; i <= N; i++) {
        fin >> id[i];
        dp[i] = dp[i-1] ^ id[i];
    }
    
    return 0;
}