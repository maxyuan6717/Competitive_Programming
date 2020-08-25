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

int N,D;
int dig[100001];

int main() {
	while (cin >> N >> D, N || D) {
		for (int i = 0; i < N; i++) {
			char c;
			cin >> c;
			dig[i] = c-'0';
		}
		int cur = 0;
		int high = -1,next,left = N-D;
		string ans = "";
		while (left) {
			for (int i = cur; i <= N-left; i++) {
				if (dig[i] > high) {
					high = dig[i];
					next = i;
				}
			}
			cout << high;
			cur = next+1;
			high = -1;
			left--;
		}
		cout << endl;
	}
    return 0;
}
