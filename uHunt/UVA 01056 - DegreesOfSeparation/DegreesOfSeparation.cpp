#include <iostream>
#include <fstream>
#include <string>
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

#define LARGE 100000
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int P,R;
map<string,int> indx;
int arr[51][51];

int main() {
	cin >> P >> R;
	int netNum = 1;
	while (P || R) {
		indx.clear();
		int cindx = 1;
		for (int i = 0; i <= P; i++) {
			for (int j = 0; j <= P; j++) {
				arr[i][j] = LARGE;
				if (i == j) arr[i][j] = 0;
			}
		}
		for (int i = 0; i < R; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			int i1 = indx[s1];
			int i2 = indx[s2];
			if (!i1) i1 = cindx++;
			indx[s1] = i1;
			if (!i2) i2 = cindx++;
			indx[s2] = i2;
			arr[i1][i2] = 1;
			arr[i2][i1] = 1;
		}
		for (int k = 1; k <= P; k++) {
			for (int i = 1; i <= P; i++) {
				for (int j = 1; j <= P; j++) {
					arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
				}
			}
		}
		bool done = 0;
		int ans = 0;
		for (int i = 1; i <= P; i++) {
			for (int j = 1; j <= P; j++) {
				if (arr[i][j] == LARGE) {
					done = 1;
					ans = 0;
					break;
				}
				ans = max(ans,arr[i][j]);
			}
			if (done) break;
		}
		cout << "Network " << netNum++ << ": ";
		if (!ans) cout << "DISCONNECTED" << endl;
		else cout << ans << endl;
		cout << endl;
		cin >> P >> R;
	}
    return 0;
}
