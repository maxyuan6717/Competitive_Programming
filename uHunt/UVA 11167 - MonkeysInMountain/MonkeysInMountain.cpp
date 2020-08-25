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

struct monkey {
	int v,a,b;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M;
monkey monkeys[100];

int main() {
	cin >> N;
	while (N) {
		cin >> M;
		for (int i = 0; i < N; i++) {
			monkey m;
			cin >> m.v >> m.a >> m.b;
		}
		cin >> N;
	}
    return 0;
}
