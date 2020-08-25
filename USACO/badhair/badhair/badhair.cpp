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

int N;
stack<int> s;
long long ans = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        //cout << s.size() << endl;
        if (s.empty()) s.push(num);
        else if (num < s.top()) s.push(num);
        else {
            while (!s.empty() && s.top() <= num) {
                s.pop();
                ans+=s.size();
            }
            s.push(num);
        }
    }
    while (!s.empty()) {
        s.pop();
        ans+=s.size();
    }
    cout << ans << endl;
    return 0;
}