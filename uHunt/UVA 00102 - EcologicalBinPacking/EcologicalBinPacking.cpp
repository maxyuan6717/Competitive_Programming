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

int main() {
	int arr[3][3];
	string bottle[3] = {"B","G","C"};
	int moves[6][3] = {
			{0,2,1},
			{0,1,2},
			{2,0,1},
			{2,1,0},
			{1,0,2},
			{1,2,0}
	};
	string s;
	while (getline(cin,s)) {
		stringstream ss(s);
		//cout << s << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				ss >> arr[i][j];
			}
		}
		int ans1 = LARGE;
		string ans2 = "";
		for (int i = 0; i < 6; i++) {
			int sum = 0;
			string str = bottle[moves[i][0]] + bottle[moves[i][1]] + bottle[moves[i][2]];
			if (i == 0) sum = arr[1][0] + arr[2][0] + arr[0][2] + arr[2][2] + arr[0][1] + arr[1][1];
			else if (i == 1) sum = arr[1][0] + arr[2][0] + arr[0][1] + arr[2][1] + arr[0][2] + arr[1][2];
			else if (i == 2) sum = arr[1][2] + arr[2][2] + arr[0][0] + arr[2][0] + arr[0][1] + arr[1][1];
			else if (i == 3) sum = arr[1][2] + arr[2][2] + arr[0][1] + arr[2][1] + arr[0][0] + arr[1][0];
			else if (i == 4) sum = arr[1][1] + arr[2][1] + arr[0][0] + arr[2][0] + arr[0][2] + arr[1][2];
			else if (i == 5) sum = arr[1][1] + arr[2][1] + arr[0][2] + arr[2][2] + arr[0][0] + arr[1][0];
			if (sum < ans1) {
				ans1 = sum;
				ans2 = str;
			}
		}
		cout << ans2 << " " << ans1 << endl;
	}
    return 0;
}
