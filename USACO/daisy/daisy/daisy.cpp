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

int N,M;
int arr[251][251];
int visited[251];

void dfs(int cur) {
    for (int i = 1; i <= N; i++) {
        if (arr[cur][i] && !visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
        for (int j = 0; j <= N; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int c1,c2;
        cin >> c1 >> c2;
        arr[c1][c2] = 1;
        arr[c2][c1] = 1;
    }
    dfs(1);
    int none = 1;
    for (int i = 2; i <= N; i++) {
        if (!visited[i]) cout << i << endl, none = 0;
    }
    if (none) cout << 0 << endl;
    
    return 0;
}