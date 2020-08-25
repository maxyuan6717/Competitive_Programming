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

string name;
int N,M;
int dis[120][15];

int main() {
	while (cin >> name) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dis[i][j] = LARGE;
				if (!i) dis[i][j] = 0;
			}
		}
		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < M; k++) {
					int walkTime;
					cin >> walkTime;
					dis[i+1][k] = min(dis[i+1][k], dis[i][j] + walkTime + 2);
				}
			}
		}
		int ans = LARGE;
		for (int i = 0; i < M; i++) {
			ans = min(ans,dis[N-1][i]);
		}
		cout << name << endl;
		cout << ans << endl;
	}
    return 0;
}
