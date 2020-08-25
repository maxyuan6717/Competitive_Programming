/*
 ID: yuanmax1
 */
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


using namespace std;

int main() {
    ofstream fout ("art2.out");
    ifstream fin ("art2.in");
    int N, ans = 0;
    fin >> N;
    set <int> s;
    set <int> s2;
    set <int>::iterator it;
    int counter[N];
    int b[N];
    int e[N];
    int num;
    for (int i = 0; i < N; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        fin >> num;
        s.insert(num);
        counter[num]++;
        //cout << num << " " << counter[num] << " " << s2.size() << " " << ans << endl;
        if (counter[num] == 1) b[num] = i;
        if (counter[num] > 1) e[num] = i;
        if (counter[num] == 2 && s2.size() == 0 && i - 1 != b[num]) {
            ans++;
            s2.insert(num);
        }
        else if (counter[num] == 2 && i - 1 == b[num]) {
            ans = ans;
        }
        else if (counter[num] > 1 && s2.size() != 0) {
            int add = 0;
            for (it = s2.begin(); it != s2.end(); it++) {
                if (b[num] < e[*it] && b[num] > b[*it]) {
                    //cout << -1 << endl;
                    fout << -1 << endl;
                    return 0;
                }
                else if (b[num] > e[*it]) {
                    ans = ans;
                }
                else if (b[num] < b[*it]) {
                    add++;
                    s2.insert(num);
                }
                else if (b[num] > e[*it]) {
                    add++;
                    s2.insert(num);
                }
            }
            if (add > 0) ans++;
        }
        cout << num << " " << counter[num] << " " << s2.size() << " " << ans << endl;
    }
    //cout << ans + 1 << endl;
    fout << ans + 1 << endl;
    
    return 0;
}