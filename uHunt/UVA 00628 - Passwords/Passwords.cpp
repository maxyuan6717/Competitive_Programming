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

int N,M;
string arr[100],rule;
char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
int len;
map<string,bool> used;

void rec(int indx, string str) {
	if (indx == len) {
		if (used[str]) return;
		used[str] = 1;
		cout << str << endl;
		return;
	}
	if (rule[indx] == '#') {
		for (int i = 0; i < N; i++) rec(indx + 1, str + arr[i]);
	}
	else if (rule[indx] == '0') {
		for (int i = 0; i < 10; i++) rec(indx + 1, str + nums[i]);
	}
}

int main() {
	while (cin >> N) {
		for (int i = 0; i < N; i++) cin >> arr[i];
		cin >> M;
		cout << "--" << endl;
		for (int i = 0; i < M; i++) {
			cin >> rule;
			len = rule.size();
			used.clear();
			rec(0,"");
		}
	}
    return 0;
}
