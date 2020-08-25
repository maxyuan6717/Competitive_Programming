/*
 ID: yuanmax1
 PROG: charrec
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

#define LARGE 999999999

using namespace std;

char letter(int x) {
    if (!x) return ' ';
    else return x-1+'a';
}

bool chars[27][21][21];
bool input[1201][21];
int dis[27][21][1201];
int par[1201], dp[1201], ans[1201];
int N;
double lim = .3;

ofstream fout ("charrec.out");

void print(int x) {
    //cout << x << " " << par[x] << endl;
    if (par[x] == -1) {
        return;
    }
    if (ans[x] == -1) {
        int nxt = 0,small = LARGE;
        if (dp[x-19] != LARGE && dp[x-19] < small) {
            small = dp[x-19];
            nxt = x-19;
        }
        if (dp[x-20] != LARGE && dp[x-20] < small) {
            small = dp[x-20];
            nxt = x-20;
        }
        if (dp[x-21] != LARGE && dp[x-21] < small) {
            small = dp[x-21];
            nxt = x-21;
        }
        print(nxt);
        fout << '?';
        return;
    }
    print(par[x]);
    fout << letter(ans[x]);
}

int main() {
    ifstream fin ("charrec.in");
    ifstream fin2 ("font.in");
    fin2 >> N;
    memset(ans,-1,sizeof(ans));
    for (int c = 0; c < 27; c++) {
        for (int i = 0; i < 20; i++) {
            string s;
            fin2 >> s;
            for (int j = 0; j < 20; j++) {
                chars[c][i][j] = s[j]-'0';
            }
        }
    }
    fin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        fin >> s;
        for (int j = 0; j < 20; j++) {
            input[i][j] = s[j]-'0';
        }
    }
    for (int c = 0; c < 27; c++) {
        for (int i = 0; i < 20; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 0; k < 20; k++) {
                    if (chars[c][i][k] != input[j][k]) dis[c][i][j]++;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) dp[i] = LARGE;
    par[0] = -1;
    for (int i = 19; i <= N; i++) {
        for (int c = 0; c < 27; c++) {
            int dif;
            int s;
            if (dp[i-19] != LARGE) {
                s = i-18;
                dif = LARGE;
                for (int a = 0; a < 20; a++) {
                    int b = s;
                    int cur = 0;
                    for (int j = 0; j < 20; j++) {
                        if (a == j) continue;
                        cur += dis[c][j][b++];
                    }
                    dif = min(dif,cur);
                }
                if (dif/400.0 <= lim && dp[i-19] + dif < dp[i]) {
                    dp[i] = dp[i-19] + dif;
                    ans[i] = c;
                    par[i] = i-19;
                }
            }
        
            if (i > 19 && dp[i-20] != LARGE) {
                s = i-19;
                dif = 0;
                for (int j = 0; j < 20; j++) {
                    dif += dis[c][j][s+j];
                }
                if (dif/400.0 <= lim && dp[i-20] + dif < dp[i]) {
                    dp[i] = dp[i-20] + dif;
                    ans[i] = c;
                    par[i] = i-20;
                }
            }
        
            if (i > 20 && dp[i-21] != LARGE) {
                s = i-20;
                dif = LARGE;
                for (int a = 0; a < 20; a++) {
                    int b = s;
                    int cur = 0;
                    for (int j = 0; j < 20; j++) {
                        if (a == j) b++;
                        cur += dis[c][j][b++];
                    }
                    dif = min(dif,cur);
                }
                if (dif/400.0 <= lim && dp[i-21] + dif < dp[i]) {
                    dp[i] = dp[i-21] + dif;
                    ans[i] = c;
                    par[i] = i-21;
                }
            }
            //cout << letter(c) << " " << dp[i] << endl;
        }
    }
    print(N);
    fout << endl;
    return 0;
}