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

struct turn {
    int pos, lim;
};

int L,N;
vector<turn> turns;

bool compare(turn a, turn b) {
    return a.pos < b.pos;
}

pair<int,pair<int,int>> maxspeed(int p, int s, int t) {
    turn cur = turns[t];
    pair<int,pair<int,int>> ret;
    int dist;
    dist = cur.pos-p;
    if (s + dist < turns[t].lim) {
        ret.first = s+dist;
        ret.second.first = cur.pos;
        ret.second.second = s+dist;
        return ret;
    }
    ret.first = ((dist+s+turns[t].lim)/2);
    ret.second.first = cur.pos;
    ret.second.second = cur.lim;
    return ret;
}

int main() {
    cin >> L >> N;
    turn last;
    last.pos = L;
    last.lim = LARGE;
    turns.push_back(last);
    for (int i = 0; i < N; i++) {
        turn t;
        cin >> t.pos >> t.lim;
        turns.push_back(t);
    }
    sort(turns.begin(),turns.end(),compare);
    int p = 0;
    int s = 1;
    int ans = 0;
    for (int i = N; i > 0; i--) {
        if (turns[i].lim + (turns[i].pos-turns[i-1].pos) < turns[i-1].lim) {
            turns[i-1].lim = turns[i].lim + (turns[i].pos-turns[i-1].pos);
        }
    }
    for (int i = 0; i <= N; i++) {
        pair<int,pair<int,int>> result = maxspeed(p,s,i);
        int speed = result.first;
        ans = max(ans,speed);
        p = result.second.first;
        s = result.second.second;
        //cout << speed << " ";
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}