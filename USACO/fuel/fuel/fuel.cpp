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

struct station {
    int pos;
    long long price;
};

int N,G,B,D;
vector<station> stations;
int closest[500001];

bool compare(station a, station b) {
    return a.pos < b.pos;
}

int main() {
    cin >> N >> G >> B >> D;
    for (int i = 0; i < N; i++) {
        station s;
        cin >> s.pos >> s.price;
        stations.push_back(s);
    }
    sort(stations.begin(),stations.end(),compare);
    stack<int> s;
    s.push(N-1);
    closest[N-1] = -1;
    for (int i = N-2; i >= 0; i--) {
        while (!s.empty() && stations[s.top()].price >= stations[i].price) s.pop();
        if (s.empty()) {
            s.push(i);
            closest[i] = -1;
        }
        else {
            closest[i] = s.top();
            s.push(i);
        }
    }
    //for (int i = 0; i < N; i++) cout << closest[i] << " ";
    //cout << endl;
    long long gas = B;
    long long ans = 0;
    gas -= stations[0].pos;
    if (gas < 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        long long need;
        station cur = stations[i];
        if (closest[i] != -1) need = stations[closest[i]].pos - cur.pos;
        else need = D - cur.pos;
        if (need > G) need = G;
        //cout << i << " " << gas << " " << need << endl;
        if (need > gas) {
            ans += cur.price*(need-gas);
            gas = need;
        }
        if (i != N-1) gas -= (stations[i+1].pos-cur.pos);
        else gas -= (D-cur.pos);
        if (gas < 0) {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}