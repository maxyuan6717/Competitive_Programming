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

int main() {
    int N,M;
    cin >> N >> M;
    while (N != 0 && M != 0) {
		set<int> jack;
		set<int> jill;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			jack.insert(num);
		}
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			jill.insert(num);
		}
		set<int>::iterator it;
		int ans = 0;
		for (it = jack.begin(); it != jack.end(); it++) {
			if (jill.find(*it) != jill.end()) ans++;
		}
		cout << ans << endl;
		cin >> N >> M;
    }
    return 0;
}
