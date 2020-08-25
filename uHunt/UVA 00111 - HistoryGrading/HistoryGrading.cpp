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
int seq1[21];
int seq2[21];

int main() {
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		seq1[num-1] = i;
	}
	cin.ignore();
	while (getline(cin,s)) {
		//vcout << s << endl;
		stringstream ss(s);
		int num;
		for (int i = 0; i < N; i++) {
			ss >> num;
			seq2[num-1] = i;
		}
		int dp[21][21];
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j] = 0;
				if (seq1[i-1] == seq2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout << dp[N][N] << endl;
	}
    return 0;
}
