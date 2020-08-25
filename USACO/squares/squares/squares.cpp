/*
 ID: yuanmax1
 PROG: squares
 LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct pnt {
    int x,y;
    bool start;
    pnt(int x1, int y1, bool st) {
        x = x1, y = y1, start = st;
    }
};

int N,K,k;
map<int, vector<pnt> > line;
set<pii> cur;

int main() {
    ofstream fout ("squares.out");
    ifstream fin ("squares.in");
    fin >> N >> K;
    k = K/2;
    line.clear();
    for (int i = 0; i < N; i++) {
        int x,y;
        fin >> x >> y;
        pnt p1(x-k,y,1);
        pnt p2(x+k,y,0);
        line[x-k].push_back(p1);
        line[x+k].push_back(p2);
    }
    map<int, vector<pnt> >::iterator it;
    bool works = 1;
    int ans = 0;
    for (it = line.begin(); it != line.end(); it++) {
        //cout << it->first << endl;
        vector<pnt> v = it->second;
        for (int i = 0; i < v.size(); i++) {
            //cout << v[i].x << " " << v[i].y << endl;
            if (!v[i].start) cur.erase(cur.find(mp(v[i].x-K,v[i].y)));
            if (v[i].start) {
                set<pii>::iterator sit;
                for (sit = cur.begin(); sit != cur.end(); sit++) {
                    pii p = *sit;
                    if (abs(v[i].y-p.second) < K) {
                        int dx = abs(v[i].x - p.first), dy = abs (v[i].y - p.second);
                        int x = 2*(k-dx) + dx, y = 2*(k-dy) + dy;
                        if (x*y && ans != 0) {
                            //cout << ans << endl;
                            //cout << p.first << " " << p.second << " " << v[i].x << " " << v[i].y << endl;
                            works = 0;
                            break;
                        }
                        ans = max(ans,x*y);
                        //cout << ans << " " << p.first << " " << p.second << " " << v[i].x << " " << v[i].y << endl;
                    }
                }
                if (!works) break;
                cur.insert(mp(v[i].x,v[i].y));
            }
        }
        if (!works) break;
    }
    if (works) fout << ans << endl;
    else fout << -1 << endl;
    return 0;
}