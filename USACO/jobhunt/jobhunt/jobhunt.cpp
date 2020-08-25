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

int D,P,C,F,S;
int arr[221][221];
int ans = LARGE;

int main() {
    cin >> D >> P >> C >> F >> S;
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= C; j++) {
            arr[i][j] = LARGE;
        }
    }
    for (int i = 0; i < P; i++) {
        int s,e;
        cin >> s >> e;
        arr[s][e] = -D;
    }
    for (int i = 0; i < F; i++) {
        int s,e,c;
        cin >> s >> e >> c;
        arr[s][e] = c-D;
    }
    for (int k = 1; k <= C; k++) {
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
                if (i == S && arr[i][j] < ans) ans = arr[i][j];
                //ccout << arr[i][j] << " ";
            }
            //cout << endl;
        }
        //cout << endl;
    }
    int negcycle = 0;
    for (int k = 1; k <= C; k++) {
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) negcycle = 1;
            }
        }
    }
    if (negcycle) cout << -1 << endl;
    else cout << D-ans << endl;
    return 0;
}