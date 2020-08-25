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

int T,N;
int arr[12];
map<vector<int>,bool> used;

void rec(int sum, int indx, vector<int> seq) {
	if (sum == T) {
		if (used[seq]) return;
		used[seq] = 1;
		for (int i = 0; i < seq.size(); i++) {
			printf("%d",seq[i]);
			if (i != seq.size()-1) printf("+");
		}
		printf("\n");
		return;
	}
	for (int i = indx; i < N; i++) {
		if (sum + arr[i] > T) continue;
		seq.push_back(arr[i]);
		rec(sum + arr[i],i + 1,seq);
		seq.pop_back();
	}
}

int main() {
	while (scanf("%d %d", &T, &N), T || N) {
		for (int i = 0; i < N; i++) cin >> arr[i];
		printf("Sums of %d:\n",T);
		vector<int> v;
		used.clear();
		rec(0,0,v);
		if (used.empty()) printf("NONE\n");
	}
    return 0;
}
