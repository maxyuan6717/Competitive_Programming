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

int R;
int arr[101][101];

int main() {
    cin >> R;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = R-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            arr[i][j] = max(arr[i+1][j+1],arr[i+1][j]) + arr[i][j];
        }
    }
    cout << arr[1][1] << endl;
    return 0;
}