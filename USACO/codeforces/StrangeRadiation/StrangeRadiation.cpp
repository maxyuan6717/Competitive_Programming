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

struct person {
    int pos;
    int dir;
    int speed;
};

bool compare(person a, person b) {
    return a.pos < b.pos;
}

int N,S;
person ppl[100001];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> ppl[i].pos >> ppl[i].speed >> ppl[i].dir;
        ppl[i].dir--;
    }
    sort(ppl,ppl+N,compare);
    
    
    return 0;
}