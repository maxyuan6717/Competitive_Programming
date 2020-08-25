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
#define fin cin
#define fout cout

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int a,b,n,P;
bool all;
vector<string> papers;
//ifstream fin ("in");
//ofstream fout("out");

void rec(int indx, int left, vector<string> v) {
	if (!left) {
		for (int i = 0; i < v.size(); i++) {
			fout << v[i];
			if (i != v.size()-1) fout << ", ";
		}
		fout << endl;
		return;
	}
	for (int i = indx; i <= P-left; i++) {
		v.push_back(papers[i]);
		rec(i+1,left-1,v);
		v.pop_back();
	}
}

int main() {
	int T;
	fin >> T;
	fin.ignore();
	string s,str;
	getline(fin,s);
	for (int t = 0; t < T; t++) {
		all = a = b = n = 0;
		papers.clear();
		getline(fin,s);
		stringstream ss(s);
		if (s.size() > 2) {
			ss >> a >> b;
		}
		else {
			ss >> str;
			if (str[0] == '*') all = 1;
			else {
				stringstream ss2(str);
				ss2 >> n;
			}
		}
		while (getline(fin,s),s!="") {
			papers.push_back(s);
		}
		P = papers.size();
		if (all) {
			for (int i = 1; i <= P; i++) {
				fout << "Size " << i << endl;
				vector<string> v;
				rec(0,i,v);
				fout << endl;
			}
		}
		else if (n) {
			fout << "Size " << n << endl;
			vector<string> v;
			rec(0,n,v);
			fout << endl;
		}
		else {
			for (int i = a; i <= b; i++) {
				fout << "Size " << i << endl;
				vector<string> v;
				rec(0,i,v);
				fout << endl;
			}
		}
		if (t != T-1) fout << endl;
	}
    return 0;
}
