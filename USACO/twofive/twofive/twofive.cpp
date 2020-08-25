/*
 ID: yuanmax1
 PROG: twofive
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

ofstream fout ("twofive.out");
ifstream fin ("twofive.in");

char type,rows[5],cols[5];
int M,dp[6][6][6][6][6];
bool used[91];
string s;

int calc (int a, int b , int c, int d, int e, char ch) {
    if (dp[a][b][c][d][e]) return dp[a][b][c][d][e];
    if (used[ch]) return dp[a][b][c][d][e] = calc(a,b,c,d,e,ch+1);
    int sum = 0;
    if (a < 5 && ch > max(rows[0],cols[a])) sum += calc(a+1,b,c,d,e,ch+1);
    if (b < a && ch > max(rows[1],cols[b])) sum += calc(a,b+1,c,d,e,ch+1);
    if (c < b && ch > max(rows[2],cols[c])) sum += calc(a,b,c+1,d,e,ch+1);
    if (d < c && ch > max(rows[3],cols[d])) sum += calc(a,b,c,d+1,e,ch+1);
    if (e < d && ch > max(rows[4],cols[e])) sum += calc(a,b,c,d,e+1,ch+1);
    return dp[a][b][c][d][e] = sum;
}

void reset() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                for (int l = 0; l < 6; l++) {
                    for (int m = 0; m < 6; m++) {
                        dp[i][j][k][l][m] = 0;
                    }
                }
            }
        }
    }
    dp[5][5][5][5][5] = 1;
}

string typeN() {
    fin >> M;
    string ans(25,' ');
    int arr[5];
    int sum = 0,cur;
    char c;
    for (char i = 'A'; i < 'Z'; i++) used[i] = 0;
    for (int i = 0; i < 5; i++) {
        cols[i] = rows[i] = '0';
        arr[i] = 0;
    }
    for (int i = 0; i < 25; i++) {
        arr[i/5]++;
        for (c = 'A'; c < 'Z'; c++) {
            if (used[c] || c < rows[i/5] || c < cols[i%5]) continue;
            used[c] = 1;
            rows[i/5] = cols[i%5] = c;
            reset();
            cur = calc(arr[0],arr[1],arr[2],arr[3],arr[4],'A');
            if (cur + sum >= M) break;
            sum += cur;
            used[c] = 0;
        }
        ans[i] = c;
    }
    return ans;
}

int typeW() {
    fin >> s;
    int arr[5],ans = 1;
    char c;
    for (char i = 'A'; i < 'Z'; i++) used[i] = 0;
    for (int i = 0; i < 5; i++) {
        cols[i] = rows[i] = '0';
        arr[i] = 0;
    }
    for (int i = 0; i < 25; i++) {
        arr[i/5]++;
        for (c = 'A'; c < s[i]; c++) {
            if (used[c] || c < rows[i/5] || c < cols[i%5]) continue;
            used[c] = 1;
            rows[i/5] = cols[i%5] = c;
            reset();
            ans += calc(arr[0],arr[1],arr[2],arr[3],arr[4],'A');
            used[c] = 0;
        }
        used[c] = 1;
        rows[i/5] = cols[i%5] = c;
    }
    return ans;
}

int main() {
    fin >> type;
    if (type == 'N') fout << typeN() << endl;
    else fout << typeW() << endl;
    return 0;
}