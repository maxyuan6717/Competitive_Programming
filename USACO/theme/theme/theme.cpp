/*
 ID: yuanmax1
 PROG: theme
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <ctime>

#define LARGE 9999999


using namespace std;

int N;
int arr[5000];

int main() {
    ofstream fout ("theme.out");
    ifstream fin ("theme.in");
    fin >> N;
    int n1,n2;
    fin >> n1;
    for (int i = 0; i < N-1; i++) {
        fin >> n2;
        arr[i] = n1-n2;
        n1 = n2;
    }
    int ans = 0;
    for (int i = 0; i < N-ans-1; i++) {
        for (int j = i+ans; j < N-ans-1; j++) {
            int length;
            if (arr[i]==arr[j]) {
                length = 1;
                while (arr[i+length] == arr[j+length] && j > i+length+1) length++;
                ans = max(ans,length);
            }
        }
    }
    ans++;
    if (ans < 5) {
        cout << 0 << endl;
        fout << 0 << endl;
    }
    else {
        cout << ans << endl;
        fout << ans << endl;
    }
    //cout << ((float)clock()-t)/CLOCKS_PER_SEC << endl;;
    
    
    
    return 0;
}