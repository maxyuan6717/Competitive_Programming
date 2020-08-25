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

#define LARGE 999999999
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

int M,N;
int dp[81][81];

int main() {
    string s1,s2;
    int caseNum = 0;
    while (getline(cin,s1)) {
    	getline(cin,s2);
    	if (caseNum++) cout << endl;
		int M = int(s1.size());
		int N = int(s2.size());
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				if (i == 0) dp[i][j] = j;
				else if (j == 0) dp[i][j] = i;
				else if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
			}
		}
		cout << dp[M][N] << endl;
		int i = M, j = N;
		int cnt = 1;
		while (i || j) {
			if (s1[i-1] == s2[j-1]) {
				i--, j--;
				continue;
			}
			cout << cnt++ << " ";
			if (i && dp[i][j] == dp[i-1][j] + 1) {
				cout << "Delete " << i << endl;
				s1.erase(i-1,1);
				i--;
				continue;
			}
			if (j && dp[i][j] == dp[i][j-1] + 1) {
				cout << "Insert " << i+1 << "," << s2[j-1] << endl;
				s1.insert(i,1,s2[j-1]);
				j--;
				continue;
			}
			if (i && j) {
				cout << "Replace " << i << "," << s2[j-1] << endl;
				s1[i-1] = s2[j-1];
				i--,j--;
			}
		}
    }
    return 0;
}
