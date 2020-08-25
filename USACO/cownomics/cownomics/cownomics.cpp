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
    ofstream fout ("cownomics.out");
    ifstream fin ("cownomics.in");
    int N,M;
    fin >> N >> M;
    string sp[501];
    string pl[501];
    int ans[M];
    int arr[N][N][M];
    int arr2[N][M];
    for (int i = 0; i < N; i++) {
        fin >> sp[i];
    }
    for (int i = 0; i < N; i++) {
        fin >> pl[i];
    }
    ans[0] = 1;
    for (int i = 0; i < N; i++) {
        arr2[i][0] = 1;
        for (int j = 0; j < N; j++) {
            if (sp[i][0] == pl[j][0]) {
                arr[i][j][0] = -1;
                arr2[i][0] = -1;
                ans[0] = -1;
            }
            else arr[i][j][0] = 1;
        }
    }
    for (int i = 1; i < M; i++) {
        if (ans[i-1] < 0) ans[i] = 1;
        else ans[i] = ans[i-1] + 1;
        for (int j = 0; j < N; j++) {
            arr2[j][i] = 1;
            for (int k = 0; k < N; k++) {
                arr[j][k][i] = 1;
                if (sp[j][i] == pl[k][i]) {
                    //if (ans[i-1] < 0) ans[i] = ans[i-1] - 1;
                    //else ans[i] = -1;
                    /*if (arr[j][k][i-1] < 0) {
                        arr[j][k][i] = arr[j][k][i-1] - 1;
                    }
                    else {
                        arr[j][k][i] = arr[j][k][i-1] + 1;
                    }*/
                    arr[j][k][i] = -1;
                    arr2[j][i] = -1;
                }
                /*else {
                    if (arr[j][k][i-1] < 0) {
                        arr[j][k][i] = 0-arr[j][k][i-1]+1;
                    }
                    else {
                        arr[j][k][i] = arr[j][k][i-1] + 1;
                    }
                }*/
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //cout << arr[0][i][j] << " ";
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}