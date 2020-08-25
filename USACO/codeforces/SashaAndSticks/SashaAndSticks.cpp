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

int main() {
    long long N,K;
    cin >> N >> K;
    string ans[2] = {"NO","YES"};
    cout << ans[(N/K)%2] << endl;

    return 0;
}