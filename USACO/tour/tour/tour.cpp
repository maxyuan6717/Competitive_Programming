/*
 ID: yuanmax1
 PROG: tour
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

#define LARGE 9999999

using namespace std;

int N,V;
map<string,int> m;
int arr[100][100];
int dp[100][100];
int ans = 1;

int main() {
    ofstream fout ("tour.out");
    ifstream fin ("tour.in");
    fin >> N >> V;
    for (int i = 0; i < N; i++) {
        string s;
        fin >> s;
        m[s] = i;
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < V; i++) {
        string s1,s2;
        fin >> s1 >> s2;
        int i1 = m[s1];
        int i2 = m[s2];
        arr[i1][i2] = 1;
        arr[i2][i1] = 1;
    }
    dp[0][0] = 1;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = 0; k < j; k++) {
                if (arr[k][j] && dp[i][k] > 0 && dp[i][k] > dp[i][j]) {
                    dp[i][j] = dp[i][k];
                }
            }
            dp[i][j]++;
            dp[j][i] = dp[i][j];
            if (j == N-1 && arr[i][j] && dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout << ans << endl;
    fout << ans << endl;
    return 0;
}