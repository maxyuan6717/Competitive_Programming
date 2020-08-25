/*
 ID: yuanmax1
 PROG: transform
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
char cur[10][10],res[10][10],temp[10][10];
int N,ans = 7;

bool comp() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (cur[i][j] != res[i][j]) return 0;
    return 1;
}

void rot() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) temp[i][j] = cur[i][j];
    for (int j = N-1; j >= 0; j--) for (int i = 0; i < N; i++) cur[i][j] = temp[N-j-1][i];
}

void ref() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N/2; j++) swap(cur[i][j],cur[i][N-j-1]);
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    fin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) fin >> cur[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) fin >> res[i][j];
    if (comp()) ans = 6; ref(); rot();
    if (comp()) ans = 5; rot();
    if (comp()) ans = 5; rot();
    if (comp()) ans = 5; rot();
    if (comp()) ans = 4; ref(); rot(); rot(); rot();
    if (comp()) ans = 3; rot(); rot(); rot();
    if (comp()) ans = 2; rot(); rot(); rot();
    if (comp()) ans = 1;
    fout << ans << endl;
}