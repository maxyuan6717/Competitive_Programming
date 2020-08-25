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
bool isPrime[50];

void genPrimes(int n) {
	memset(isPrime,true,sizeof(isPrime));
	for (int p = 2; p*p <= n; p++) {
		if (isPrime[p]) {
			for (int i = p*2; i <= n; i+=p) {
				isPrime[i] = 0;
			}
		}
	}
}

int cnter = 0;
int used[17];

void rec(int cnt, int cur, int start, vector<int> seq) {
	//cout << cnt << " " << cur << endl;
	seq.push_back(cur);
	if (cnt == N) {
		if (isPrime[cur+start]) {
			for (int i = 0; i < seq.size(); i++) {
				printf("%d",seq[i]);
				if (i != N-1) printf(" ");
			}
			printf("\n");
			cnter++;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (used[i]) continue;
		if (!isPrime[cur+i]) continue;
		used[i] = 1;
		rec(cnt + 1, i, start, seq);
		used[i] = 0;
	}
}

int main() {
	genPrimes(45);
	int caseNum = 1;
	while (scanf("%d",&N) == 1) {
		cnter = 0;
		if (caseNum > 1) printf("\n");
		printf("Case %d:\n",caseNum++);
		vector<int> v;
		for (int i = 0; i <= N; i++) used[i] = 0;
		used[1] = 1;
		rec(1,1,1,v);
		//cout << cnter << endl;
	}
    return 0;
}
