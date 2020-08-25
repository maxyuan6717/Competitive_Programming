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
int arr[21];

int main() {
	int T;
	cin >> T;
	cin.ignore();
	for (int t = 0; t < T; t++) {
		string s;
		int num;
		getline(cin,s);
		stringstream ss(s);
		N = 0;
		int total = 0;
		while (ss >> num) {
			arr[++N] = num;
			total += num;
		}
		if (total%2) {
			cout << "NO" << endl;
			continue;
		}
		total/=2;
		bool dp[N+1][total+1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= total; j++) {
				dp[i][j] = 0;
				if (j == 0) dp[i][j] = 1;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= total; j++) {
				if (arr[i] > j) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i]]);
			}
		}
		if (dp[N][total]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}
