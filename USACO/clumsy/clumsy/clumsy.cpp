/*
 ID: yuanmax1
 PROG: CHANGE
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

string s;
int N,ans,open,closed;

int main() {
    ofstream fout ("clumsy.out");
    ifstream fin ("clumsy.in");
    fin >> s;
    N = (int)s.length();
    for (int i = 0; i < N; i++) {
        if (s[i] == '(') open++;
        else {
            closed++;
            if (open < closed) {
                ans++;
                closed--;
                open++;
                s[i] = '(';
            }
        }
    }
    int extra = open - closed;
    fout << ans + extra/2 << endl;
    return 0;
}