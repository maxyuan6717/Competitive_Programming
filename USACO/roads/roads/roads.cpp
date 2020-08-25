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
#include <iomanip>

#define LARGE 999999999

using namespace std;

struct farm {
    long long x,y;
};

int N,M;
farm farms[1001];
long double distances[1001][1001];
long parent[1001];
long double key[1001];
bool mst[1001];

long double dist(farm a, farm b) {
    long double ret = ((a.y-b.y)*(a.y-b.y)) + ((a.x-b.x)*(a.x-b.x));
    return sqrt(ret);
}

int findmin() {
    double min = LARGE;
    int minindex = 0;
    for (int i = 0; i < N; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            minindex = i;
        }
    }
    return minindex;
}



int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x,y;
        cin >> x >> y;
        farm f;
        f.x = x;
        f.y = y;
        farms[i] = f;
        key[i] = LARGE;
        mst[i] = 0;
        for (int j = 0; j < N; j++) {
            distances[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            distances[i][j] = dist(farms[i],farms[j]);
            distances[j][i] = distances[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int c1,c2;
        cin >> c1 >> c2;
        distances[c1-1][c2-1] = 0;
        distances[c2-1][c1-1] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < N-1; i++) {
        int v = findmin();
        mst[v] = 1;
        for (int j = 0; j < N; j++) {
            if (distances[v][j] != -1 && !mst[j] && distances[v][j] < key[j]) {
                key[j] = distances[v][j];
                parent[j] = v;
            }
        }
    }
    long double sum = 0;
    for (int i = 1; i < N; i++) {
        sum += distances[i][parent[i]];
        //cout << sum << " " << i << endl;
        //cout << i << " " << parent[i] << " " << sum << endl;
    }
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}