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

struct tile {
	int l,m;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
tile tiles[10000];

bool compare(tile a, tile b) {
	if (a.l != b.l) return a.l < b.l;
	else return a.m < b.m;
}

int lis() {
	int len = 0;
	vector<int> seq;
	for (int i = 0; i < N; i++) {
		int indx = upper_bound(seq.begin(),seq.end(),tiles[i].m) - seq.begin();
		if (indx == len) {
			seq.push_back(tiles[i].m);
			len++;
		}
		else {
			seq[indx] = tiles[i].m;
		}
	}
	return len;
}


int main() {
	while (cin >> N, N) {
		for (int i = 0; i < N; i++) cin >> tiles[i].l >> tiles[i].m;
		sort(tiles,tiles+N,compare);
		cout << lis() << endl;
	}
	cout << "*" << endl;
    return 0;
}
