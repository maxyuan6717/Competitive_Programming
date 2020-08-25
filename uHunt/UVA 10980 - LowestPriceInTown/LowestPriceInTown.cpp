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

struct deal {
	int n;
	double p;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M;

int main() {
	deal unit;
	unit.n = 1;
	//double price;
	int caseNum = 1;
	while (cin >> unit.p >> M) {
		cout << "Case " << caseNum++ << ":" << endl;
		vector<deal> deals;
		deals.push_back(unit);
		for (int i = 0; i < M; i++) {
			deal add;
			cin >> add.n >> add.p;
			//add.p = (price+1e-6)*100;
			//cout << add.p << endl;
			deals.push_back(add);
		}
		int N = deals.size();
		double dp[201];
		for (int i = 0; i <= 200; i++) dp[i] = deals[0].p * i;
		for (int i = 0; i < N; i++) {
			double pr = deals[i].p;
			int cnt = deals[i].n;
			for (int j = 0; j <= 200-cnt; j++) {
				dp[j+cnt] = min(dp[j+cnt],dp[j] + pr);
			}
		}
		for (int i = 0; i <= 100; i++) {
			for (int j = i; j <= 200; j++) {
				dp[i] = min(dp[i],dp[j]);
			}
		}
		cin.ignore();
		string s;
		getline(cin,s);
		stringstream ss(s);
		int K;
		cout << setprecision(2) << fixed;
		while (ss >> K) {
			cout << "Buy " << K <<" for $" << dp[K] << endl;
		}
	}
    return 0;
}
