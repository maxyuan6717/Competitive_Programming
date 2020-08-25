/*
 ID: yuanmax1
 PROG: race3
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

int arr[51][51];
int N = 0;
int ans1 = 0,a1[51],counter1 = 0;
int ans2 = 0,a2[51],counter2 = 0;
int visited[51];

int dfs(int x,int t) {
    //cout << x << " ";
    visited[x] = 1;
    for (int i = 0; i <= N; i++) {
        if (arr[x][i] && i == t) return 1;
        if (arr[x][i] && visited[i] == 0) {
            if (dfs(i,t)) return 1;
        }
    }
    return 0;
}

int main() {
    ofstream fout ("race3.out");
    ifstream fin ("race3.in");
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            arr[i][j] = 0;
        }
    }
    int num;
    int done = 0;
    while (!done) {
        fin >> num;
        if (num == -2) N++;
        else if (num == -1) done = 1;
        else arr[N][num] = 1;
    }
    N--;
    int stop = 0;
    for (int i = 1; i < N; i++) {
        //cout << i << "   ";
        for (int i = 0; i <= N; i++) {
            visited[i] = 0;
        }
        visited[i] = 1;
        if (!dfs(0,N)) {
            ans1++;
            a1[counter1] = i;
            counter1++;
            int temp[N+1];
            for (int j = 0; j <= N; j++) {
                temp[j] = visited[j];
                visited[j] = 0;
            }
            stop = 0;
            int c = dfs(i,-1);
            /*cout << i << "     ";
            for (int j = 0; j <= N; j++) cout << temp[j] << " ";
            cout << endl;
            cout << i << "     ";
            for (int j = 0; j <= N; j++)  cout << visited[j] << " ";
            cout << endl;*/
            for (int j = 0; j <= N; j++) {
                if (visited[j] && temp[j] && j!=i) {
                    stop = 1;
                    break;
                }
            }
            if (!stop) {
                ans2++;
                a2[counter2] = i;
                counter2++;
            }
            //cout << i << endl;
        }
        //cout << endl;
    }
    //cout << N << endl;
    cout << ans1;
    fout << ans1;
    for (int i = 0; i < counter1; i++) {
        cout << " " << a1[i];
        fout << " " << a1[i];
    }
    cout << endl;
    fout << endl;
    cout << ans2;
    fout << ans2;
    for (int i = 0; i < counter2; i++) {
        cout << " " << a2[i];
        fout << " " << a2[i];
    }
    cout << endl;
    fout << endl;
    /*for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << N << endl;*/
    return 0;
}