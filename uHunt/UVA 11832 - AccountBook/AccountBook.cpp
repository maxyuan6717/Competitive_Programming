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

int N,F,arr[41];
bool dp[41][32001];
long long pos[41][32001],neg[41][32001];

int main() {
	while (cin >> N >> F, N || F) {
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= 32000; j++) {
				dp[i][j] = 0;
				pos[i][j] = neg[i][j] = 0;
			}
		}
		dp[0][16000] = 1;
		for (int i = 1; i <= N; i++) {
			int a = arr[i];
			for (int j = 0; j <= 32000; j++) {
				if (j - a >= 0 && dp[i-1][j-a]) {
					//cout << i << " " << j-16000 << " +" << endl;
					dp[i][j] = 1;
					pos[i][j] |= pos[i-1][j-a];
					neg[i][j] |= neg[i-1][j-a];
					pos[i][j] |= ((long long) 1 << i);
				}
				if (j + a <= 32000 && dp[i-1][j+a]) {
					//cout << i << " " << j-16000 << " -" << endl;
					dp[i][j] = 1;
					pos[i][j] |= pos[i-1][j+a];
					neg[i][j] |= neg[i-1][j+a];
					neg[i][j] |= ((long long) 1 << i);
				}
			}
		}
		if (!dp[N][F+16000]) {
			cout << "*" << endl;
			continue;
		}
		int curN = 3, curF = 6;
		for (int i = 1; i <= N; i++) {
			if ((pos[N][F+16000] & ((long long) 1<<i)) && (neg[N][F + 16000] & ((long long) 1<<i))) cout << "?";
			else if (pos[N][F + 16000] & ((long long) 1<<i)) cout << "+";
			else cout << "-";
		}
		cout << endl;
	}
    return 0;
}
