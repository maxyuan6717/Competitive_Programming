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

int N,M;
int dragon[20000],knight[20000];

int main() {
	while (cin >> N >> M, N || M) {
		for (int i = 0; i < N; i++) cin >> dragon[i];
		for (int i = 0; i < M; i++) cin >> knight[i];
		sort(dragon,dragon+N);
		sort(knight,knight+M);
		int i = 0, j = 0,ans = 0;
		while (i < N && j < M) {
			if (knight[j] >= dragon[i]) {
				i++;
				ans += knight[j];
			}
			j++;
		}
		if (i < N) cout << "Loowater is doomed!" << endl;
		else cout << ans << endl;
	}
    return 0;
}
