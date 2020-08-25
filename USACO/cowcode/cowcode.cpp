/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
string s(string str, long long x) {
	return (str[x-1]+str.substr(0,x-1));
}
string s2(string str, long long x) {
	return (str.substr(1,x-1)+str[0]);
}
int main() {
    ofstream fout ("cowcode.out");
    ifstream fin ("cowcode.in");
    string str;
    string str2;
    long long N;
    fin >> str >> N;
    long long n = N;
    long long si = str.size();
    while (si < n) {
    	if (n == N) {
    		n-=si;
    		str = s(str,si);
    		
    	}	
    	else {
    		n-=si; 		
			str = s(s2(str,si)+str,2*si);
			si*=2;
			
		}
		cout << str << endl;
    }
    
    fout << str[n-1] << endl;

    return 0;
}