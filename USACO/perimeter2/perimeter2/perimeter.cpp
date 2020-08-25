/*
 ID: yuanmax1
 PROG: perimeter
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

int N,sr = 0,sc = LARGE;
map<int,map<int,bool> > m;
int dc[4] = {1,0,-1,0};
int dr[4] = {0,-1,0,1};

int main() {
    ofstream fout ("perimeter.out");
    ifstream fin ("perimeter.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        int r,c;
        fin >> r >> c;
        if (r > sr || (r == sr && c < sc)) {
            sr = r;
            sc = c;
        }
        m[r][c] = 1;
    }
    int cr = sr, cc = sc, ans = 0, dir = 0;
    do {
        ans++;
        cr += dr[dir];
        cc += dc[dir];
        //cout << cr << " " << cc << endl;
        for (int i = (dir+3)%4; i != (dir+2)%4; i = (i+1)%4) {
            if (i == 0 && m[cr][cc]) {
                dir = 0;
                break;
            }
            if (i == 1 && m[cr][cc-1]) {
                dir = 1;
                break;
            }
            if (i == 2 && m[cr+1][cc-1]) {
                dir = 2;
                break;
            }
            if (i == 3 && m[cr+1][cc]) {
                dir = 3;
                break;
            }
        }
    } while (cr != sr || cc != sc);
    fout << ans << endl;
    return 0;
}