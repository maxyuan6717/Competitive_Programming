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
int arr[201][201];
int ans = -LARGE;

int bigpos(vector<int> v) {
    int ret = -LARGE;
    int cur = 0;
    int sum = 0;
    for (int i = 0; i < cur+N; i++) {
        sum += v[i%N];
        if (sum > ret) ret = sum;
        else if (sum < 0) {
            if (i >= N) break;
            sum = 0;
            cur = i+1;
        }
    }
    return ret;
}
int bigneg(vector<int> v) {
    int ret = 0;
    int cur = 0;
    int sum = 0;
    for (int i = 0; i < cur+N; i++) {
        sum += v[i%N];
        if (sum < ret) ret = sum;
        if (sum > 0) {
            if (i >= N) break;
            sum = 0;
            cur = i+1;
        }
    }
    int total = 0;
    for (int i = 0; i < N; i++) total+=v[i];
    if (total != ret) ret = total-ret;
    else ret = total;
    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        vector<int> seq;
        for (int j = 0; j < N; j++) {
            seq.push_back(arr[i][j]);
        }
        int n1 = bigpos(seq);
        int n2 = bigneg(seq);
        int num = max(n1,n2);
        if (num > ans) ans = num;
    }
    
    for (int i = 0; i < N; i++) {
        vector<int> seq;
        for (int j = 0; j < N; j++) {
            seq.push_back(arr[j][i]);
        }
        int n1 = bigpos(seq);
        int n2 = bigneg(seq);
        int num = max(n1,n2);
        if (num > ans) ans = num;
    }
    for (int i = 0; i < N; i++) {
        vector<int>seq;
        for (int j = 0; j < N; j++) {
            seq.push_back(arr[j][(i+j)%N]);
        }
        int n1 = bigpos(seq);
        int n2 = bigneg(seq);
        int num = max(n1,n2);
        if (num > ans) ans = num;
    }
    
    for (int i = 0; i < N; i++) {
        vector<int>seq;
        for (int j = 0; j < N; j++) {
            seq.push_back(arr[j][(N+i-j)%N]);
        }
        int n1 = bigpos(seq);
        int n2 = bigneg(seq);
        int num = max(n1,n2);
        if (num > ans) ans = num;
    }
    cout << ans << endl;
    
    return 0;
}