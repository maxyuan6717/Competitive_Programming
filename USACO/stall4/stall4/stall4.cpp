/*
 ID: yuanmax1
 PROG: stall4
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>


using namespace std;

int N,M,stalls[201][201],occupied[201],used[201],ans = 0;

int works(int a) {
    for (int i = 1; i <= M; i++) {
        if (!stalls[a][i] || used[i]) continue;
        used[i] = 1;
        if (!occupied[i] || works(occupied[i])) {
            occupied[i] = a;
            return 1;
        }
    }
    return 0;
}

int f() {
    for (int i = 1; i <= M; i++) {
        occupied[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            used[j] = 0;
        }
        ans += works(i);
    }
    return ans;
}


int main() {
    ofstream fout ("stall4.out");
    ifstream fin ("stall4.in");
    fin >> N >> M;
    int num;
    for (int i = 1; i <= N; i++) {
        fin >> num;
        for (int j = 0; j < num; j++) {
            int stall;
            fin >> stall;
            stalls[i][stall] = 1;
        }
    }
    int print = f();
    fout << print << endl;
    //cout << print << endl;
    return 0;
}