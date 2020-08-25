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
vector<int> coins;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		coins.clear();
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			coins.push_back(num);
		}
		int ans = 0;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (coins[i] <= sum) {
				sum -= coins[i-1];
				sum += coins[i];
				continue;
			}
			sum += coins[i];
			ans++;
		}
		cout << ans << endl;
	}
    return 0;
}
