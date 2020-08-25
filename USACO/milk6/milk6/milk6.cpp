/*
 ID: yuanmax1
 PROG: milk6
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

#define LARGE 9999999999


using namespace std;

int N,M;
pair<long long,vector<int> > arr[33][33];
long long residual[33][33];
int parent[33];
int visited[33];
int edge[33][33];
vector<int> current;
vector<int> temp;

void reset() {
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
}

int bfs() {
    reset();
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    parent[1] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = N; i >= 0; i--) {
            if (residual[u][i] > 0 && !visited[i] && edge[u][i]) {
                q.push(i);
                visited[i] = 1;
                parent[i] = u;
            }
        }
    }
    return visited[N];
}

void dfs(int cur) {
    visited[cur] = 1;
    for (int i = 1; i <= N; i++) {
        if (residual[cur][i] > 0 && !visited[i] && edge[cur][i]) {
            dfs(i);
        }
    }
}

int ff() {
    int maxflow = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            residual[i][j] = arr[i][j].first;
        }
    }
    while (bfs()) {
        long long flow = LARGE;
        for (int i = N; i != 1; i = parent[i]) {
            int j = parent[i];
            //cout << i << " " << j << endl;
            flow = min(flow,residual[j][i]);
        }
        for (int i = N; i != 1; i = parent[i]) {
            int j = parent[i];
            residual[i][j] += flow;
            residual[j][i] -= flow;
        }
        //cout << flow << endl;
        maxflow+=flow;
    }
    return maxflow;
}

int main() {
    ofstream fout ("milk6.out");
    ifstream fin ("milk6.in");
    fin >> N >> M;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            arr[i][j].first = 0;
            residual[i][j] = -1;
            edge[i][j] = 1;
        }
    }
    for (int i = 1; i <= M; i++) {
        int s,e,c;
        fin >> s >> e >> c;
        //arr[s][e] = make_pair(c*1001+1,i);
        arr[s][e].first += c*1001+100+i;
        arr[s][e].second.push_back(i);
        edge[s][e] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            residual[i][j] = arr[i][j].first;
        }
    }
    long long mflow = ff();
    //cout << mflow << endl;
    mflow = mflow;
    //cout <<mflow << endl;
    reset();
    dfs(1);
    //for (int i = 1; i <= N; i++) cout << visited[i] << " ";
    //cout << endl;
    long long ans = 0;
    int indexsum = 0;
    vector<int> ans2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i] && !visited[j] && arr[i][j].first > -1) {
                ans += arr[i][j].first;
                for (int k = 0; k < arr[i][j].second.size(); k++) {
                    ans2.push_back(arr[i][j].second[k]);
                    indexsum+=arr[i][j].second[k];
                }
            }
        }
    }
    sort(ans2.begin(),ans2.end());
    long long len = ans2.size();
    fout << (ans-len*100-indexsum)/1001 << " " << len << endl;
    cout << (ans-len*100-indexsum)/1001  << " "<< len << endl;
    for (int i = 0; i < len; i++) {
        //cout << ans2[i] << endl;
        fout << ans2[i] << endl;
    }
    
    
    return 0;
}