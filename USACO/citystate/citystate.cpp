/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    ofstream fout ("citystate.out");
    ifstream fin ("citystate.in");
	map<string,int> str;
    string str1;
    string str2;
    int ans = 0;
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
    	fin >> str1 >> str2;
    	str1 = str1.substr(0,2);
    	if (str[str1+str2] <1) {
    		str[str1+str2] =1;
    	}
    	else {
    		str[str1+str2]++;
    	}
    	//cout << str1+str2 << " " << str2+str1 << endl;
    	/*if (str[str2+str1] == 1 && str1!=str2) {
    		//cout << str1<< " " << str2 << endl;
    		ans++;
    	}  	*/
    	if (str1!=str2) {
    		ans += str[str2+str1];
    	}
    }
    cout << ans << endl;
    fout << ans << endl;
    
    return 0;
}