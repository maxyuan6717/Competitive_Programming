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

struct cow {
    int h,v,index;
    long long total;
};

int N;
long long ans = 0;
cow thecow;

int main() {
    cin >> N;
    cow arr[50000];
    stack<cow> s;
    for (int i = 0; i < N; i++) {
        int h,v;
        cin >> h >> v;
        cow c;
        c.h = h;
        c.v = v;
        c.index = i;
        arr[i] = c;
        if (s.empty()) s.push(c);
        else if (s.top().h > c.h) {
            s.top().total += c.v;
            arr[s.top().index].total += c.v;
            if (s.top().total > ans) {
                ans = s.top().total;
                //thecow = s.top();
            }
            s.push(c);
        }
        else {
            while (!s.empty() && s.top().h < c.h) s.pop();
            if (s.empty()) s.push(c);
            else {
                s.top().total += c.v;
                arr[s.top().index].total += c.v;
                if (s.top().total > ans) {
                    ans = s.top().total;
                    //thecow = s.top();
                }
                s.push(c);
            }
        }
    }
    //cout << thecow.h << " " <<  ans << endl;
    while (!s.empty()) s.pop();
    for (int i = N-1; i >= 0; i--) {
        cow c = arr[i];
        if (s.empty()) s.push(c);
        else if (s.top().h > c.h) {
            s.top().total += c.v;
            if (s.top().total > ans) ans = s.top().total;
            s.push(c);
        }
        else {
            while (!s.empty() && s.top().h < c.h) s.pop();
            if (s.empty()) s.push(c);
            else {
                s.top().total += c.v;
                if (s.top().total > ans) ans = s.top().total;
                s.push(c);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}