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

int main() {
	int N,M;
	while (cin >> N >> M) {
		vector<int> adj[1000001];
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			adj[num].push_back(i+1);
		}
		for (int i = 0; i < M; i++) {
			int k,v;
			cin >> k >> v;
			if (adj[v].size() < k) cout << 0 << endl;
			else cout << adj[v][k-1] << endl;
		}
	}
    
    return 0;
}
