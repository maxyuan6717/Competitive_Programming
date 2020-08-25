/*
 ID: yuanmax1
 PROG: painting
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

struct enclosure {
    int p,b,t;
    bool start;
    enclosure (int po, int bo, int to, bool st) {
        p = po, b = bo, t = to, start = st;
    }
};

int N,ans;
set<pii> cur;
vector<enclosure> e;

bool comp(enclosure a, enclosure b) {
    if (a.p != b.p) return a.p < b.p;
    return a.t > b.t;
}

int main() {
    ifstream fin ("painting.in");
    ofstream fout ("painting.out");
    fin >> N;
    ans = N;
    for (int i = 0; i < N; i++) {
        int l,b,r,t;
        fin >> l >> b >> r >> t;
        enclosure e1(l,b,t,1);
        enclosure e2(r,b,t,0);
        e.push_back(e1);
        e.push_back(e2);
    }
    sort(e.begin(),e.end(),comp);
    for (int i = 0; i < e.size(); i++) {
        int b = e[i].b, t = e[i].t;
        //cout << e[i].p << " " << b << " " << t << endl;
        if (e[i].start) {
            set<pii>::iterator it = cur.upper_bound(mp(t,b));
            if (it != cur.end() && it->s < b) ans--;
            else cur.insert(mp(t,b));
        }
        else cur.erase(mp(t,b));
    }
    fout << ans << endl;
    return 0;
}