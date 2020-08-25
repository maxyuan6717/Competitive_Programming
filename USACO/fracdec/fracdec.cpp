/*
ID: yuanmax1
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

int N, D, num;
string ans = "";
string tostr(int n) {
	stringstream ss;
   	ss << n;
   	return ss.str();
}
int main() {
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");
    fin >> N >> D;
    int rem[100001];
    int over;
    string beg;
    for (int i = 0; i < D; i++) {
    	rem[i] = 0-1;
    }
    if (N < D) {
    	beg = "0.";
    	cout << beg;
    	fout << beg;
    	num = N;
    }
    else if (N > D && N%D != 0) {
    	beg = tostr(N/D) + ".";
    	//cout << beg;
    	fout << beg;
    	num = N%D;
    }
    over = beg.size();
    if (N%D == 0) {
    	fout << tostr(N/D) + ".0"  << endl;
    	return 0;
    }
    int r = num%D;
    rem[r] = 0;
    int need = 0;
    int done = 0;
   	while (!done) {
   //	for (int i = 0; i < 10; i++) {
   		if ((num*10)%D != 0) {
    		ans += tostr(num*10/D);
    	}
    	else {
    		ans += tostr(num*10/D);
    		done = 1;
    	}	
    	num = (num*10)%D;
    	if (rem[num] != -1) {
    		//cout << rem[2] << endl;
    		done = 1;
    		need = 1;
    	}
    	else {
    		rem[num] = ans.size();
    	}
    	
   	}
   	//cout << ans << endl;
   	if (need == 1) {
   		ans = ans.substr(0,rem[num]) + "(" + ans.substr(rem[num],ans.size()) + ")";
   	}
   	if (ans.size() <= 76) {
   		//cout << ans << endl;
   		fout << ans << endl;
   	}
   	else {
   		fout << ans.substr(0,76-over) << endl;
   		//cout << ans.substr(0,76-over) << endl;
   		for (int i = 76-over; i < ans.size() + beg.size(); i += 76) {
   			//cout << ans.substr(i,76) << endl;
   			fout << ans.substr(i,76) << endl;
   		}
   	}
   	
    //cout << ans << endl;
    return 0;
}