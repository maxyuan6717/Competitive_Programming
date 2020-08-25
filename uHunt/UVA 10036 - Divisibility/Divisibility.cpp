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

int N,K,num[10000];
bool dp[10000][100];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		memset(dp,0,sizeof(dp));
		for (int i = 0; i < N; i++) {
			cin >> num[i];
			num[i]%=K;
			if (num[i] < 0) num[i] += K;
		}
		dp[0][(K+num[0])%K] = 1;
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < K; j++) {
				if (!dp[i-1][j]) continue;
				int k = (j+num[i]+K)%K;
				dp[i][k] = 1;
				k = (j-num[i]+K)%K;
				dp[i][k] = 1;
			}
		}
		if (dp[N-1][0]) cout << "Divisible" << endl;
		else cout << "Not divisible" << endl;
	}
    return 0;
}
