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

int N,M,T;
int arr[301][301];
int tall[301][301];
int visited[301];
int start,dest;
int ans = LARGE;
int temp = 0;


int main() {
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = LARGE;
            //tall[i][j] = LARGE;
        }
    }
    for (int i = 0; i < M; i++) {
        int s,e,h;
        cin >> s >> e >> h;
        arr[s][e] = h;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][k] && arr[k][j] && max(arr[i][k],arr[k][j]) < arr[i][j]) arr[i][j] = max(arr[i][k],arr[k][j]);
            }
        }
    }
    for (int i = 0; i < T; i++) {
        int num,s,e;
        cin >> s >> e;
        num = arr[s][e];
        if (num == LARGE) cout << -1 << endl;
        else cout << num << endl;
    }

    
    return 0;
}