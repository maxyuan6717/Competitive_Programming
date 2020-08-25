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

unsigned long long ans[62][61];

unsigned long long trib(int n, unsigned int back) {
	if (n < 0) return 1;
	if (ans[n][back] != -1) return ans[n][back];
	int i;
	unsigned long long cnt = 1;
	if(n<=1) return ans[n][back] = 1;
	for(i=1;i<=back;i++) cnt += trib(n-i,back);
	return ans[n][back] = cnt;
}

int main() {
	//ofstream fout ("out");
	memset(ans,-1,sizeof(ans));
	for (int i = 0; i <= 61; i++) {
		for (int j = 0; j <= 60; j++) {
			trib(i,j);
		}
	}
	int n,back,caseNum = 1;
	while (cin >> n >> back, n <= 60) {
		if (n < 0) {
			cout << "Case " << caseNum++ << ": " << 1 << endl;
			continue;
		}
		cout << "Case " << caseNum++ << ": " << ans[n][back] << endl;
	}
    return 0;
}
