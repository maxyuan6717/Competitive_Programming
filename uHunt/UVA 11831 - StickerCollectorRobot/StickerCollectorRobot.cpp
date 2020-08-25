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
#include <bitset>

#define LARGE (1<<31)-1

using namespace std;

int N,M,S;
int arr[101][101];
int sr,sc,cr,cc;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int di;
string seq;

bool inbounds(int r, int c) {
	return (r >= 0 && r < N && c >= 0 && c < M);
}

int main() {
    cin >> N >> M >> S;
    while (N || M || S) {
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			char c;
    			cin >> c;
    			if (c == '.') arr[i][j] = 1;
    			else if (c == '*') arr[i][j] = 2;
    			else if (c == '#') arr[i][j] = 0;
    			else {
    				sr = i, sc = j;
    				if (c == 'N') di = 3;
    				else if (c == 'S') di = 1;
    				else if (c == 'L') di = 0;
    				else di = 2;
    				arr[i][j] = 1;
    			}
    		}
    	}
    	cin >> seq;
    	cr = sr, cc = sc;
    	int ans = 0;
    	for (int i = 0; i < S; i++) {
    		char c = seq[i];
    		if (c == 'D') di = (di+5)%4;
    		else if (c == 'E') di = (di+3)%4;
    		else {
    			int nr = cr + dr[di];
    			int nc = cc + dc[di];
    			if (inbounds(nr,nc) && arr[nr][nc]) {
    				cr = nr;
    				cc = nc;
    				if (arr[cr][cc] == 2) {
    					ans++;
    					arr[cr][cc] = 1;
    				}
    			}
    		}
    	}
    	cout << ans << endl;
    	cin >> N >> M >> S;
    }
    return 0;
}
