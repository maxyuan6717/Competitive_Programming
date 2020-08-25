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

#define LARGE 999999999

using namespace std;

int K,N,M;
int start[1001];
int visited[1001];
vector<int> adjlist[1001];
set<int> s;

void dfs(int cur) {
    visited[cur] = 1;
    s.insert(cur);
    //numvis[cur]++;
    for (int i = 0; i < adjlist[cur].size(); i++) {
        int v = adjlist[cur][i];
        if (!visited[v]) {
            visited[v] = 1;
           // numvis[v]++;
            s.insert(v);
            dfs(v);
        }
    }
}

int main() {
    cin >> K >> N >> M;
    for (int i = 0; i < K; i++) {
        cin >> start[i];
    }
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
    }
    for (int i = 0; i < K; i++) {
        dfs(start[i]);
        for (int i = 0; i <= N; i++) {
            if (!visited[i] && s.find(i) != s.end()) s.erase(s.find(i));
            visited[i] = 0;
        }
    }
    set<int>::iterator it;
    //for (it = s.begin(); it != s.end(); it++) cout << *it << endl;
    cout << s.size() << endl;
    return 0;
}