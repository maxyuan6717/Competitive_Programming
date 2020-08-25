/*
 ID: yuanmax1
 PROG: cruise
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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,arr[1001][2],moves[500],leads[1001];
int M,K;
char c;

int rec(int u, int indx) {
    if (indx == M) return u;
    return rec(arr[u][moves[indx]],indx+1);
}

int main() {
    ifstream fin ("cruise.in");
    ofstream fout ("cruise.out");
    fin >> N >> M >> K;
    for (int i = 1; i <= N; i++) fin >> arr[i][0] >> arr[i][1];
    for (int i = 0; i < M; i++) {
        fin >> c;
        moves[i] = (c == 'L') ? 0:1;
    }
    for (int i = 1; i <= N; i++) leads[i] = rec(i,0);
    int cur = leads[1], len = 1;
    while (cur != 1) {
        len++;
        cur = leads[cur];
        if (len == K) break;
    }
    if (len == K) {
        fout << cur << endl;
        return 0;
    }
    K %= len;
    cur = 1;
    for (long long i = 0; i < K; i++) {
        cur = leads[cur];
    }
    fout << cur << endl;
    return 0;
}