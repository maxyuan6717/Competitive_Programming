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
vector<char> cows;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        cows.push_back(c);
    }
    string ans;
    int lindx = 0,rindx = N-1;
    for (int i = 0; i < N; i++) {
        if (cows[lindx] < cows[rindx]) {
            ans += cows[lindx];
            lindx++;
        }
        else if (cows[lindx] > cows[rindx]){
            ans += cows[rindx];
            rindx--;
        }
        else if (rindx-lindx <= 2) {
            ans += cows[rindx];
            rindx--;
        }
        else {
            int l = 0;
            int templ = lindx;
            int tempr = rindx;
            while (templ < tempr) {
                templ++;
                tempr--;
                if (cows[templ] < cows[tempr]) {
                    l = 1;
                    break;
                }
                else if (cows[templ] > cows[tempr]) {
                    l = 0;
                    break;
                }
            }
            if (l) {
                ans += cows[lindx];
                lindx++;
            }
            else {
                ans += cows[rindx];
                rindx--;
            }
        }
    }
    int indx = 0;
    int len = int(ans.size());
    if (ans.size() <= 80) cout << ans << endl;
    else {
        while (indx < len) {
            for (int i = 0; i < 80 && indx < len; i++) {
                cout << ans[indx];
                indx++;
            }
            cout << endl;
        }
    }
    
    return 0;
}