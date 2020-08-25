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
#include <cctype>

#define LARGE INT_MAX
#define mp make_pair
#define fout cout

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int T,P,S;
map<string,int> indx;
string rindx[16];
vector<string> topics;
int arr[16][16];
//ofstream fout ("out");

bool comp (string a, string b) {
	if (a.size() != b.size()) return a.size() > b.size();
	return a < b;
}

void rec(int ind, int left, vector<string> seq) {
	if (!left) {
		for (int i = 0; i < seq.size(); i++) {
			string st = seq[i];
			fout << st;
			if (i != seq.size()-1) fout << " ";
		}
		fout << endl;
		return;
	}
	for (int i = ind+1; i <= T-left; i++) {
		if (ind == -1) {
			seq.push_back(rindx[i]);
			rec(i,left-1,seq);
			seq.pop_back();
			continue;
		}
		bool works = 1;
		for (int j = 0; j < seq.size(); j++) {
			int i1 = indx[seq[j]];
			if (arr[i1][i]) {
				works = 0;
				break;
			}
		}
		if (!works) continue;
		seq.push_back(rindx[i]);
		rec(i,left-1,seq);
		seq.pop_back();
	}
}

int main() {
	int C;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		indx.clear();
		topics.clear();
		cin >> T >> P >> S;
		string s,s1,s2;
		for (int i = 0; i < T; i++) {
			cin >> s;
			topics.push_back(s);
			for (int j = 0; j < topics[i].size(); j++) topics[i][j] = toupper(topics[i][j]);
			for (int j = 0; j < T; j++) {
				arr[i][j] = 0;
			}
		}
		sort(topics.begin(),topics.end(),comp);
		for (int i = 0; i < T; i++) {
			indx[topics[i]] = i;
			rindx[i] = topics[i];
		}
		for (int i = 0; i < P; i++) {
			cin >> s1 >> s2;
			for (int j = 0; j < s1.size(); j++) s1[j] = toupper(s1[j]);
			for (int j = 0; j < s2.size(); j++) s2[j] = toupper(s2[j]);
			int i1 = indx[s1], i2 = indx[s2];
			arr[i1][i2] = 1;
			arr[i2][i1] = 1;
		}
		fout << "Set " << c <<":" << endl;
		vector<string> v;
		rec(-1,S,v);
		fout << endl;
	}
    return 0;
}
