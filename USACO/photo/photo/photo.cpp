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
vector<int> arr[5];
vector<int> cur;
map<int,int> m[5];

bool compare(int i, int j) {
    int counter = 0;
    for (int k = 0; k < 5; k++) {
        if (m[k][i] < m[k][j]) counter++;
    }
    if (counter > 2) return 1;
    else return 0;
}

int main() {
    cin >> N;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            arr[i].push_back(num);
            m[i][num] = j;
        }
        if (i == 0) cur = arr[i];
    }
    sort(cur.begin(),cur.end(),compare);
    for (int i = 0; i < N; i++) cout << cur[i] << endl;
    
    return 0;
}