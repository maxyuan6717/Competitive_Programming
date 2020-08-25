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

string s1[100];
string s2[100];

int main() {
	while (cin >> s1[0]) {
		int N = 0, M = 1;
		while (cin >> s1[M++], s1[M-1] != "#");
		while (cin >> s2[N++], s2[N-1] != "#");
		M--,N--;
		int dp[101][101];
		vector<string> seq[101][101];
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = 0;
				seq[i][j].clear();
			}
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
					seq[i][j] = seq[i-1][j-1];
					seq[i][j].push_back(s1[i-1]);
				}
				else {
					if (dp[i][j-1] > dp[i-1][j]) {
						seq[i][j] = seq[i][j-1];
						dp[i][j] = dp[i][j-1];
					}
					else {
						seq[i][j] = seq[i-1][j];
						dp[i][j] = dp[i-1][j];
					}
				}
			}
		}
	    for (int i = 0; i < seq[M][N].size(); i++) {
	    	cout << seq[M][N][i];
	    	if (i != seq[M][N].size()-1) cout << " ";
	    }
	    cout << endl;
	}
    return 0;
}
