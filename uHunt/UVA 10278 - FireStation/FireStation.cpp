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

using namespace std;

#define LARGE 999999

int f[101];
int dis[501][501];
int F,N;

void init() {
    	for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            dis[i][j] = LARGE;
        dis[i][i] = 0;
    }
}
void floyd() {
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
}

int main()
{
    int caseNum;
    cin >> caseNum;
    while (caseNum--)
    {
        cin >> F >> N;
        for (int i = 0; i < F; ++i) cin >> f[i];
        init();
        string str; getline(cin, str);
        while (getline(cin, str) && !str.empty()) {
            stringstream ss(str);
            int u, v, l;
            ss >> u >> v >> l;
            dis[u][v] = l;
            dis[v][u] = l;
        }
        floyd();
        int minl[501];
        int maxl = 0;
        for (int i = 1; i <= N; ++i) {
            minl[i] = LARGE;
            for (int j = 0; j < F; ++j) minl[i] = min(minl[i], dis[i][f[j]]);
            maxl = max(maxl, minl[i]);
        }

        int ans = 1;
        for (int i = 1; i <= N; ++i) {
            int newl = 0;
            for (int j = 1; j <= N; ++j) {
                int shorter = min(dis[i][j], minl[j]);
                newl = max(newl, shorter);
            }
            if (newl< maxl) {
                maxl = newl;
                ans = i;
            }
        }
        cout << ans << endl;
        if (caseNum) cout << endl;
    }
}
