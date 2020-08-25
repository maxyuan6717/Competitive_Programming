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

int R,C,K;
string s;
char arr[50][50];
bool vis[50][50];
int dr[8] = {0,0,1,-1,1,1,-1,-1};
int dc[8] = {1,-1,0,0,1,-1,1,-1};

vii spoints[26];

bool inbounds(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int dfs(int r, int c, string seq, int dir) {
	seq += arr[r][c];
	int len = seq.size();
	vis[r][c] = 1;
	if (seq == s) return 1;
	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (!inbounds(nr,nc)) return 0;
	if (arr[nr][nc] != s[len] || vis[nr][nc]) return 0;
	int res = dfs(nr,nc,seq,dir);
	if (res) return 1;
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> R >> C;
		for (int i = 0; i < 26; i++) spoints[i].clear();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char c;
				cin >> c;
				arr[i][j] = tolower(c);
				spoints[arr[i][j]-'a'].push_back(mp(i,j));
			}
		}
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> s;
			for (int j = 0; j < s.size(); j++) s[j] = tolower(s[j]);
			for (int j = 0; j < spoints[s[0]-'a'].size(); j++) {
				int r = spoints[s[0]-'a'][j].first;
				int c = spoints[s[0]-'a'][j].second;
				int done = 0;
				for (int i = 0; i < 8; i++) {
					memset(vis,0,sizeof(vis));
					if (dfs(r,c,"",i)) {
						cout << r+1 << " " << c+1 << endl;
						done = 1;
						break;
					}
				}
				if (done) break;
			}
		}
		if (t != T-1) cout << endl;
	}
    return 0;
}
