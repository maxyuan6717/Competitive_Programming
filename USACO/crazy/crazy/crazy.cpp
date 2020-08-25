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

struct fence {
    int x1,y1;
    int x2,y2;
};

struct cow {
    int x,y;
};

int N,C;

vector<fence> fences;
vector<cow> cows;

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        fence f;
        cin >> f.x1 >> f.y1 >> f.x2 >> f.y2;
        fences.push_back(f);
    }
    for (int i = 0; i < C; i++) {
        cow c;
        cin >> c.x >> c.y;
        cows.push_back(c);
    }
    
    
    return 0;
}