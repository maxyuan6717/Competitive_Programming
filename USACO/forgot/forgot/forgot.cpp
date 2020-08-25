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

int L,NW;
string forgot;
vector<string> dictionary;
string dp[1001];

int main() {
    cin >> L >> NW >> forgot;
    for (int i = 0; i < NW; i++) {
        string s;
        cin >> s;
        dictionary.push_back(s);
    }
    for (int i = 1; i <= L; i++) {
        for (int j = 0; j < NW; j++) {
            string word = dictionary[j];
            int len = int(word.size());
            int indx = i-len;
            if (indx < 0 || (indx != 0 && dp[indx] == "")) continue;
            int works = 1;
            //cout << i << " " << word << endl;
            for (int k = 0; k < len; k++) {
                if (forgot[indx+k] != '?' && forgot[indx+k] != word[k]) {
                    works = 0;
                    break;
                }
            }
            if (!works) continue;
            //cout << i << " " << word << endl;
            if (dp[i] == "" || (dp[i] != "" && dp[indx]+word < dp[i])) dp[i] = dp[indx]+word;
            //cout << dp[i] << endl;
        }
    }
    cout << dp[L] << endl;
    return 0;
}