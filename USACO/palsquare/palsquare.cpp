/*
ID: yuanmax1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

string baseConverter(int B, int N) {
	char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
	int remainder;
	string result;
	string temp = "";
	while (N > 0) {
		remainder = N%B;
		if (remainder >= 10) {
			remainder = letters[remainder-10];
			result += remainder;
		}
		else {
			ostringstream oss;
			oss << remainder;
			result += oss.str();
			//result += to_string(remainder);
		}
		
		
		N = N/B;
	}
	reverse(result.begin(),result.end());
	return result;
	
}


int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int B;
    fin >> B;
	
	for (int N = 1; N <= 300; N++) {
		string newNum = baseConverter(B,N);
		string square = baseConverter(B,pow(N,2));
		string squareRev = square;
		reverse(squareRev.begin(),squareRev.end());
		if (square == squareRev) {
			fout << newNum << " " << square << endl;
			cout << newNum << " " << square << endl;
		}
	}
	
	
	
	
    return 0;
}