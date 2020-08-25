/*
 ID: yuanmax1
 PROG: shuffle
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

int N,M,Q,arr[100000];

int main() {
    ifstream fin ("shuffle.in");
    ofstream fout ("shuffle.out");
    fin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        fin >> arr[i];
        arr[i]--;
    }
    return 0;
}