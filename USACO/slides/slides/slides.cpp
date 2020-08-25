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
int platforms[10001];
map<int,int> indeg;
map<int,int> outdeg;

int main() {
    ifstream fin("test.in");
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> platforms[i];
    }
    for(int i = 0; i < M; i++) {
        int in,out;
        cin >> out >> in;
        out = platforms[out];
        in = platforms[in];
        if (out == in) continue;
        outdeg[out]++;
        indeg[in]++;
        if (outdeg[in] > 0) outdeg[in]--,indeg[in]--;
        if (indeg[out] > 0) indeg[out]--,outdeg[out]--;
    }
    map<int,int>::iterator it1 = outdeg.begin();
    map<int,int>::iterator it2 = indeg.begin();
    int ans = 0;
    while (it1!=outdeg.end()) {
        if (it1->second>0 && it2->second>0) {
            ans += abs(it1->first - it2->first);
            it1->second--;
            it2->second--;
        }
        if (!it1->second) it1++;
        if (!it2->second) it2++;
    }
    cout << ans << endl;
    return 0;
}