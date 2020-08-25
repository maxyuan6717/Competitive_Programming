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
vector<int> res;
map<vector<int>,bool> used;
int ans1,ans2;

void rec(vector<int> v, int moves) {
	/*cout << moves << " ";
	for (int i = 0; i < N; i++) cout << v[i] << " ";
	cout << ans2 << endl;*/
	if (moves > ans1) return;
	if (v == res) {
		if (moves < ans1) {
			ans1 = moves;
			ans2 = 1;
		}
		else if (moves == ans1) ans2++;
		if (moves == 0) ans2 = 0;
		return;
	}
	for (int i = 0; i < N-1; i++) {
		if (v[i] < v[i+1]) continue;
		swap(v[i],v[i+1]);
		if (used[v]) {
			swap(v[i],v[i+1]);
			continue;
		}
		used[v] = 1;
		rec(v,moves+1);
		used[v] = 0;
		swap(v[i],v[i+1]);
	}
}

int main() {
	int caseNum = 1;
	while (scanf("%d",&N),N) {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			int num;
			scanf("%d",&num);
			v.push_back(num);
		}
		res = v;
		ans1 = LARGE,ans2 = 0;
		used.clear();
		sort(res.begin(),res.end());
		used[v] = 1;
		rec(v,0);
		printf("There are %d swap maps for input data set %d.\n",ans2,caseNum++);
	}
    return 0;
}
