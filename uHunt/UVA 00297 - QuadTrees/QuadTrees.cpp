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

char c;
int len;
queue<char> q;
string s;

bool temp[32][32];
bool pic1[32][32];
bool pic2[32][32];

void color(int t, int b, int l, int r) {
	for (int i = t; i < b; i++) {
		for (int j = l; j < r; j++) {
			temp[i][j] = 0;
		}
	}
	q.pop();
}

void build(int t, int b, int l, int r) {
	q.pop();
	int nt,nb,nl,nr;
	nt = t;
	nr = r;
	nl = (l+r)/2;
	nb = (t+b)/2;
	if (q.front() == 'p') build(nt,nb,nl,nr);
	else if (q.front() == 'e') color(nt,nb,nl,nr);
	else q.pop();


	nt = t;
	nl = l;
	nr = (l+r)/2;
	nb = (t+b)/2;
	if (q.front() == 'p') build(nt,nb,nl,nr);
	else if (q.front() == 'e') color(nt,nb,nl,nr);
	else q.pop();


	nl = l;
	nb = b;
	nt = (t+b)/2;
	nr = (l+r)/2;
	if (q.front() == 'p') build(nt,nb,nl,nr);
	else if (q.front() == 'e') color(nt,nb,nl,nr);
	else q.pop();


	nb = b;
	nr = r;
	nt = (t+b)/2;
	nl = (l+r)/2;
	if (q.front() == 'p') build(nt,nb,nl,nr);
	else if (q.front() == 'e') color(nt,nb,nl,nr);
	else q.pop();
}

int main() {
	int N;
	ifstream fin("test.in");
	cin >> N;
	for (int n = 0; n < N; n++) {
		while (!q.empty()) q.pop();
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				temp[i][j] = 1;
			}
		}
		cin >> s;
		for (int i = 0; i < s.size(); i++) q.push(s[i]);
		if (q.front() == 'e') color(0,32,0,32);
		else if (q.front() == 'p') build(0,32,0,32);
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				pic1[i][j] = temp[i][j];
				temp[i][j] = 1;
			}
		}
		cin >> s;
		for (int i = 0; i < s.size(); i++) q.push(s[i]);
		if (q.front() == 'e') color(0,32,0,32);
		else if (q.front() == 'p') build(0,32,0,32);
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				pic2[i][j] = temp[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				ans += (pic1[i][j] | pic2[i][j]);
			}
		}
		cout << "There are " << ans << " black pixels." << endl;
	}
    
    return 0;
}
