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

struct enclosure {
    int pos;
    int bigy,smally;
    bool start;
};

typedef pair<int,int> height;

int N;
stack<enclosure> s;
vector<enclosure> epoints;
set<height> heights;
set<height>::iterator it;

bool compare(enclosure a, enclosure b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    else return a.bigy > b.bigy;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        enclosure e1,e2;
        cin >> e1.pos >> e1.smally >> e2.pos >> e2.bigy;
        e1.bigy = e2.bigy;
        e2.smally = e1.smally;
        e1.start = 1;
        e2.start = 0;
        epoints.push_back(e1);
        epoints.push_back(e2);
    }
    sort(epoints.begin(),epoints.end(),compare);
    int ans = N;
    for (int i = 0; i < epoints.size(); i++) {
        //cout << heights.size() << endl;
        height h;
        h.first = epoints[i].bigy;
        h.second = epoints[i].smally;
        //cout << h.first << " " << h.second << endl;
        if (epoints[i].start) {
            it = heights.upper_bound(h);
            //cout << it->first << " " << it->second << endl << endl;
            if (it != heights.end() && it->second < h.second) {
                ans--;
            }
            else {
                heights.insert(h);
            }
        }
        else {
            heights.erase(h);
        }
    }
    cout << ans << endl;
    
    return 0;
}