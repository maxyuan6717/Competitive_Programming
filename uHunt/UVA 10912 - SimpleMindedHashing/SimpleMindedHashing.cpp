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
#define maxSum 27*13

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int ans[27][27][maxSum+1];

int main() {
	memset(ans,0,sizeof(ans));
	for (int i = 1; i <= 26; i++) ans[i][1][i] = 1;
	for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= maxSum; k++) {
				ans[i][j][k] += ans[i-1][j][k];
				if (j > 1 && k >= i) {
					ans[i][j][k] += ans[i-1][j-1][k-i];
				}
			}
		}
	}
	int L,S,caseNum = 1;
	while (cin >> L >> S, L || S) {
		cout << "Case " << caseNum++ << ": ";
		if (L > 26 || S > maxSum) cout << 0 << endl;
		else cout << ans[26][L][S] << endl;
	}
    return 0;
}
