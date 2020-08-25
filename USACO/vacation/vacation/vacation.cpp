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

int N,M,K,Q;
int arr[201][201];

int main() {
    cin >> N >> M >> K >> Q;
    for (int i = 1;i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i!=j) arr[i][j] = LARGE;
            else arr[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int s,e,c;
        cin >> s >> e >> c;
        //cout << s << " " << e << " " << c;
        arr[s][e] = c;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
    /*for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    int ans1 = 0;
    long long ans2 = 0;
    for (int i = 0; i < Q; i++) {
        int sofar = LARGE;
        int s,e;
        cin >> s >> e;
        for (int j = 1; j <= K; j++) {
            if (arr[s][j] + arr[j][e] < sofar) sofar = arr[s][j] + arr[j][e];
        }
        if (sofar != LARGE) {
            ans1++;
            //cout << ans1 << " " << ans2 << endl;
            ans2 += sofar;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}