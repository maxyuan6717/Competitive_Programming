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
int arr[100];
char c;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> c;
			arr[i] = (c == '.');
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i]) {
				ans++;
				for (int j = 0; j < 3; j++) {
					arr[i+j] = 0;
				}
			}
		}
		cout << "Case " << t << ": " << ans << endl;
	}
    return 0;
}
