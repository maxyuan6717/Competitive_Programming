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

int N;
int pegs[50];
int ans = 0;

bool isSquare(int x) {
	int y = sqrt(x);
	return x == y*y;
}

void rec(int cur) {
	ans = max(ans,cur-1);
	for (int i = 0; i < N; i++) {
		if (!pegs[i]) {
			pegs[i] = cur;
			rec(cur+1);
			pegs[i] = 0;
			break;
		}
		if (!isSquare(pegs[i] + cur)) continue;
		int temp = pegs[i];
		pegs[i] = cur;
		rec(cur+1);
		pegs[i] = temp;
		break;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		memset(pegs,0,sizeof(pegs));
		ans = 0;
		rec(1);
		cout << ans << endl;
	}
    return 0;
}
