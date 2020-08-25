/*
ID: yuanmax1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
char let[7] = {'I','V','X','L','C','D','M'};
//int nums[7] = {1,5,10,50,100,500,1000};
int ans[7] = {0,0,0,0,0,0,0};
string total = "";
void toRom(int x, int y) {
	//cout << x << " " << y << endl;
	if (x == 1) {
		ans[y*2]++;
	}
	else if (x == 2) {
		ans[y*2] += 2;
	}
	else if (x == 3) {
		ans[y*2] += 3;
	}
	else if (x == 4) {
		ans[y*2]++;
		ans[(y*2)+1]++;
	}
	else if (x == 5) {
		ans[(y*2)+1]++;
	}
	else if (x == 6) {
		ans[(y*2)+1]++;
		ans[y*2]++;
	}
	else if (x == 7) {
		ans[(y*2)+1]++;
		ans[y*2]+=2;
	}
	else if (x == 8) {
		ans[(y*2)+1]++;
		ans[y*2]+=3;
	}
	else if (x == 9) {
		ans[(y*2)]++;
		ans[(y*2)+2]++;
	}
	
}
int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    fin >> N;
    int digit = 0;
    int tens = 0;
   	for (int i = 1; i <= N; i++) {
   		int num = i;
   		while (num > 0) {
   			digit = num%10;
   			toRom(digit,tens);
   			num/=10;
   			//cout << digit<< " " << tens << endl;
   			tens++;
   			
   		}
   		tens = 0;
   	}
   	for (int i = 0; i < 7; i++) {
   		if (ans[i] != 0) {
   			fout << let[i] << " " << ans[i] << endl;
   		}
   	}
    return 0;
}