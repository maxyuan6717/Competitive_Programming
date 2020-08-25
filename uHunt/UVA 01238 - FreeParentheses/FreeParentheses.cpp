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

int n[31];
int s[31];
int indx,ans;
bool vis[31][6001][31];
bool used[6001];

void rec(int cur,int sum, int open) {
	if (vis[cur][sum+3000][open]) return;
	vis[cur][sum+3000][open] = 1;
	if (cur == indx) {
		if (!used[sum+3000]) {
			used[sum+3000] = 1;
			ans++;
		}
		return;
	}
	int add = s[cur] * n[cur+1];
	if (open%2) add *= -1;
	sum += add;
	if (s[cur] == -1) rec(cur+1,sum,open+1);
	if (open) rec(cur+1,sum,open-1);
	rec(cur+1,sum,open);
}

int main() {
	string str;
	while (getline(cin,str)) {
		memset(vis,0,sizeof(vis));
		memset(used,0,sizeof(used));
		stringstream ss(str);
		ss >> n[0];
		indx = ans = 0;
		char sign;
		while (ss >> sign) {
			if (sign == '+') s[indx++] = 1;
			else s[indx++] = -1;
			ss >> n[indx];
		}
		rec(0,0,0);
		cout << ans << endl;
	}
    return 0;
}
