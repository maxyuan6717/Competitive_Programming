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

char arr[20][20];
bool vis[20][20];
int N;
int dr[8] = {1,-1,0,0,1,1,-1,-1};
int dc[8] = {0,0,1,-1,1,-1,1,-1};
vector<string> ans;
map<string,bool> used;

bool comp (string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

bool inbounds(int r, int c) {
	return (r >= 0 && r < N && c >= 0 && c < N);
}

void rec(int r, int c, int len, string str) {
	str += arr[r][c];
	if (len > 2) {
		if (!used[str]) {
			ans.push_back(str);
			used[str] = 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (vis[nr][nc] || arr[nr][nc] <= arr[r][c]) continue;
		vis[nr][nc] = 1;
		rec(nr,nc,len+1,str);
		vis[nr][nc] = 0;
	}
}

int main() {
	int T;
	cin >> T;
	ofstream fout("out");
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		ans.clear();
		used.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) for (int l = 0; l < N; l++) vis[k][l] = 0;
				rec(i,j,1,"");
			}
		}
		sort(ans.begin(),ans.end(),comp);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
		if (t != T-1) cout << endl;
	}
    return 0;
}
