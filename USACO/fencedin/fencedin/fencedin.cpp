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

long long A,B,N,M;
vector<int> v;
vector<int> h;
vector<long long> difv;
vector<long long> difh;

int main() {
    cin >> A >> B >> N >> M;
    v.push_back(0);
    h.push_back(0);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        h.push_back(num);
    }
    sort(v.begin(),v.end());
    sort(h.begin(),h.end());
    v.push_back(A);
    h.push_back(B);
    //for (int i = 0; i <= N+1; i++) cout << v[i] << " ";
    //cout << endl;
    //for (int i = 0; i <= M+1; i++) cout << h[i] << " ";
    //cout << endl;
    for (int i = 0; i <= N; i++) difv.push_back(v[i+1]-v[i]);
    for (int i = 0; i <= M; i++) difh.push_back(h[i+1]-h[i]);
    sort(difv.begin(),difv.end());
    sort(difh.begin(),difh.end());
    //for (int i = 0; i <= N; i++) cout << difv[i] << " ";
    //cout << endl;
    //for (int i = 0; i <= M; i++) cout << difh[i] << " ";
    //cout << endl;
    int indxv = 0, indxh = 0;
    long long ans = 0;
    while (indxv <= N && indxh <= M) {
        long long curv = difv[indxv];
        long long curh = difh[indxh];
        if (indxv == 0) {
            ans += curh*N;
            indxv++;
        }
        if (indxh == 0) {
            ans += curv*M;
            indxh++;
        }
        else if (curh < curv) {
            ans += curh*(N+1-indxv);
            indxh++;
        }
        else {
            ans += curv*(M+1-indxh);
            indxv++;
        }
        //cout << curv << " " << curh << " " << indxv << " " << indxh << " " << ans << endl;
    }
    cout << ans << endl;
    
    return 0;
}