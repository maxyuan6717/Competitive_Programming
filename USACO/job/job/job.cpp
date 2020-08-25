/*
 ID: yuanmax1
 PROG: job
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

int N,m1,m2,tasksa[1001],tasksb[1001];
int times1[31],times2[31],machine[1001];
int A[31], B[31];

int main() {
    ofstream fout ("job.out");
    ifstream fin ("job.in");
    fin >> N >> m1 >> m2;

    for (int i = 1; i <= m1; i++) {
        fin >> A[i];
    }
    for (int i = 1; i <= m2; i++) {
        fin >> B[i];
    }
    for (int i = 1; i <= m1; i++) {
        times1[i] = 0;
    }
    for (int i = 1; i <= m2; i++) {
        times2[i] = 0;
    }
    int ans1 = 0;
    for (int n = N; n >=1; n--) {
        int index = 0;
        int min1 = LARGE;
        for (int i = 1; i <= m1; i++) {
            if (times1[i]+A[i] < min1) {
                min1 = times1[i] + A[i];
                index = i;
            }
        }
        times1[index] += A[index];
        tasksa[n] = min1;
    }
    for (int i = 1; i <= m1; i++) {
        if (times1[i] > ans1) ans1 = times1[i];
    }
    for (int n = 1; n <= N; n++) {
        int min2 = LARGE;
        int index = 0;
        for (int i = 1; i <= m2; i++) {
            if (times2[i] + B[i] < min2) {
                min2 = times2[i] + B[i];
                index = i;
            }
        }
        times2[index] += B[index];
        tasksb[n] = min2;
        machine[n] = index;
    }
    int ans2 = 0;
    for (int i = 1; i <= N; i++) {
        cout << tasksa[i] << " " << tasksb[i]  << " " << machine[i] << endl;
        if (tasksa[i] + tasksb[i] > ans2) ans2 = tasksa[i] + tasksb[i];
    }
    fout << ans1 << " " << ans2 << endl;
    cout << ans1 << " " << ans2 << endl;

    return 0;
}