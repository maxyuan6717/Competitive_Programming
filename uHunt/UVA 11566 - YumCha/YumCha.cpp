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

#define LARGE 10000000

using namespace std;

int N,x,T,K;

int main() {
	cin >> N >> x >> T >> K;
	while (N || x || T || K) {
		int price[2*K+1];
		int fav[2*K+1];
		for (int i = 1; i <= 2*K; i+=2) {
			cin >> price[i];
			fav[i] = 0;
			for (int j = 0; j <= N; j++) {
				int num;
				cin >> num;
				fav[i] += num;
			}
			price[i+1] = price[i];
			fav[i+1] = fav[i];
		}
		int total = (N+1)*x;
		int maxJ = floor(double(x * (N + 1)) / 1.1 + 1e-6) - (N + 1) * T;
		int dp[25][total+1];
		for (int i = 0; i <= 2*(N+1); i++) {
			for (int j = 0; j <= total; j++) {
				dp[i][j] = 0;
			}
		}
		int ans = 0;
		for (int i = 1; i <= 2*K; i++) {
			int val = fav[i];
			int pri = price[i];
			for (int j = maxJ; j >= pri; j--) {
				for (int k = 1; k <= 2*(N+1); k++) {
					dp[k][j] = max(dp[k][j], dp[k-1][j-pri] + val);
					ans = max(ans,dp[k][j]);
				}
			}
		}
		double output = ans;
		output/=(N+1);
		cout << setprecision(2) << fixed;
		cout << output << endl;
		cin >> N >> x >> T >> K;
	}
    
    return 0;
}
