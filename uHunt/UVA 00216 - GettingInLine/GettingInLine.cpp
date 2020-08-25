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
#include <iomanip>

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
double ans = LARGE;
vector<int> ansseq;
vector<int> curseq;
double dis[8][8];
int N;

double dist(int x1, int y1, int x2, int y2) {
	return (sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))) + 16);
}

int once = 1;

void solve(int cur, int vis, double sum) {
	if (vis == (1<<N)-1) {
		if (sum < ans) {
			ans = sum;
			ansseq = curseq;
		}
		return;
	}
	vis |= 1<<cur;
	for (int i = 0; i < N; i++) {
		if (vis & 1<<i) continue;
		curseq.push_back(i);
		solve(i,vis|1<<i,sum + dis[cur][i]);
		curseq.pop_back();
	}
}

int main() {
	int counter = 1;
    cin >> N;
    while (N) {
    	vii points;
    	for (int i = 0; i < N; i++) {
    		int x, y;
    		cin >> x >> y;
    		points.push_back(mp(x,y));
    	}
    	for (int i = 0; i < N; i++) {
    		for (int j = i+1; j < N; j++) {
    			dis[i][j] = dist(points[i].first,points[i].second,points[j].first,points[j].second);
    			dis[j][i] = dis[i][j];
    		}
    	}
    	ans = LARGE;
    	ansseq.clear();
    	for (int i = 0; i < N; i++) {
    		curseq.clear();
    		curseq.push_back(i);
    		solve(i,0,0);
    	}
    	cout << setprecision(2) << fixed;
    	cout << "**********************************************************" << endl;
    	cout << "Network #" << counter << endl;
    	for (int i = 0; i < N-1; i++) {
    		cout << "Cable requirement to connect (" << points[ansseq[i]].first << "," << points[ansseq[i]].second << ") to (";
    		cout << points[ansseq[i+1]].first << "," << points[ansseq[i+1]].second << ") is " << dis[ansseq[i]][ansseq[i+1]] << " feet." << endl;
    	}
    	cout << "Number of feet of cable required is " << ans << "." << endl;
    	cin >> N;
    	counter++;
    }
    return 0;
}
