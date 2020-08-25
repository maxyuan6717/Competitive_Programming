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

int N,M,a,b,c;
bool bit[1000001];

int main() {
	while (cin >> N >> M, N || M) {
		memset(bit,0,sizeof(bit));
		bool works = 1;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			if (!works) continue;
			for (int j = a; j < b; j++) {
				if (bit[j]) {
					works = 0;
					break;
				}
				bit[j] = 1;
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			int d = b-a;
			if (!works) continue;
			for (int j = a; j <= 1000000; j += c) {
				for (int k = j; k < j + d && k <= 1000000; k++) {
					if (bit[k]) {
						works = 0;
						break;
					}
					bit[k] = 1;
				}
				if (!works) break;
			}
		}
		if (!works) cout << "CONFLICT" << endl;
		else cout << "NO CONFLICT" << endl;
	}
    return 0;
}
