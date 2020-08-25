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

struct elephant {
	int w,s,indx;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int w,s;
elephant arr[1000];
int N;

bool compare(elephant a, elephant b) {
	if (a.w != b.w) return a.w < b.w;
	else return a.s > b.s;
}

int main() {
	N = 0;
	//ifstream fin("test");
	while (cin >> w >> s) {
		arr[N].indx = N;
		arr[N].w = w;
		arr[N++].s = s;
	}
	sort(arr,arr+N,compare);
	int dp[N];
	vector<int> seq[1000];
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		seq[i].push_back(i);
	}
	int ans = 0;
	vector<int> ansseq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j].w == arr[i].w) continue;
			if (arr[j].s <= arr[i].s) continue;
			if (dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				seq[i] = seq[j];
				seq[i].push_back(i);
			}
			if (dp[i] > ans) {
				ans = dp[i];
				ansseq = seq[i];
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < ansseq.size(); i++) {
		int u = ansseq[i];
		cout << arr[u].indx + 1 << endl;
	}
    return 0;
}
