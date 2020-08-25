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

int B,S;
int num;

int main() {
	cin >> B >> S;
	int caseNum = 1;
	while (B || S) {
		int minimum = LARGE;
		for (int i = 0; i < B; i++) {
			cin >> num;
			minimum = min(minimum,num);
		}
		for (int i = 0; i < S; i++) cin >> num;
		cout << "Case " << caseNum++ << ": ";
		if (B <= S) cout << 0 << endl;
		else cout << B-S << " " << minimum << endl;
		cin >> B >> S;
	}
    return 0;
}
