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

int arr[1<<15];
int N,num;

bool check(int a, int b) {
	int c = a^b;
	return (c&(-c)) == c;
}

int main() {
	while (cin >> N) {
		N = 1<<N;
		for (int i = 0; i < N; i++) arr[i] = 0;
		for (int i = 0; i < N; i++) {
			cin >> num;
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (check(i,j)) arr[j] += num;
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (check(i,j)) ans = max(ans,arr[i] + arr[j]);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
