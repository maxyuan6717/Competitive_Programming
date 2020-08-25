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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,arr[2050],ans[1050];
bool done = 0;

void rec(int sum, int cnt, int cur) {
	if (done || cnt > N ||cur > M) return;
	if (cnt == N && sum%N == 0) {
		done = 1;
		cout << "Yes" << endl << ans[0];
		for (int i = 1; i < N; i++) cout << " " << ans[i];
		cout << endl;
		return;
	}
	ans[cnt] = arr[cur];
	rec((sum+arr[cur])%N,cnt+1,cur+1);
	rec(sum,cnt,cur+1);
}

int main() {
	while (cin >> N, N) {
		M = 2*N-1;
		done = 0;
		for (int i = 0; i < M; i++) cin >> arr[i];
		rec(0,0,0);
		if (!done) {
			cout << "No" << endl;
		}
	}
    return 0;
}
