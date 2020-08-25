/*
 ID: yuanmax1
 PROG: paint
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

int N,K;
pii arr[200000];

int main() {
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");
    fin >> N >> K;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        int d,dir;
        char c;
        fin >> d >> c;
        dir = (c == 'L') ? -1 : 1;
        arr[2*i] = mp(max(cur,cur+dir*d),-1);
        arr[2*i+1] = mp(min(cur,cur + dir*d),1);
        cur += dir*d;
    }
    sort(arr,arr+2*N);
    int layers = arr[0].second;
    int ans = 0;
    for (int i = 1; i < 2*N; i++) {
        //cout << arr[i].first << endl;
        if (layers >= K) ans += arr[i].first - arr[i-1].first;
        layers += arr[i].second;
    }
    fout << ans << endl;
    return 0;
}
