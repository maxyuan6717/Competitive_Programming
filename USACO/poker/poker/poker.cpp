/*
 ID: yuanmax1
 PROG: poker
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

struct interval {
    int l,r,x;
    interval(int left, int right, int used) {
        l = left, r = right, x = used;
    }
};

int N,arr[100001];
queue<interval> v;
long long ans = 0;

int main() {
    ifstream fin ("poker.in");
    ofstream fout ("poker.out");
    fin >> N;
    int l = 1,i;
    for (i = 1; i <= N; i++) {
        fin >> arr[i];
        if (!arr[i] && l < i) {
            interval in(l,i-1,0);
            v.push(in);
            l = i+1;
        }
        if (!arr[i]) l = i+1;
    }
    if (l < i) {
        interval in(l,i-1,0);
        v.push(in);
    }
    while (!v.empty()) {
        int temp = (int)v.size();
        for (i = 0; i < temp; i++) {
            interval cur = v.front();
            v.pop();
            int l = cur.l, r = cur.r, x = cur.x;
            int rem = LARGE,j;
            for (j = l; j <= r; j++) {
                rem = min(rem, arr[j]-x);
            }
            ans += rem;
            x += rem;
            int a = l;
            for (j = l; j <= r; j++) {
                if (!(arr[j]-x) && a < j) {
                    interval in(a,j-1,x);
                    v.push(in);
                    a = j+1;
                }
                if (!(arr[j]-x)) a = j+1;
            }
            if (a < j) {
                interval in(a,j-1,x);
                v.push(in);
            }
        }
    }
    fout << ans << endl;
    return 0;
}