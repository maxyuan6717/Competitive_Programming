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

vector<string> solve(int n) {
    if (n == 1) {
        vector<string> v;
        v.push_back("O");
        v.push_back("X");
        return v;
    }
    else {
        vector<string> v = solve(n-1);
        for (int i = 0; i < v.size(); i++) v[i] += "O";
        int len = int(v.size());
        vector<string> temp = v;
        reverse(temp.begin(),temp.end());
        for (int i = 0; i < temp.size(); i++) {
            v.push_back(temp[i]);
            v[len+i][n-1] = 'X';
        }
        return v;
    }
}

int main() {
    cin >> N;
    vector<string> ans = solve(N);
    string s (N,'O');
    ans.push_back(s);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}