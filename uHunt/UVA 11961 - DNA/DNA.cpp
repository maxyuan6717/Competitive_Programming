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

int N,K;
string seq,cur;
set<string> ans;

void dfs(int indx, int M) {
	if (M > K) return;
	if (indx == N) {
		ans.insert(cur);
		return;
	}
	cur[indx] = 'A';
	if (seq[indx] != 'A') dfs(indx+1,M+1);
	else dfs(indx+1,M);
	cur[indx] = 'T';
	if (seq[indx] != 'T') dfs(indx+1,M+1);
	else dfs(indx+1,M);
	cur[indx] = 'C';
	if (seq[indx] != 'C') dfs(indx+1,M+1);
	else dfs(indx+1,M);
	cur[indx] = 'G';
	if (seq[indx] != 'G') dfs(indx+1,M+1);
	else dfs(indx+1,M);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans.clear();
		cin >> N >> K >> seq;
		cur = "";
		for (int i = 0; i < N; i++) cur += " ";
		dfs(0,0);
		cout << ans.size() << endl;
		set<string>::iterator it;
		for (it = ans.begin(); it != ans.end(); it++) cout << *it << endl;
	}
    return 0;
}
