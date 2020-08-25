/*
ID: yuanmax1
PROG: dualpal
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

	int remainder;
	string result;
	string temp = "";
	while (N > 0) {
		remainder = N%B;
		ostringstream oss;
		oss << remainder;
		result += oss.str();	
		N = N/B;
	}
	reverse(result.begin(),result.end());
	return result;	
}


int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N;
    fin >> N;
    int num;
    fin >> num;
    int num2 = num;
    int counter = 0;
    while (N > 0) {
		counter = 0;
    	num2 += 1;
    	for (int b = 2; b <=10; b++) {
    		string newNum = baseConverter(b,num2);
    		string rev = newNum;
			reverse(rev.begin(),rev.end());
			if (newNum == rev) {
				counter++;
				if (counter == 2) {
					N--;
					fout << num2 << endl;
					//cout << num2 << endl;
					
					
				}
			}
    	}
    
    
    }
    
    return 0;
}