/*
 ID: yuanmax1
 PROG: slowdown
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

int N;
priority_queue< int, vector<int>, greater<int> > dis,tim;

int main() {
    ifstream fin ("slowdown.in");
    ofstream fout ("slowdown.out");
    fin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        int a;
        fin >> c >> a;
        if (c == 'T') tim.push(a);
        else dis.push(a);
    }
    double s = 1, d = 0, t = 0;
    while (!dis.empty() || !tim.empty()) {
        double t1 = LARGE, t2 = LARGE;
        if (!dis.empty()) t1 = s * (dis.top()-d);
        if (!tim.empty()) t2 = tim.top()-t;
        if (t1 < t2) {
            d = dis.top();
            t += t1;
            dis.pop();
        }
        else {
            t = tim.top();
            d += t2/s;
            tim.pop();
        }
        s++;
    }
    t += (1000-d)*s;
    int ans = t + .5;
    fout << ans << endl;
    return 0;
}