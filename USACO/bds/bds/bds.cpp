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

int N,final;
int seen = 0;
int visited[11];
vector<int> seq;
int done = 0;

int check() {
    if (N == 2) return (seq[0]+seq[1] == final);
    if (N == 3) return (seq[0]+seq[2]+2*seq[1] == final);
    if (N == 4) return (seq[0]+seq[3]+3*(seq[1]+seq[2]) == final);
    if (N == 5) return (seq[0]+seq[4]+4*(seq[1]+seq[3])+6*seq[2] == final);
    if (N == 6) return (seq[0]+seq[5]+5*(seq[1]+seq[4])+10*(seq[2]+seq[3]) == final);
    if (N == 7) return (seq[0]+seq[6]+6*(seq[1]+seq[5])+15*(seq[2]+seq[4])+20*(seq[3]) == final);
    if (N == 8) return (seq[0]+seq[7]+7*(seq[1]+seq[6])+21*(seq[2]+seq[5])+35*(seq[3]+seq[4]) == final);
    if (N == 9) return (seq[0]+seq[8]+8*(seq[1]+seq[7])+28*(seq[2]+seq[6])+56*(seq[3]+seq[5])+70*seq[4] == final);
    if (N == 10)return (seq[0]+seq[9]+9*(seq[1]+seq[8])+36*(seq[2]+seq[7])+84*(seq[3]+seq[6])+126*(seq[4]+seq[5]) == final);
    return 0;
}

void dfs(int cur) {
    if (done) return;
    if (seen == N) {
        if (check()) {
            cout << seq[0];
            for (int i = 1; i < N; i++) cout << " " << seq[i];
            cout << endl;
            done = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            seen++;
            seq.push_back(i);
            dfs(i);
            seq.pop_back();
            seen--;
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> final;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) visited[j] = 0;
        dfs(i);
        if (done) break;
    }
    return 0;
}