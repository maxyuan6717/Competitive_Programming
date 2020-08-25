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

int N,c,arr[201][201],visited[201],ans = 0,parent[201];
char s,e;
int M = 52;

int toint(char c) {
    int a = c;
    char ret;
    if (a <= 90) ret = a-64;
    else ret = a-70;
    return ret;
}

int bfs() {
    for (int i = 1; i <= M; i++) {
        visited[i] = 0;
        parent[i] = 0;
    }
    queue <int> q;
    q.push(1);
    visited[1] = 1;
    parent[1] = -1;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 1; i <= M; i++) {
            if (!visited[i] && arr[p][i] > 0) {
                q.push(i);
                visited[i] = 1;
                parent[i] = p;
            }
        }
    }
    return (visited[26] == 1);
}

int ff() {
    while (bfs()) {
        int flow = LARGE;
        for (int i = 26; i != 1; i = parent[i]) {
            int a = parent[i];
            flow = min(flow, arr[a][i]);
        }
        for (int i = 26; i != 1; i = parent[i]) {
            int a = parent[i];
            arr[a][i] -= flow;
            arr[i][a] += flow;
        }
        ans += flow;
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> s >> e >> c;
        int is,ie;
        is = toint(s);
        ie = toint(e);
        //cout << is << " " << ie << endl;
        arr[is][ie] += c;
    }
    ff();
    //cout << ans << endl;
    cout << ans << endl;
    return 0;
}