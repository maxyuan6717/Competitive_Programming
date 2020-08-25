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

struct common {
	bool arr[20];
	int cnt;
};

int N,R,M,P,ppl[20];
vector<common> v;

int main() {
	int caseNum = 1;
	while (cin >> N >> R, N || R) {
		printf("Case Number  %d\n",caseNum++);
		v.clear();
		vector<int> ansseq;
		int ans = 0;
		for (int i = 0; i < N; i++) cin >> ppl[i];
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> P;
			common c;
			for (int i = 0; i < N; i++) c.arr[i] = 0;
			for (int j = 0; j < P; j++) {
				int u;
				cin >> u;
				c.arr[u-1] = 1;
			}
			cin >> c.cnt;
			v.push_back(c);
		}
		vector<bool> use(N,0);
		for (int i = 0; i < R; i++) use[i] = 1;
		do {
			vector<int> cur;
			int sum = 0;
			for (int i = 0; i < N; i++) {
				if (use[i]) {
					cur.push_back(i);
					sum += ppl[i];
				}
			}
			for (int i = 0; i < M; i++) {
				common c = v[i];
				int cnt = 0;
				for (int j = 0; j < R; j++) {
					if (c.arr[cur[j]]) cnt++;
				}
				if (cnt) sum-=(cnt-1) * c.cnt;
			}
			if (sum > ans) {
				ans = sum;
				ansseq = cur;
			}
		} while (prev_permutation(use.begin(),use.end()));
		printf("Number of Customers: %d\n",ans);
		printf("Locations recommended:");
		for (int i = 0; i < R; i++) printf(" %d",ansseq[i]+1);
		printf("\n\n");
	}
    return 0;
}
