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

struct point {
    int pos,height;
    bool start;
};

int N;
map< int,vector<point> > m;
multiset< int,greater<int> > mheights;
long long area = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b,h;
        cin >> a >> b >> h;
        point p1;
        p1.height = h;
        p1.start = 1;
        p1.pos = a;
        point p2;
        p2.height = h;
        p2.start = 0;
        p2.pos = b;
        m[a].push_back(p1);
        m[b].push_back(p2);
    }
    //cout << m.size() << endl;
    map< int,vector<point> >::iterator it;
    for (it = m.begin(); next(it,1) != m.end(); it++) {
        map< int,vector<point> >::iterator it2 = next(it,1);
        int pos = it->first;
        int pos2 = it2->first;
        //cout << pos << " " << pos2 << endl;
        vector<point> v = it->second;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].start) mheights.insert(v[i].height);
            else {
                multiset<int>::iterator it2 = mheights.find(v[i].height);
                mheights.erase(it2);
            }
        }
        if (!mheights.empty()) {
            long long width = pos2-pos;
            long long height = *mheights.begin();
            area += width*height;
        }
        pos = pos2;
        //cout << pos << endl;
    }
    //cout << endl;
    cout << area << endl;
    return 0;
}