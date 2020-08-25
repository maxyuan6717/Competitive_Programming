/*
 ID: yuanmax1
 PROG: schlnet
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

int N;
int arr[101][101];
int arrscc[101][101];
int transpose[101][101];
int visited[101];
int indeg[101];
int outdeg[101];
int scc[101];
int counter = 0;
int in0 = 0;
int out0 = 0;

void dfs(int cur) {
    visited[cur] = 1;
    for (int i = 1; i <= N; i++) {
        if (arr[cur][i] && !visited[i]) dfs(i);
    }
}

void tdfs(int cur) {
    scc[cur] = counter;
    for (int i = 1; i <= N; i++) {
        if (transpose[cur][i] && visited[i] && !scc[i]) tdfs(i);
    }
}

int subprob1() {
    int ans;
    for (int i = 1; i <= N; i++) {
        if (!scc[i]) {
            dfs(i);
            counter++;
            tdfs(i);
            for (int j = 1; j<=N+1; j++) visited[j] = 0;
        }
    }
    if (counter == 1) {
        ans = 1;
        in0 = 0;
        out0 = 0;
        return ans;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j]) arrscc[scc[i]][scc[j]] = 1;
        }
    }
    for (int i = 1; i <= counter; i++) {
        for (int j = 1; j <= counter; j++) {
            if (i!=j && arrscc[i][j]) {
                indeg[j]++;
                outdeg[i]++;
            }
        }
    }
    for (int i = 1; i <= counter; i++) {
        if (indeg[i] == 0) in0++;
        if (outdeg[i] == 0) out0++;
    }
    ans = in0;
    return ans;
}

int subprob2() {
    int ans = 0;
    ans = max(in0,out0);
    return ans;
}

int main() {
    ofstream fout ("schlnet.out");
    ifstream fin ("schlnet.in");
    fin >> N;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            arr[i][j] = 0;
            transpose[i][j] = 0;
            arrscc[i][j] = 0;
        }
        scc[i] = 0;
        indeg[i] = 0;
        outdeg[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        int num;
        fin >> num;
        while(num != 0) {
            arr[i][num] = 1;
            transpose[num][i] = 1;
            fin >> num;
        }
    }
    int ans1 = subprob1();
    int ans2 = subprob2();
    fout << ans1 << endl;
    cout << ans1 << endl;
    fout << ans2 << endl;
    cout << ans2 << endl;
    
    return 0;
}