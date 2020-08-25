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
    double x,y;
};

struct mid {
    double x,y;
};

int N;
vector<cow> cows;
vector<mid> midpoints;
map<pair<double,double>,int> counter;

int comb( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    
    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cow c;
        cin >> c.x >> c.y;
        cows.push_back(c);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            cow c1 = cows[i];
            cow c2 = cows[j];
            double c1x = c1.x, c1y = c1.y;
            double c2x = c2.x, c2y = c2.y;
            mid m;
            m.x = (c1x + c2x)/2;
            m.y = (c1y + c2y)/2;
            counter[make_pair(m.x,m.y)]++;
        }
    }
    int ans = 0;
    map<pair<double,double>,int>::iterator it;
    for (it = counter.begin(); it != counter.end(); it++) {
        if (it->second < 2) continue;
        ans += comb(it->second,2);
    }
    
    cout << ans << endl;
    
    return 0;
}