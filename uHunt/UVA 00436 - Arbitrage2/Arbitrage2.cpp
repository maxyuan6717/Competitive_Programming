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

int N,M;
map<string,int> indx;
double arr[30][30];

int main() {
	cin >> N;
	int caseNum = 1;
	while (N) {
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			indx[s] = i;
			for (int j = 0; j < N; j++) {
				arr[i][j] = 0;
				if (i == j) arr[i][j] = 1;
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			string s1, s2;
			double c;
			cin >> s1 >> c >> s2;
			int i1 = indx[s1], i2 = indx[s2];
			arr[i1][i2] = c;
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					double temp = arr[i][k] * arr[k][j];
					arr[i][j] = max(arr[i][j],temp);
				}
			}
		}
		string ans = "No";
		for (int i = 0; i < N; i++) {
			if (arr[i][i] > 1.0001) {
				ans = "Yes";
				break;
			}
		}
		cout << "Case " << caseNum++ << ": ";
		cout << ans << endl;
		cin >> N;
	}
    return 0;
}
