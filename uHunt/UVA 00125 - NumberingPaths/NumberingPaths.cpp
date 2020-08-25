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

int N;
int arr[30][30];

int main() {
	int caseNum = 0;
	while (cin >> N) {
		int largest = 0;
		for (int i = 0; i < 30; i++)
			for (int j = 0; j < 30; j++)
				arr[i][j] = 0;
		for (int i = 0; i < N; i++) {
			int u,v;
			cin >> u >> v;
			largest = max(largest,max(u,v));
			arr[u][v] = 1;
		}
		largest++;
		for (int k = 0; k < largest; k++) {
			for (int i = 0; i < largest; i++) {
				for (int j = 0; j < largest; j++) {
					if (arr[i][k] && arr[k][j]) arr[i][j] += arr[i][k] * arr[k][j];
				}
			}
		}
		for (int k = 0; k < largest; k++) {
			if (!arr[k][k]) continue;
			for (int i = 0; i < largest; i++) {
				for (int j = 0; j < largest; j++) {
					if (arr[i][k] && arr[k][j]) arr[i][j] = -1;
				}
			}
		}
		cout << "matrix for city " << caseNum++ << endl;
		for (int i = 0; i < largest; i++) {
			for (int j = 0; j < largest; j++) {
				cout << arr[i][j];
				if (j != largest-1) cout << " ";
			}
			cout << endl;
		}
	}
    return 0;
}
