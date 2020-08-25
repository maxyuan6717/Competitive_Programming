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

struct rock {
    int pos;
};

bool comp(rock a, rock b) {
    return a.pos < b.pos;
}

int L,N,M;
vector<rock> rocks;

int numremove(int goal) {
    int ret = 0;
    int prev = 0;
    for (int i = 0; i < N; i++) {
        //cout << ret << " " << rocks[i].pos;
        if (rocks[i].pos-prev < goal) {
            ret++;
        }
        else {
            prev = rocks[i].pos;
        }
    }
    //cout << endl;
    return ret;
}

int main() {
    cin >> L >> N >> M;
    for (int i = 0; i < N; i++) {
        rock r;
        cin >> r.pos;
        rocks.push_back(r);
    }
    sort(rocks.begin(),rocks.end(),comp);
    int ans = 0;
    //for (int i = 0; i <= N; i++) cout << jumps[i].dist << " ";
    //cout << endl;
    int start = 0, end = L;
    while (start < end) {
        //cout << start << " " << end << endl;
        int mid = (start+end+1)/2;
        int m = numremove(mid);
        //cout << m << " " << mid << endl;
        if (m > M) {
            end = mid-1;
        }
        else {
            start = mid;
        }
    }
    ans = end;
    cout <<  ans << endl;
    /*for (int i = 0; i <= N; i++) {
        cout << jumps[i].dist << " ";
    }
    cout << endl;*/
    return 0;
}