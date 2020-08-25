#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
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

struct edge {
	string name;
	int c;
};

edge arr[101][101];
int p[101][101];

int main() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			arr[i][j].c = LARGE;
			p[i][j] = i;
		}
	}
	//ifstream fin ("test");
	string s;
	getline(cin,s);
	map<string,int> indx;
	map<int,string> rindx;
	int cindx = 1;
	while (s != "") {
		vector<string> v;
		int len = 0;
		int start = 0;
		for (int i = 0; i < s.size(); i++,len++) {
			if (s[i] == ',') {
				string add = s.substr(start,len);
				len = -1;
				start = i+1;
				v.push_back(add);
			}
		}
		string add = s.substr(start,len);
		v.push_back(add);
		string a = v[0], b = v[1], name = v[2], cost = v[3];
		stringstream ss(cost);
		int c;
		ss >> c;
		int i1 = indx[a];
		if (!i1) {
			i1 = cindx++;
			rindx[i1] = a;
		}
		indx[a] = i1;
		int i2 = indx[b];
		if (!i2) {
			i2 = cindx++;
			rindx[i2] = b;
		}
		indx[b] = i2;
		edge e = arr[i1][i2];
		if (c < arr[i1][i2].c) {
			e.c = c;
			e.name = name;
		}
		arr[i1][i2] = e;
		arr[i2][i1] = e;
		getline(cin,s);
	}
	for (int k = 1; k < cindx; k++) {
		for (int i = 1; i < cindx; i++) {
			for (int j = 1; j < cindx; j++) {
				if (arr[i][k].c == LARGE || arr[k][j].c == LARGE) continue;
				if (arr[i][k].c + arr[k][j].c < arr[i][j].c) {
					arr[i][j].c = arr[i][k].c + arr[k][j].c;
					p[i][j] = p[k][j];
				}
			}
		}
	}
	getline(cin,s);
	while (s != "") {
		string s1,s2;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ',') {
				s1 = s.substr(0,i);
				s2 = s.substr(i+1,s.size()-(i+1));
				break;
			}
		}
		int i1 = indx[s1];
		int i2 = indx[s2];
		cout << endl << endl;
		string row1 (20,'-');
		string row2 (10,'-');
		string row3 (5,'-');
		printf ("%-20s %-20s %-10s %-5s\n","From","To","Route","Miles");
		cout << row1 << " " << row1 << " " << row2 << " " << row3 << endl;
		int u = i1;
		int v = i2;
		stack<int> ans;
		while (u != v) {
			ans.push(p[u][v]);
			v = p[u][v];
		}
		u = ans.top();
		ans.pop();
		while (!ans.empty()) {
			v = ans.top();
			ans.pop();
			printf("%-20s %-20s %-10s %5d\n", rindx[u].c_str(), rindx[v].c_str(), arr[u][v].name.c_str(), arr[u][v].c);
			u = v;
		}
		v = i2;
		printf("%-20s %-20s %-10s %5d\n", rindx[u].c_str(), rindx[v].c_str(), arr[u][v].name.c_str(), arr[u][v].c);
		printf("%-20s %-20s %-10s %5s\n"," "," "," ",row3.c_str());
		printf("%-20s %-20s %-10s %5d\n"," "," ","Total", arr[i1][i2].c);
		getline(cin,s);
	}
    
    return 0;
}
