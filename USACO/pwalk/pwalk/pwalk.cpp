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

int N,Q;
int arr[1001][1001];
int dist[1001];
int visited[1001];
int start,ending;
int ans,done,temp;

void dfs(int cur) {
    if (cur == ending) {
        ans = temp;
        done = 1;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (arr[cur][i] && !visited[i] && !done) {
            visited[i] = 1;
            temp += arr[cur][i]; 
            dfs(i);
            visited[i] = 0;
            temp -= arr[cur][i];
        }
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N-1; i++) {
        int p1,p2,l;
        cin >> p1 >> p2 >> l;
        arr[p1][p2] = l;
        arr[p2][p1] = l;
    }
    for (int i = 0; i < Q; i++) {
        cin >> start >> ending;
        ans = 0;
        done = 0;
        temp = 0;
        for (int i = 1; i <= N; i++) visited[i] = 0;
        visited[start] = 1;
        dfs(start);
        cout << ans << endl;
    }
    return 0;
}