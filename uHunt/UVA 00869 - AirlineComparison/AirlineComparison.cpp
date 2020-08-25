#include <iostream>
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

int N,M;
int arr1[26][26];
int arr2[26][26];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(arr1,0,sizeof(arr1));
		memset(arr2,0,sizeof(arr2));
		cin >> N;
		for (int i = 0; i < N; i++) {
			char a,b;
			cin >> a >> b;
			int i1 = a - 'A';
			int i2 = b - 'A';
			arr1[i1][i2] = 1;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			char a,b;
			cin >> a >> b;
			int i1 = a - 'A';
			int i2 = b - 'A';
			arr2[i1][i2] = 1;
		}
		for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					arr1[i][j] |= arr1[i][k] & arr1[k][j];
					arr2[i][j] |= arr2[i][k] & arr2[k][j];
				}
			}
		}
		string ans = "YES";
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (arr1[i][j] != arr2[i][j]) {
					ans = "NO";
					break;
				}
			}
			if (ans == "NO") break;
		}
		cout << ans << endl;
		if (t != T-1) cout << endl;
	}
    return 0;
}
