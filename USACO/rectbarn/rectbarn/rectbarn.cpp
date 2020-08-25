/*
 ID: yuanmax1
 PROG: rectbarn
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

int R,C,P;
bool arr[3000][3000];
int row[3000];

int maxHist() {
    int s[3005],indx = 0;
    int topVal,ret = 0;
    int i = 0;
    while (i < C) {
        int cur = row[i];
        if(!indx || cur >= row[s[indx-1]]) s[indx++] = i++;
        else {
            topVal = row[s[indx-1]];
            indx--;
            int area;
            if (!indx) area = topVal * i;
            else area = topVal * (i-s[indx-1]-1);
            ret = max(ret,area);
        }
    }
    while (indx) {
        topVal = row[s[indx-1]];
        indx--;
        int area;
        if (!indx) area = topVal * i;
        else area = topVal * (i-s[indx-1]-1);
        ret = max(ret,area);
    }
    return ret;
}

int main() {
    ofstream fout ("rectbarn.out");
    ifstream fin ("rectbarn.in");
    fin >> R >> C >> P;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            arr[i][j] = 1;
    for (int i = 0; i < P; i++) {
        int r,c;
        fin >> r >> c;
        arr[r-1][c-1] = 0;
    }
    for (int i = 0; i < C; i++) row[i] = arr[0][i];
    int ans = maxHist();
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j]) row[j]++;
            else row[j]  = 0;
        }
        ans = max(ans,maxHist());
    }
    
    fout << ans << endl;
    return 0;
}