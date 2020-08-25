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

int N,L;
vector<int> v;

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int cur = -1;
    for (int i = 0; i < N; i++) {
        if (L < v[i]) {
            v.insert(v.begin()+i,L);
            cur = i;
            break;
        }
    }
    if (cur == -1) {
        v.push_back(L);
        cur = N;
    }
    int ans = 0;
    int t = 0;
    while (v.size()!=1) {
        int s = int(v.size());
        if (cur == s-1) {
            t += v[cur]-v[cur-1];
            v.erase(v.begin()+cur);
            cur--;
        }
        else if (cur == 0) {
            t += v[cur+1]-v[cur];
            v.erase(v.begin());
        }
        else {
            int s1 = v[cur+1] - v[cur];
            int s2 = v[cur] - v[cur-1];
            if (s1 <= s2) {
                t += s1;
                v.erase(v.begin()+cur);
            }
            else if (s2 < s1) {
                t += s2;
                v.erase(v.begin()+cur);
                cur--;
            }
        }
        ans += t;
        //for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        //cout << cur << " " << t << endl;
    }
    cout << ans << endl;

    
    
    return 0;
}