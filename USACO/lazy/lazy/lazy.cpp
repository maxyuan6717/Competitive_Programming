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

int N,K;
int arr[401][401];
int rot[801][801];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            rot[i+j][N-(i-j+1)] = arr[i][j];
        }
    }
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rot[i+j][N-(i-j+1)] = arr[i][j];
        }
    }*/
    int newN = 2*N-1;
    int lat = (N+1)%2;
    int ans = 0;
    for (int i = 0; i < newN; i++) {
        int row;
        if (i-K > 0) row = i-K;
        else row = 0;
        int sum = 0;
        for (int j = row; j < newN && j <= i+K; j++) {
            int col;
            if (lat-K > 0) col = lat-K;
            else col = 0;
            for (int k = col; k < newN && k <= lat+K; k++) {
                sum += rot[j][k];
            }
        }
        ans = max(ans,sum);
        for (int j = lat+1; j+K < newN; j++) {
            for (int k = row; k < newN && k<=i+K; k++) {
                if (j-K-1>=0) sum-=rot[k][j-K-1];
                sum += rot[k][j+K];
            }
            if (j%2 == lat) ans = max(ans,sum);
        }
        lat = 1-lat;
    }
    cout << ans << endl;
    
    return 0;
}