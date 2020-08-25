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

struct view {
    int c1,c2;
};

int N,I,H,R;
int height[10001];
vector<view> views;

bool compare1 (view i, view j) {
    return i.c2 > j.c1;
}

bool compare2 (view i, view j) {
    return i.c1 < j.c1;
}

int main() {
    cin >> N >> I >> H >> R;
    for (int i = 1; i <= N; i++) height[i] = H;
    for (int i = 0; i < R; i++) {
        int c1,c2;
        cin >> c1 >> c2;
        if (c1 > c2) swap(c1,c2);
        view v;
        v.c1 = c1;
        v.c2 = c2;
        views.push_back(v);
    }
    stable_sort(views.begin(),views.end(),compare1);
    stable_sort(views.begin(),views.end(),compare2);
    for (int i = 0; i < views.size(); i++) {
        //cout << views[i].c1 << " " << views[i].c2 << endl;
    }
    for (int i = 0; i < views.size(); i++) {
        int c1 = views[i].c1;
        int c2 = views[i].c2;
        for (int i = c1+1; i < c2; i++) {
            height[i] = min(height[c1],height[c2])-1;
        }
    }
    for (int i = 1; i <= N; i++) cout << height[i] << endl;
    return 0;
}