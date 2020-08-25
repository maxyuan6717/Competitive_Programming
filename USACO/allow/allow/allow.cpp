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

struct coin {
    int val,num;
};

int N,C;
vector<coin> coins;

bool compare(coin a, coin b) {
    return a.val < b.val;
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        coin c;
        cin >> c.val >> c.num;
        coins.push_back(c);
    }
    int done = 0;
    int ans = 0;
    sort(coins.begin(),coins.end(),compare);
    while (!done) {
        done = 1;
        int salary = C;
        //cout << ans << endl;
        //sort(coins.begin(),coins.end(),compare1);
        for (int i = coins.size()-1; i >= 0; i--) {
            coin c = coins[i];
            while (c.num > 0 && c.val <= salary) {
                c.num--;
                salary -= c.val;
            }
            coins[i].num = c.num;
        }
        //sort(coins.begin(),coins.end(),compare2);
        for (int i = 0; i < coins.size(); i++) {
            coin c = coins[i];
            while (c.num > 0 && salary > 0) {
                c.num--;
                salary -= c.val;
            }
            coins[i].num = c.num;
        }
        if (salary <= 0) {
            done = 0;
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}