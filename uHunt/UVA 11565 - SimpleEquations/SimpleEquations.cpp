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

int main() {
	int N;
	cin >> N;
	for (int n = 0; n < N; n++) {
		int A,B,C;
		cin >> A >> B >> C;
		int done = 0;
		for (int x = -100; x <= 100; x++) {
			for (int y = x + 1; y <= 100; y++) {
				int xsqr = x*x;
				int ysqr = y*y;
				int zsqr = C-xsqr-ysqr;
				if (zsqr < 0) continue;
				int z = sqrt(zsqr);
				if (z*z != zsqr) continue;
				if (x + y + z != A) continue;
				if (x*y*z != B) continue;
				if (z == x || z == y) continue;
				cout << x << " " << y << " " << z << endl;
				done = 1;
				break;
			}
			if (done) break;
		}
		if (!done) cout << "No solution." << endl;
	}
    return 0;
}
