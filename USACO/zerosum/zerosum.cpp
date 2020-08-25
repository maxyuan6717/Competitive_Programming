/*
ID: yuanmax1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");
int num[10] = {0};
char sign[10];
int counter = 1;
int N;
int calc() {
	//cout << counter << endl;
	int sum = num[0];
	for (int i = 1; i < counter; i++) {
		if (sign[i-1] == '+') {
			sum += num[i];
		}
		else {
			sum -= num[i];
		}
	}
	return sum;
}
void printans() {
	for (int i = 0; i < counter; i++) {
		int temp = num[i];
		string ans;
		while (temp != 0) {
			//cout << temp << endl;
			ans.insert(0,1,char(temp%10+'0'));
			if (temp > 10) {
				ans.insert(0,1,' ');
			}
			temp/=10;
		}
		fout << ans;
		if (i+1 != counter) {
			fout << sign[i];
		}
	}
	fout << endl;
}
void dfs(int curr, int curs) { 
	if (curr == N + 1) {
		int sum = calc();
		if (sum == 0) {
			printans();
		}
		return;
	}
	//cout << num[counter-1] << endl;
	num[counter-1] = num[counter-1]*10 + curr;
	dfs(curr+1,curs);
	num[counter-1] = (num[counter - 1]-curr)/10;
	sign[curs] = '+';
	num[counter] = curr;
	counter++;
	dfs(curr+1,curs+1);
	sign[curs] = '-';
	dfs(curr+1,curs+1);
	num[counter] = 0;
	counter--;
}

int main() {
    fin >> N;
    num[0] = 1;
    dfs(2,0);   
    return 0;
}