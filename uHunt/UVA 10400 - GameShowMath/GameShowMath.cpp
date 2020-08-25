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

int N,nums[100],goal,op[100];
bool used[100][64000];
char operations[4] = {'+','-','*','/'};

bool works(int x) {
	return (x > -32000 && x < 32000);
}

void print() {
	for (int i = 0; i < N-1; i++) {
		cout << nums[i] << operations[op[i]];
	}
	cout << nums[N-1] << '=' << goal << endl;
}

bool rec(int indx, int sum) {
	if (used[indx][sum+32000]) return 0;
	used[indx][sum+32000] = 1;
	if (indx == N-1) {
		if (sum == goal) {
			print();
			return 1;
		}
		return 0;
	}
	if (works(sum + nums[indx+1])) {
		op[indx] = 0;
		if (rec(indx+1,sum+nums[indx+1])) return 1;
	}
	if (works(sum - nums[indx+1])) {
		op[indx] = 1;
		if (rec(indx+1,sum-nums[indx+1])) return 1;
	}
	if (works(sum * nums[indx+1])) {
		op[indx] = 2;
		if (rec(indx+1,sum*nums[indx+1])) return 1;
	}
	if (sum%nums[indx+1] == 0 && works(sum/nums[indx+1])) {
		op[indx] = 3;
		if (rec(indx+1,sum/nums[indx+1])) return 1;
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(used,0,sizeof(used));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		cin >> goal;
		if (!rec(0,nums[0])) cout << "NO EXPRESSION" << endl;
	}
    return 0;
}
