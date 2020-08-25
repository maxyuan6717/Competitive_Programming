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

struct cow {
    int pos,height;
};

int N,D;
vector<cow> cows;
multiset<cow> cowsleft;
multiset<cow> cowsright;

bool compare(cow a, cow b) {
    return a.pos < b.pos;
}

bool operator< (cow a, cow b) {
    return a.height < b.height;
}

int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cow c;
        cin >> c.pos >> c.height;
        cows.push_back(c);
        //cowsleft.insert(c);
    }
    sort(cows.begin(),cows.end(),compare);
    //for (int i = 0; i < N; i++) cout << cows[i].pos << " ";
    //cout << endl;
    int rindx = 0, lindx = 0;
    int ans = 0;
    multiset<cow>::iterator it;
    //for (it = cowsleft.begin(); it != cowsleft.end(); it++) cout << it->height << " ";
    //cout << endl;
    for (int i = 0; i < N; i++) {
        //cout << lindx << " " << rindx << endl;
        cow cur = cows[i];
        int j = 0;
        for (j = lindx; cows[j].pos < cur.pos-D; j++) {
            cowsleft.erase(cowsleft.find(cows[j]));
        }
        lindx = j;
        for (j = rindx; j < N && cows[j].pos <= cur.pos+D; j++) {
            cowsright.insert(cows[j]);
        }
        rindx = j;
        cowsleft.insert(cur);
        cowsright.erase(cowsright.find(cur));
        int product = cur.height*2;
        if (!cowsleft.empty() && !cowsright.empty() && cowsleft.rbegin()->height >= product && cowsright.rbegin()->height >= product) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}