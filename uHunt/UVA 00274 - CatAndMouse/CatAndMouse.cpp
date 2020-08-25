#include <iostream>
#include <fstream>
#include <sstream>
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
#include <iomanip>
#include <climits>

#define LARGE 100000
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,C,M;
int arr[101][101][2];
int vis[101];
vector<int> adj[101];

int bfs() {
	queue<pii> q;
	q.push(mp(M,0));
	while (!q.empty()) {
		int u = q.front().first;
		int c = q.front().second;
		q.pop();
		if (u == M && c != 0) return 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (vis[v]) continue;
			if (arr[C][v][0]) continue;
			vis[v] = 1;
			q.push(mp(v,c+1));
		}
	}
	return 0;
}

int main() {
	//ifstream fin ("test");
	int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
    	cin >> N >> C >> M;
    	//cout << N << " " << C << " " << M << endl;
    	for (int i = 0; i <= N; i++) {
    		vis[i] = 0;
    		adj[i].clear();
    		for (int j = 0; j <= N; j++) {
    			arr[i][j][0] = 0;
    			arr[i][j][1] = 0;
    			if (i == j) {
    				arr[i][j][0] = 1;
    				arr[i][j][1] = 1;
    			}
    		}
    	}
    	int u,v;
    	while (cin >> u >> v && u != -1 && v != -1) {
    		arr[u][v][0] = 1;
    		//cout << u << " " << v << endl;
    	}
    	cin.ignore();
    	string s;
    	getline(cin,s);
    	while (s != "") {
    		stringstream ss(s);
    		ss >> u >> v;
    		arr[u][v][1] = 1;
    		adj[u].push_back(v);
    		getline(cin,s);
    		//cout << u << " " << v << endl;
    	}
    	for (int k = 1; k <= N; k++) {
    		for (int i = 1; i <= N; i++) {
    			for (int j = 1; j <= N; j++) {
    				arr[i][j][0] |= arr[i][k][0] && arr[k][j][0];
    				arr[i][j][1] |= arr[i][k][1] && arr[k][j][1];
    			}
    		}
    	}
    	char ans1 = 'N';
    	for (int i = 1; i <= N; i++) {
    		if (arr[C][i][0] && arr[M][i][1]) {
    			ans1 = 'Y';
    			break;
    		}
    	}
    	char ans2 = 'N';
    	if (bfs()) ans2 = 'Y';
    	cout << ans1 << " " << ans2 << endl;
    	if (t != T) cout << endl;
    }
    return 0;
}
