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
#define gr (1 + sqrt(5))/2

using namespace std;

int M,N,T;
string ans[2] = {"Bessie","Farmer John"};
set<pair<int,int>> lose;

int main() {
    cin >> M >> N >> T;
    int losex = 0,losey = 0,counter = 0;
    while (losex <= M && losey <= N) {
        losex = floor(counter*gr);
        losey = floor(counter*pow(gr,2));
        lose.insert(\make_pair(losex,losey));
        counter++;
    }
    for (int i = 0; i < T; i++) {
        int sx,sy;
        cin >> sx >> sy;
        pair<int,int> p;
        p.first = min(sx,sy);
        p.second = max(sx,sy);
        cout << ans[(lose.find(p) != lose.end())] << endl;
    }
    return 0;
}