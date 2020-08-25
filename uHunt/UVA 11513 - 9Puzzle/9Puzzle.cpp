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
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct point {
	vector<string> v;
	string seq;
	int moves;
};

struct ans {
	int moves;
	string seq;
};

vector<string> start;
vector<string> final;
map<vector<string>, ans> vis;
map<vector<string>, bool> vis2;

vector<string> hshift(vector<string> v, int r) {
	string change;
	string s1 = v[r].substr(0,1);
	string s2 = v[r].substr(1,2);
	change = s2 + s1;
	v[r] = change;
	return v;
}

vector<string> vshift(vector<string> v, int c) {
	char temp = v[2][c];
	v[2][c] = v[1][c];
	v[1][c] = v[0][c];
	v[0][c] = temp;
	return v;
}

void bfs() {
	queue<point> q;
	point st = {final,"",0};
	ans sta = {0,""};
	vis[final] = sta;
	vis2[final] = 1;
	q.push(st);
	while (!q.empty()) {
		point u = q.front();
		ans u2 = {u.moves,u.seq};
		vis[u.v] = u2;
		q.pop();
		for (int i = 0; i < 3; i++) {
			vector<string> n = hshift(u.v,i);
			if (vis2[n]) continue;
			char num = i + '1';
			string str = "H";
			str += num;
			point v = {n,str + u.seq,u.moves+1};
			vis2[n] = 1;
			q.push(v);
		}
		for (int i = 0; i < 3; i++) {
			vector<string> n = vshift(u.v,i);
			if (vis2[n]) continue;
			char num = i + '1';
			string str = "V";
			str += num;
			point v = {n,str + u.seq,u.moves+1};
			vis2[n] = 1;
			q.push(v);
		}
	}
}

int main() {
	string s1;
	cin >> s1;
	vis.clear();
	vis2.clear();
	final.push_back("123");
	final.push_back("456");
	final.push_back("789");
	bfs();
	while (s1 != "0") {
		start.clear();
		string s2, s3;
		cin >> s2 >> s3;
		s1 += s2 + s3;
		start.push_back(s1);
		for (int i = 0; i < 2; i++) {
			cin >> s1 >> s2 >> s3;
			s1 += s2 + s3;
			start.push_back(s1);
		}
		if (!vis2[start]) cout << "Not solvable" << endl;
		else {
			ans output = vis[start];
			cout << output.moves << " " << output.seq << endl;
		}
		cin >> s1;
	}
    
    return 0;
}
