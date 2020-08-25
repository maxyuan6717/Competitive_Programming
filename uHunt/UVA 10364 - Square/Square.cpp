#include <iostream>
#include <cstdio>
#include <sstream>
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
#include <bitset>
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,total,side;
int sticks[20];

bool square(int indx, int cnt, int sum, int used) {
	//cout << indx << " " << cnt << " " << sum << endl;
	if (sum == side) {
		cnt++;
		indx = -1;
		sum = 0;
	}
	if (cnt == 5) return 1;
	for (int i = indx + 1; i < N; i++) {
		if (used&(1<<i)) continue;
		if (sum + sticks[i] > side) break;
		if (square(i,cnt,sum + sticks[i], used|(1<<i))) return 1;
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		total = 0;
		for (int i = 0; i < N; i++) {
			cin >> sticks[i];
			total += sticks[i];
		}
		if (total%4) {
			cout << "no" << endl;
			continue;
		}
		side = total/4;
		sort(sticks,sticks+N);
		if (square(-1,1,0,0)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
    return 0;
}
