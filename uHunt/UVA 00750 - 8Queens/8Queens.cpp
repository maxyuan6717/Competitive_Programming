#include <iostream>
#include <fstream>
#include <string>
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

#define LARGE (1<<31)-1

using namespace std;

int t;
int mr,mc;
int indx[9];
int counter = 1;

bool check(int r, int c) {
	//HORIZONTAL
	for (int i = 1; i <= 8; i++) {
		if (i != c && indx[i] == r) return 0;
	}
	//DIAGONAL
	for (int i = 1; i <= 8; i++) {
		int nr = r + (i-c);
		if (nr >= 1 && nr <= 8) {
			if (i != c && indx[i] == nr) return 0;
		}
		nr = r + (c-i);
		if (nr >= 1 && nr <= 8) {
			if (i != c && indx[i] == nr) return 0;
		}
	}
	return 1;
}

void solve(int cur) {
	//cout << cur << endl;
	if (cur == mc) solve(cur+1);
	else {
		if (cur == 9) {
			if (counter < 10) cout << " " << counter << "     ";
			else cout << counter << "     ";
			for (int i = 1; i <= 8; i++) cout << " " << indx[i];
			cout << endl;
			counter++;
			return;
		}
		for (int i = 1; i <= 8; i++) {
			if (!check(i,cur)) continue;
			indx[cur] = i;
			//cout << i << " " << cur << endl;
			solve(cur+1);
			//indx[cur] = 0;
		}
		indx[cur] = 0;
	}
}

int main() {
    int C;
    cin >> C;
    for (t = 1; t <= C; t++) {
    	cin >> mr >> mc;
    	counter = 1;
    	cout << "SOLN       COLUMN" << endl;
    	cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
    	for (int i = 1; i <= 8; i++) indx[i] = 0;
    	indx[mc] = mr;
    	solve(1);
    	if (t != C) cout << endl;
    }
    return 0;
}
