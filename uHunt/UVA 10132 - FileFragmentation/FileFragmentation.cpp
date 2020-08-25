#include <iostream>
#include <cstdio>
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
	string s;
	int C;
	getline(cin,s);
	C = s[0]-'0';
	//cout << C << endl;
	getline(cin,s);
	//cout << s << endl;
	for (int c = 0; c < C; c++) {
		string ans;
		int ansCounter = 0;
		int total = 0;
		int num = 0;
		map<string,int> counter;
		map<int,vector<string> > ff;
		//cout << "HI - before while loop" << endl;
		while (1) {
			getline(cin,s);
			//cout << s << endl;
			if (s.empty()) break;
			//cout << "HI - within while loop" << endl;
			//cout << s << endl;
			int len = int(s.size());
			total += len;
			num++;
			ff[len].push_back(s);
		}
		//cout << "HI - after while loop" << endl;
		total /= (num/2);
		for (int i = 1; i <= total/2; i++) {
			int n1 = i;
			int n2 = total-i;
			if (ff[n1].empty() || ff[n2].empty()) continue;
			if (n1 != n2) {
				for (int j = 0; j < ff[n1].size(); j++) {
					for (int k = 0; k < ff[n2].size(); k++) {
						string s1 = ff[n1][j];
						string s2 = ff[n2][k];
						counter[s1+s2]++;
						if (counter[s1+s2] > ansCounter) {
							ansCounter = counter[s1+s2];
							ans = s1+s2;
						}
						counter[s2+s1]++;
						if (counter[s2+s1] > ansCounter) {
							ansCounter = counter[s2+s1];
							ans = s2+s1;
						}
					}
				}
			}
			else {
				for (int j = 0; j < ff[n1].size(); j++) {
					for (int k = 0; k < ff[n2].size(); k++) {
						if (j == k) continue;
						string s1 = ff[n1][j];
						string s2 = ff[n2][k];
						counter[s1+s2]++;
						if (counter[s1+s2] > ansCounter) {
							ansCounter = counter[s1+s2];
							ans = s1+s2;
						}
						counter[s2+s1]++;
						if (counter[s2+s1] > ansCounter) {
							ansCounter = counter[s2+s1];
							ans = s2+s1;
						}
					}
				}
			}
		}
		cout << ans << endl;
		if (c != C-1) cout << endl;
	}

    return 0;
}
