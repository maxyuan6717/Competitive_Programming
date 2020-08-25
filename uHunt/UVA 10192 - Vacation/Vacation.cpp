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

int main() {
	string s1,s2;
	int caseNum = 1;
	while (getline(cin,s1), s1 != "#") {
		getline(cin,s2);
		int M = s1.size();
		int N = s2.size();
		int dp[2][N+1];
		for (int i = 0; i < 2; i++) for (int j = 0; j <= N; j++) dp[i][j] = 0;
	    for (int i = 1; i <= M; i++) {
	        for (int j = 1; j <= N; j++) {
	            if (s1[i-1] == s2[j-1]) dp[1][j] = dp[0][j-1] + 1;
	            else dp[1][j] = max(dp[1][j-1],dp[0][j]);
	        }
	        for (int j = 0; j <= N; j++) dp[0][j] = dp[1][j];
	    }
	    cout << "Case #" << caseNum++ << ": " << "you can visit at most " << dp[0][N] << " cities." << endl;
	}
    return 0;
}
