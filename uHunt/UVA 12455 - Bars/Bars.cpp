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
#include <bitset>

#define LARGE (1<<31)-1

using namespace std;

string ans[2] = {"YES","NO"};

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
    	int N,P;
    	int ans2 = 1;
    	cin >> N >> P;
    	int bars[P];
    	for (int i = 0; i < P; i++) {
    		cin >> bars[i];
    	}
    	for (int i = 1; i < (1<<(P+1)); i++) {
    		int sum = 0;
    		for (int j = 0; j < P; j++) {
    			if (i & 1<<j) sum += bars[j];
    		}
    		if (sum == N) {
    			ans2 = 0;
    			break;
    		}
    	}
    	cout << ans[ans2] << endl;
    }
    return 0;
}
