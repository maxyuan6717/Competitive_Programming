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
    ofstream fout ("art.out");
    ifstream fin ("art.in");
    int N,ans = 1,mi,ma;
    fin >> N;
    int arr[N][N];
    int counter[N*N+1];
    for (int i = 0; i <= N*N; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> arr[i][j];
        }
    }
    for (int a = 1; a <= N*N; a++) {
        mi = N;
        ma = 0;
        int mi2 = N;
        int ma2 = 0;
        int x,y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == a) {
                    counter[a]++;
                    if (i > ma) ma = i;
                    if (i < mi) mi = i;
                    if (j > ma2) ma2 = j;
                    if (j < mi2) mi2 = j;
                }
            }
        }
        y = ma-mi+1;
        x = ma2-mi2+1;
        //cout << "x: " << x << " y: " << y << " " << counter[a] << endl;
        if (counter[a] > 0 && counter[a] != x*y) ans++;
    }
    fout << ans << endl;
    return 0;
}