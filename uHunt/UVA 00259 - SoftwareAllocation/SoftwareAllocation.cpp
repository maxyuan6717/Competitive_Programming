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

int res[38][38];
int vis[38];
int p[38];
int S,T;
int N = 37;
int total;

bool bfs() {
	for (int i = 0; i <= N; i++) { vis[i] = 0; p[i] = 0; }
	vis[S] = 1, p[S] = -1;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == T) return 1;
		for (int i = 0; i <= N; i++) {
			if (vis[i] || !res[u][i]) continue;
			q.push(i);
			vis[i] = 1;
			p[i] = u;
		}
	}
	return 0;
}

int ek() {
	int ans = 0;
	while (bfs()) {
		int flow = LARGE;
		for (int i = T; i != S; i = p[i]) {
			flow = min(flow,res[p[i]][i]);
		}
		for (int i = T; i != S; i = p[i]) {
			res[p[i]][i] -= flow;
			res[i][p[i]] += flow;
		}
		ans += flow;
	}
	return ans;
}

void input(string s) {
	string s1,s2;
	stringstream ss(s);
	ss >> s1 >> s2;
	int i1 = s1[0] - 'A' + 1;
	int c = s1[1] - '0';
	res[0][i1] = c;
	total += c;
	for (int i = 0; i < s2.size()-1; i++) {
		int i2 = s2[i] - '0' + 27;
		res[i2][37] = 1;
		res[i1][i2] = LARGE;
	}
}

void printans() {
	for (int i = 27; i < 37; i++) {
		bool used = 0;
		for (int j = 1; j <= 26; j++) {
			if (res[i][j]) {
				used = 1;
				char out = j-1+'A';
				cout << out;
				break;
			}
		}
		if (!used) cout << "_";
	}
	cout << endl;
}

int main() {
	string s;
	//ifstream fin ("in");
	while (getline(cin,s)) {
		total = 0;
		memset(res,0,sizeof(res));
		input(s);
		while (getline(cin,s),s != "") input(s);
		S = 0, T = 37;
		int ans = ek();
		if (ans != total) cout << "!" << endl;
		else printans();
	}
    return 0;
}
