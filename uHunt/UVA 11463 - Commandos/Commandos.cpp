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
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,R;
int arr[100][100];

int main() {
	int T;
	cin >> T;
    for (int t = 1; t <= T; t++) {
    	cin >> N >> R;
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < N; j++) {
    			arr[i][j] = 100000;
    			if (i == j) arr[i][i] = 0;
    		}
    	}
    	for (int i = 0; i < R; i++) {
    		int u,v;
    		cin >> u >> v;
    		arr[u][v] = 1;
    		arr[v][u] = 1;
    	}
    	for (int k = 0; k < N; k++)
    		for (int i = 0; i < N; i++)
    			for (int j = 0; j < N; j++)
    				arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
    	int s,d;
    	cin >> s >> d;
    	int ans = 0;
    	for (int k = 0; k < N; k++) {
    		if (arr[s][k] == 100000 || arr[k][d] == 100000) continue;
    		ans = max(ans,arr[s][k] + arr[k][d]);
    	}
    	cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}
