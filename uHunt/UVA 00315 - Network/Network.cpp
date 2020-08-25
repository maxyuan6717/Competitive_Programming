#include <iostream>
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

#define LARGE (1<<31)-1

using namespace std;

int N;
int arr[101][101];
int vis[101];
int visCount = 0;
int down;
int critCount = 0;

void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 1; i <= N; i++) {
		if (!arr[cur][i]) continue;
		if (vis[i] || i == down) continue;
		dfs(i);
	}
}

int main() {
	cin >> N;
	while (N) {
		cin.ignore();
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				arr[i][j] = 0;
			}
		}
		string s;
		while (getline(cin,s) && s != "0") {
			stringstream ss(s);
			int u,v;
			ss >> u;
			while (ss >> v) {
				arr[u][v] = 1;
				arr[v][u] = 1;
			}
		}
		critCount = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= N; j++) vis[j] = 0;
			down = i;
			dfs(1+(i)%N);
			for (int j = 1; j <= N; j++) {
				if (!vis[j] && j != down) {
					critCount++;
					break;
				}
			}
		}
		cout << critCount << endl;
		cin >> N;
	}
    return 0;
}
