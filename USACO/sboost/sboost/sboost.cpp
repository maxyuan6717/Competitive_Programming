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

struct part {
    double f,m,a;
    int indx;
};

double F,M,N,A;
vector<part> parts;
vector<int> ans;

bool compare(part a, part b) {
    return a.a < b.a;
}

int main() {
    cin >> F >> M >> N;
    A = F/M;
    for (int i = 0; i < N; i++) {
        part p;
        cin >> p.f >> p.m;
        p.a = p.f/p.m;
        p.indx = i+1;
        parts.push_back(p);
    }
    sort(parts.begin(),parts.end(),compare);
    while (!parts.empty()) {
        part p = parts.back();
        parts.pop_back();
        if ((F+p.f)/(M+p.m) > A) {
            A = (F+p.f)/(M+p.m);
            F += p.f;
            M += p.m;
            ans.push_back(p.indx);
        }
        else break;
    }
    sort(ans.begin(),ans.end());
    if (ans.empty()) cout << "NONE" << endl;
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}