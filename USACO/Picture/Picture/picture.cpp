/*
 ID: yuanmax1
 PROG: picture
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
#define add 10001
#define mp make_pair

using namespace std;

struct edge {
    int s,e;
    int r,c;
    bool start;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,cur[20005],below[20005];
vector<edge> h,v;

bool comph(edge a, edge b) {
    if (a.r == b.r) return a.start > b.start;
    return a.r > b.r;
}

bool compv(edge a, edge b) {
    if (a.c == b.c) return a.start > b.start;
    return a.c < b.c;
}

void transfer() {
    for (int i = 0; i <= 20000; i++) below[i] = cur[i];
}

int main() {
    ofstream fout ("picture.out");
    ifstream fin ("picture.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        int t,b,l,r;
        fin >> l >> b >> r >> t;
        edge hs = {l+add,r+add,b+add,0,0} ,he = {l+add,r+add,t+add,0,1} ,vs = {b+add,t+add,0,l+add,1} ,ve = {b+add,t+add,0,r+add,0};
        h.push_back(hs);
        h.push_back(he);
        v.push_back(vs);
        v.push_back(ve);
    }
    sort(h.begin(),h.end(),comph);
    sort(v.begin(),v.end(),compv);
    N*=2;
    int ans = 0;
    memset(cur,0,sizeof(cur));
    for (int i = 0; i < N; i++) {
        edge e = h[i];
        transfer();
        for (int i = e.s; i < e.e; i++) {
            if (e.start) cur[i]++;
            else cur[i]--;
            if ((cur[i] && !below[i]) || (!cur[i] && below[i])) ans++;
        }
    }
    memset(cur,0,sizeof(cur));
    for (int i = 0; i < N; i++) {
        edge e = v[i];
        transfer();
        for (int i = e.s; i < e.e; i++) {
            if (e.start) cur[i]++;
            else cur[i]--;
            if ((cur[i] && !below[i]) || (!cur[i] && below[i])) ans++;
        }
    }
    fout << ans << endl;
    return 0;
}