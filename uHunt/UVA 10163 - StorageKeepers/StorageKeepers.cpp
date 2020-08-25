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

int N,M,L,Y,arr[30],safe[101],ans;

int main() {
	while (cin >> N >> M, N || M) {
		for (int i = 0; i < M; i++) cin >> arr[i];
		for (int i = 0; i <= N; i++) safe[i] = 0;
		safe[0] = LARGE;
		for (int i = 0; i < M; i++) {
			for (int j = N; j >= 1; j--) {
				for (int k = 1; k <= j && k <= arr[i]; k++) {
					safe[j] = max(safe[j],min(arr[i]/(k),safe[j-k]));
				}
			}
		}
		L = safe[N];
		if (L == 0) {
			cout << 0 << " " << 0 << endl;
			continue;
		}
		for (int i = 0; i <= N; i++) safe[i] = 100000;
		safe[0] = 0;
		for (int i = 0; i < M; i++) {
			for (int j = N; j >= 0; j--) {
				for (int k = min(j,arr[i]/L); k > 0; k--) {
					safe[j] = min(safe[j],safe[j-k] + arr[i]);
				}
			}
		}
		Y = safe[N];
		cout << L << " " << Y << endl;
	}
    return 0;
}
