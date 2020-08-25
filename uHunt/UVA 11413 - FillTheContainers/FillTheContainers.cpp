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

int N,M;
int vessels[1000];

bool works(int target) {
	int numBuckets = 1,curCapacity = 0;
	for (int i = 0; i < N; i++) {
		if (vessels[i] > target) return 0;
		if (curCapacity + vessels[i] > target) {
			curCapacity = vessels[i];
			numBuckets++;
		}
		else curCapacity += vessels[i];
		if (numBuckets > M) return 0;
	}
	return 1;
}

int main() {
	while (cin >> N >> M) {
		for (int i = 0; i < N; i++) cin >> vessels[i];
		int l = 0, r = 1e9;
		while (l <= r) {
			int mid = (l+r)/2;
			if (works(mid)) r = mid-1;
			else l = mid + 1;
		}
		cout << r+1 << endl;
	}
    return 0;
}
