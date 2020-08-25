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

int arr[101][101];

int main() {
	int u,v;
	cin >> u >> v;
	int caseNum = 1;
	while (u || v) {
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				arr[i][j] = 100000;
				if (i == j) arr[i][i] = 0;
			}
		}
		arr[u][v] = 1;
		cin >> u >> v;
		while (u || v) {
			arr[u][v] = 1;
			cin >> u >> v;
		}
		for (int k = 1; k <= 100; k++)
			for (int i = 1; i <= 100; i++)
				for (int j = 1; j <= 100; j++)
					arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
		double total = 0;
		double cnt = 0;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if (arr[i][j] == 100000 || i == j) continue;
				total += arr[i][j];
				cnt++;
			}
		}
		cout << "Case " << caseNum++ << ": average length between pages = ";
		cout << setprecision(3) << fixed;
		cout << total/cnt;
		cout << " clicks" << endl;
		cin >> u >> v;
	}
    
    return 0;
}
