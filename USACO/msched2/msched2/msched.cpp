/*
 ID: yuanmax1
 PROG: msched
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
    int g,t;
};

int N;
vector<int> arr[10001];

int main() {
    ifstream fin ("msched.in");
    ofstream fout ("msched.out");
    fin >> N;
    int maxT = 0;
    for (int i = 0; i < N; i++) {
        int g,t;
        fin >> g >> t;
        maxT = max(maxT,t);
        arr[t].push_back(g);
    }
    priority_queue<int> p;
    int ans = 0;
    for (int i = maxT; i >= 1; i--) {
        for (int j = 0; j < arr[i].size(); j++) p.push(arr[i][j]);
        if (!p.empty()) {
            ans += p.top();
            p.pop();
        }
        //cout << ans << endl;
    }
    fout << ans << endl;
    return 0;
}