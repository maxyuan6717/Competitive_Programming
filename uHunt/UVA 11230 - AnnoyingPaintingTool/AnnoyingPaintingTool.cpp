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

int R,C,r,c,arr[100][100];

int main() {
	while (cin >> R >> C >> r >> c, R || C || r || c) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char ch;
				cin >> ch;
				arr[i][j] = ch-'0';
			}
		}
		int ans = 0;
		for (int i = 0; i < R-r+1; i++) {
			for (int j = 0; j < C-c+1; j++) {
				if (!arr[i][j]) continue;
				ans++;
				for (int k = i; k < i+r; k++) {
					for (int l = j; l < j+c; l++) {
						arr[k][l] = 1-arr[k][l];
					}
				}
			}
		}
		bool works = 1;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j]) works = 0;
			}
		}
		if (works) cout << ans << endl;
		else cout << -1 << endl;
	}
    return 0;
}
