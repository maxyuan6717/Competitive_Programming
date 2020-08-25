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

bool good[26];
bool bad[26];

int main() {
    string g;
    cin >> g;
    int len = int(g.size());
    for (int i = 0; i < len; i++) {
        good[g[i]-'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (!good[i]) bad[i] = 1;
    }
    string p;
    cin >> p;
    int len1 = int(p.size());
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int yes = 1;
        int len2 = int(s.size());
        if (len2 < len1 - 1) {
            cout << "NO" << endl;
            continue;
        }
        int indx = 0;
        for (int j = 0; j < len1; j++) {
            //cout << i << " " << j << " " << indx << " " << s[indx] << endl;
            if (p[j] != '?' && p[j] != '*' && p[j] != s[indx]) {
                yes = 0;
                break;
            }
            if (p[j] == '?' && bad[s[indx]-'a']) {
                yes = 0;
                break;
            }
            if (p[j] == '*') {
                int len3 = int(len2-len1+1);
                int counter = 0;
                for (int k = indx; k < indx + len3; k++) {
                    if (good[s[k]-'a']) {
                        yes = 0;
                        //cout << len3 << " " << indx << " " << "HI" << endl;
                    }
                    counter++;
                }
                indx += counter;
            }
            else {
                indx++;
            }
            if (!yes) break;
        }
        if (yes && indx == len2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    
    return 0;
}