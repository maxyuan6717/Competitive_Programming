/*
 ID: yuanmax1
 PROG: fuel
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

struct station {
    int p,c;
};

int N,S,D,closest[50001];
long long C;
station st[50001];

bool comp (station a, station b) {
    return a.p < b.p;
}

int main() {
    ifstream fin ("fuel.in");
    ofstream fout ("fuel.out");
    fin >> N >> C >> S >> D;
    for (int i = 0; i < N; i++) {
        fin >> st[i].p >> st[i].c;
    }
    sort(st,st+N,comp);
    if (st[0].p > S) {
        fout << -1 << endl;
        return 0;
    }
    closest[N-1] = -1;
    for (int i = N-2; i >= 0; i--) {
        closest[i] = i+1;
        while (closest[i] != -1 && st[i].c < st[closest[i]].c) closest[i] = closest[closest[i]];
    }
    long long gas = S;
    long long ans = 0;
    gas -= st[0].p;
    for (int i = 0; i < N; i++) {
        long long need;
        station cur = st[i];
        if (closest[i] != -1) need = st[closest[i]].p - cur.p;
        else need = D - cur.p;
        need = min(need,C);
        if (need > gas) {
            ans += cur.c*(need-gas);
            gas = need;
        }
        if (i != N-1) gas -= (st[i+1].p-cur.p);
        else gas -= (D-cur.p);
        if (gas < 0) {
            ans = -1;
            break;
        }
    }
    fout << ans << endl;
    return 0;
}