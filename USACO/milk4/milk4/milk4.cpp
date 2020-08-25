/*
 ID: yuanmax1
 PROG: milk4
 LANG: C++
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

#define LARGE 9999999


using namespace std;

int pails[101];
int used[101];
int Q,P;
int done = 0;
int counter;
void dfs(int p) {
    for (int i = used[p-1]+1; i <= P+p-counter; i++) {
        used[p] = i;
        //cout << counter << " " << p << " " << i << " " << pails[i] << endl;
        if (p == counter) {
            int ans[20001];
            for (int q = 0; q <= Q; q++) ans[q] = 0;
            int first = pails[used[1]];
            for (int a = 1; a<=Q/first; a++) {
                ans[a*first] = 1;
            }
            for (int a = 2; a <= counter; a++) {
                int next = pails[used[a]];
                for (int b = next; b <= Q; b++) {
                    if (ans[b-next]) ans[b] = ans[b-next];
                }
            }
            if (ans[Q]) {
                done = 1;
                break;
            }
        }
        else {
            dfs(p+1);
        }
        if (done) break;
    }
}

int main() {
    ofstream fout ("milk4.out");
    ifstream fin ("milk4.in");
    fin >> Q >> P;
    for (int i = 1; i <= P; i++) {
        fin >> pails[i];
        used[i] = 0;
    }
    sort(pails,pails+P);
    for (int i = 1; i <= P; i++) {
        if (!done) {
            counter = i;
            //for (int j = 0; j <= P; j++) used[j] = -1;
            dfs(1);
        }
        else break;
    }
    cout << counter;
    fout << counter;
    for (int i = 1; i <= counter; i++) {
        cout << " " << pails[used[i]];
        fout << " " << pails[used[i]];
    }
    fout << endl;
    cout << endl;
    
    return 0;
}