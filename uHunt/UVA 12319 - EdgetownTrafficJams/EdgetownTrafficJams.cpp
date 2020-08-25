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

int N,orig[101][101],cur[101][101],A,B;
string ans[2] = {"No","Yes"};

int main() {
	while (cin >> N, N) {
		cin.ignore();
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				if (i != j) orig[i][j] = cur[i][j] = 10000;
				else orig[i][j] = cur[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			string s;
			getline(cin,s);
			stringstream ss(s);
			int u,v;
			ss >> u;
			while (ss >> v) orig[u][v] = 1;
		}
		for (int i = 0; i < N; i++) {
			string s;
			getline(cin,s);
			stringstream ss(s);
			int u,v;
			ss >> u;
			while (ss >> v) cur[u][v] = 1;
		}
		cin >> A >> B;
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					orig[i][j] = min(orig[i][j],orig[i][k] + orig[k][j]);
					cur[i][j] = min(cur[i][j],cur[i][k] + cur[k][j]);
				}
			}
		}
		bool works = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (cur[i][j] == 10000 || cur[i][j] > A*orig[i][j] + B) works = 0;
			}
		}
		cout << ans[works] << endl;
	}
    return 0;
}
