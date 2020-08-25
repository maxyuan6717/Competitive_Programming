/*
 ID: yuanmax1
 PROG: crowded
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

struct cow {
    int p,h;
};

int N,D;
cow cows[50000];
bool arr[50000];

bool comp(cow a, cow b) {
    return a.p < b.p;
}

bool operator<(cow a, cow b) {
    return a.h > b.h;
}

int main() {
    ifstream fin ("crowded.in");
    ofstream fout ("crowded.out");
    fin >> N >> D;
    for (int i = 0; i < N; i++) fin >> cows[i].p >> cows[i].h;
    sort(cows,cows+N,comp);
    set<cow> s;
    for (int i = 0; i < N; i++) {
        while (!s.empty() && cows[i].p - s.begin()->p > D) s.erase(s.begin());
        s.insert(cows[i]);
        if (s.begin()->h >= 2*cows[i].h) arr[i] = 1;
    }
    s.clear();
    int ans = 0;
    for (int i = N-1; i >= 0; i--) {
        while (!s.empty() && s.begin()->p-cows[i].p > D) s.erase(s.begin());
        s.insert(cows[i]);
        if (arr[i] && s.begin()->h >= 2*cows[i].h) ans++;
    }
    fout << ans << endl;
    return 0;
}