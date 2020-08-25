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

int N;
set<int> numids;
set<int> uniquenums;
vector<pair<int,int>> lineup;
map<int,int> counter;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        numids.insert(p.second);
        lineup.push_back(p);
        //counter[p.second]++;
    }
    int total = int(numids.size());
    sort(lineup.begin(),lineup.end());
    //for (int i = 0; i < lineup.size(); i++) cout << lineup[i].first << " " << lineup[i].second << endl;
    //cout << endl;
    int ans = LARGE;
    for (int i = 0; i < lineup.size(); i++) {
        uniquenums.insert(lineup[i].second);
        counter[lineup[i].second]++;
        if (uniquenums.size() == total) {
            int pos = 0;
            map<int,int> temp = counter;
            //cout << lineup[pos].second << " " << temp[lineup[pos].second] << endl;
            while (temp[lineup[pos].second] > 1) {
                temp[lineup[pos].second]--;
                pos++;
            }
            //cout << lineup[i].first << " " << lineup[pos].first << endl;
            ans = min(ans,lineup[i].first-lineup[pos].first);
        }
    }
    cout << ans << endl;
    
    return 0;
}