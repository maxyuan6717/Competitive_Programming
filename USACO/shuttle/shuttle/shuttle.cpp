/*
 ID: yuanmax1
 PROG: shuttle
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

int N;
char arr[25];
int hole;
int total;
int dir = 1;
int slide = 1;
int half;
vector<int> ans;

void doslide() {
    int index = hole-dir;
    ans.push_back(index+1);
    arr[hole] = arr[index];
    arr[index] = ' ';
    hole = index;
}

void dojump() {
    int index = hole-2*dir;
    ans.push_back(index+1);
    arr[hole] = arr[index];
    arr[index] = ' ';
    hole = index;
}

int stilljump() {
    int ret = 0;
    int start = hole - 2*dir;
    int mid = hole - dir;
    if (start <= 2* N && start >= 0 && arr[mid] != arr[start]) ret = 1;
    return ret;
}

int main() {
    ofstream fout ("shuttle.out");
    ifstream fin ("shuttle.in");
    fin >> N;
    hole = N;
    total = N*N + 2*N;
    half = total/2;
    for (int i = 0; i < N; i++) {
        arr[i] = 'w';
        arr[2*N-i] = 'b';
    }
    arr[hole] = ' ';
    /*for (int i = 0; i < 2*N + 1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    
    for (int i = 0; i < total; i++) {
        if (slide) {
            if (i <= half) {
                doslide();
                dir = -dir;
            }
            else {
                dir = -dir;
                doslide();
            }
            slide = 0;
        }
        else {
            dojump();
            if (!stilljump())slide = 1;
        }
    }
    int s = int(ans.size());
    while(s>20) {
        cout << ans[0];
        fout << ans[0];
        ans.erase(ans.begin());
        for (int i = 0; i < 19; i++) {
            cout << " " << ans[0];
            fout << " " << ans[0];
            ans.erase(ans.begin());
        }
        cout << endl;
        fout << endl;
        s = int(ans.size());
    }
    cout << ans[0];
    fout << ans[0];
    for (int i = 1; i < s; i++) {
        cout << " " << ans[i];
        fout << " " << ans[i];
    }
    cout << endl;
    fout << endl;
    
    
    return 0;
}