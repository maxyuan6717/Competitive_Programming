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

string s;

int toInt(string s) {
	stringstream ss(s);
	long long ret;
	ss >> ret;
	if (ret <= LARGE) return int(ret);
	else return -1;
}

int main() {
	int T;
	cin >> T;
	cin.ignore();
	for (int t = 0; t < T; t++) {
		getline(cin,s);
		string temp = " ";
		temp += s;
		s = temp;
		int N = s.size();
		long long dp[N+1];
		for (int i = 0; i <= N; i++) dp[i] = 0;
		for (int i = 1; i < N; i++) {
			for (int j = i; j >= 1 && i-j< 10; j--) {
				//if (s[j] == '0') continue;
				string sub = s.substr(j,(i-j)+1);
				int num = toInt(sub);
				if (num == -1) break;
				dp[i] = max(dp[i],dp[j-1] + num);
				//cout << i << " " << j << " " << sub << " " << num << " " << dp[i] << endl;
			}
		}
		cout << dp[N-1] << endl;
	}
    return 0;
}
