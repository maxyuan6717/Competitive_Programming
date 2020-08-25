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

struct point {
	int x,y;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
double R;
point points[100];

double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
	while (cin >> N, N) {
		for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
		cin >> R;
		bool works = 1;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				double d = dist(points[i],points[j]);
				if (d > 2*R) {
					works = 0;
					break;
				}
			}
			if (!works) break;
		}
		if (works) cout << "The polygon can be packed in the circle." << endl;
		else cout << "There is no way of packing that polygon." << endl;
	}
    return 0;
}
