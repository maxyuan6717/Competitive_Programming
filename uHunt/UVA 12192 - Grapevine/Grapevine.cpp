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

int N,M,Q;
vector<vector<int> > arr;
int num;

int main() {
	cin >> N >> M;
	while (N || M) {
		arr.clear();
		for (int i = 0; i < N; i++) {
			vector<int> row;
			for (int j = 0; j < M; j++) {
				cin >> num;
				row.push_back(num);
			}
			arr.push_back(row);
		}
		cin >> Q;
		for (int q = 0; q < Q; q++) {
			int u,l;
			cin >> l >> u;
			int ans = 0;
			for (int i = 0; i < N; i++) {
				vector<int>::iterator it = lower_bound(arr[i].begin(), arr[i].end(), l);
				int r = i;
				int c = distance(arr[i].begin(),it);
				while (r < N && c < M && arr[r][c] <= u) {
					ans = max(ans,(r-i)+1);
					r++, c++;
				}
			}
			cout << ans << endl;
		}
		cout << '-' << endl;
		cin >> N >> M;
	}
    return 0;
}
