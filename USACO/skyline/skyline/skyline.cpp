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

struct building{
    int x,y;
};

int N,W;
vector<building> buildings;
int hends[500001];

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        building b;
        cin >> b.x >> b.y;
        buildings.push_back(b);
    }
    building e;
    e.x = W;
    e.y = 0;
    buildings.push_back(e);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        building cur = buildings[i];
        if (hends[cur.y] > cur.x) continue;
        for (int j = i+1; j <= N; j++) {
            building next = buildings[j];
            if (next.y < cur.y) {
                hends[cur.y] = next.x;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}