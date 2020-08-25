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

int K;
char arr1[6][5],arr2[6][5];
map<string,bool> used;
vector<string> ans;

void rec(int col, string seq) {
	//cout << col << " " << seq << endl;
	if (col == 5) {
		if (used[seq]) return;
		used[seq] = 1;
		ans.push_back(seq);
		return;
	}
	for (int i = 0; i < 6; i++) {
		char c = arr1[i][col];
		bool found = 0;
		for (int j = 0; j < 6; j++) {
			if (arr2[j][col] == c) {
				found = 1;
				break;
			}
		}
		if (!found) continue;
		string next = seq + c;
		rec(col+1,next);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> K;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 5; j++)
				cin >> arr1[i][j];
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 5; j++)
				cin >> arr2[i][j];
		ans.clear();
		used.clear();
		rec(0,"");
		if (ans.size() < K) {
			cout << "NO" << endl;
			continue;
		}
		sort(ans.begin(),ans.end());
		cout << ans[K-1] << endl;
	}
    return 0;
}
