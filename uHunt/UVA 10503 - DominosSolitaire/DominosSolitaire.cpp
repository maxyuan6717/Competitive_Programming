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

struct domino {
	int a,b;
};

int N,M;
domino arr[14];
domino start,dest;
bool used[14];

bool rec(int cur, int left) {
	if (!left && cur == dest.a) return 1;
	if (!left && cur != dest.a) return 0;
	for (int i = 0; i < M; i++) {
		if (used[i]) continue;
		if (arr[i].a == cur) {
			used[i] = 1;
			bool ret = rec(arr[i].b,left-1);
			used[i] = 0;
			if (ret) return 1;
		}
		else if (arr[i].b == cur) {
			used[i] = 1;
			bool ret = rec(arr[i].a,left-1);
			used[i] = 0;
			if (ret) return 1;
		}
	}
	return 0;
}

int main() {
	while (scanf("%d",&N),N) {
		scanf("%d",&M);
		scanf("%d %d %d %d",&start.a, &start.b, &dest.a, &dest.b);
		for (int i = 0; i < M; i++) {
			scanf("%d %d",&arr[i].a, &arr[i].b);
			used[i] = 0;
		}
		if (rec(start.b,N)) printf("YES\n");
		else printf("NO\n");

	}
    return 0;
}
