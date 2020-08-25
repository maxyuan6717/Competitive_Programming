/*
 ID: yuanmax1
 PROG: milk2
 LANG: C++
 */
#include <fstream>
#include <algorithm>
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

int N;
pii times[5000];

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin >> N;
    for (int i = 0; i < N; i++) fin >> times[i].first >> times[i].second;
    sort(times,times+N);
    int milkT = times[0].second - times[0].first, idleT = 0, i1 = times[0].first, i2 = times[0].second;
    for (int i = 0; i < N; i++) {
        if (times[i].first <= i2) {
            i2 = max(i2,times[i].second);
            milkT = max(milkT,i2-i1);
        }
        else {
            i1 = times[i].first;
            idleT = max(idleT,i1-i2);
            i2 = times[i].second;
        }
    }
    fout << milkT << " " << idleT << endl;
    return 0;
}