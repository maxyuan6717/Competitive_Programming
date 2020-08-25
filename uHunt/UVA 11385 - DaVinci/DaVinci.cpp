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

map<int,int> indx;
int seq[101];
int fib[50];
char arr[101];

int N;

int main() {
	int T;
	cin >> T;
	fib[1] = 1;
	indx[1] = 1;
	fib[2] = 2;
	indx[2] = 2;
	for (int i = 3; i < 46; i++) {
		fib[i] = fib[i-2] + fib[i-1];
		indx[fib[i]] = i;
	}
	for (int t = 0; t < T; t++) {
		cin >> N;
		cin.ignore();
		for (int i = 0; i < 101; i++) {
			arr[i] = ' ';
		}
		string s;
		getline(cin,s);
		stringstream ss(s);
		for (int i = 0; i < N; i++) {
			ss >> seq[i];
		}
		getline(cin,s);
		int cindx = 0;
		int maxN = 0;
		for (int i = 0; i < s.size() && cindx < N; i++) {
			int num = s[i];
			if (num > 64 && num < 91) {
				int idx = indx[seq[cindx++]];
				//cout << idx << " " << s[i] << endl;
				maxN = max(maxN,idx);
				arr[idx] = s[i];
			}
		}
		for (int i = 1; i <= maxN; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
    return 0;
}
