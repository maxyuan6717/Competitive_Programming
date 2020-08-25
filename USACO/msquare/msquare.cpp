/*
ID: yuanmax1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    ofstream fout ("msquare.out");
    ifstream fin ("msquare.in");
    string str = "12345678";
    string tar = "";
    for (int i = 0; i < 8;i++) {
    	string s;
    	fin >> s;
    	tar+=s;
    }
    map<string,int> m;
    queue<string> sq;
    queue<string> mo;
    sq.push(str);
    mo.push("");
    while(!mo.empty()) {
    	str = sq.front();
    	//cout << str << endl;
    	sq.pop();
    	string mov = mo.front();
    	mo.pop();
    	if (m[str]++) {
    		continue;
    	}
    	if (str == tar) {
    		fout << mov.size() << endl;
    		fout << mov << endl;
    		return 0;
    	}
    	sq.push(string(str.rbegin(),str.rend()));
    	mo.push(mov+"A");
    	sq.push(str.substr(3, 1) + str.substr(0, 3) + str.substr(5, 3) + str.substr(4, 1));
        mo.push(mov + "B");
 
        string a = str;
        char temp = a[1]; 
        a[1] = a[6]; 
        a[6] = a[5]; 
        a[5] = a[2]; 
        a[2] = temp;
        sq.push(a);
        mo.push(mov + "C");
    	
    } 
    
    
    
    return 0;
}