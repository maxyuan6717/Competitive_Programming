/*
 ID: yuanmax1
 PROG: nuggets
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


using namespace std;

int N;
int offers[10] = {0};
int nums[100000] = {0};
int ans = 0;

int main() {
    ofstream fout ("nuggets.out");
    ifstream fin ("nuggets.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> offers[i];
        nums[offers[i]] = 1;
    }
    for (int i = 0; i < 70000; i++) {
        for (int j = 0; j < N; j++) {
            if (i - offers[j] >= 0 && nums[i-offers[j]] == 1) {
                nums[i] = 1;
                break;
            }
        }
        if (nums[i] == 0) ans = i;
    }
    if (ans != 69999)fout << ans << endl;
    else fout << 0 << endl;
    
    return 0;
}