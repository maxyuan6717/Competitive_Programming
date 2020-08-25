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

int C,L;
vector<pair<int,int>> cows;
vector<pair<int,int>> lotions;

bool comp1(pair<int,int> a, pair<int,int> b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ifstream fin("t.in");
    cin >> C >> L;
    for (int i = 0; i < C; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        cows.push_back(p);
    }
    for (int i = 0; i < L; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        lotions.push_back(p);
    }
    int ans = 0;
    sort(cows.begin(),cows.end(),comp1);
    sort(lotions.begin(),lotions.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int pos = 0;
    while(!lotions.empty()) {
        while (pos < C && cows[pos].first <= lotions[0].first) {
            pq.push(cows[pos].second);
            pos++;
        }
        while (!pq.empty() && lotions[0].second) {
            int spf = pq.top();
            pq.pop();
            if (spf >= lotions[0].first) {
                ans++;
                lotions[0].second--;
            }
        }
        lotions.erase(lotions.begin());
    }
    cout << ans << endl;
    return 0;
}