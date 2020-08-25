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

int N,Q,D,M;
long long arr[201];
long long mod[201];
long long dp[201][11][21];

int main() {
	int setNum = 1;
	while (cin >> N >> Q, N || Q) {
		cout << "SET " << setNum++ << ":" << endl;
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int q = 1; q <= Q; q++) {
			cout << "QUERY " << q << ": ";
			cin >> D >> M;
			for (int j = 1; j <= N; j++)  mod[j] = (arr[j] + D*(abs(arr[j]/D)+1))%D;
			memset(dp,0,sizeof(dp));
			dp[0][0][0] = 1;
			for (int i = 1; i <= N; i++) {
				int div = mod[i];
				for (int j = 0; j <= M; j++) {
					for (int k = 0; k < D; k++) {
						long long sum = (div+k)%D;
						dp[i][j][k] += dp[i-1][j][k];
						if (j) dp[i][j][k] += dp[i-1][j-1][sum];
					}
				}
			}
			cout << dp[N][M][0] << endl;
		}
	}
    return 0;
}
