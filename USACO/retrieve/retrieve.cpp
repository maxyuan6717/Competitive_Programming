/*
ID: yuanmax1
PROG: retrieve
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    //for (int x = 1; x <= 10; x++) {
    	int x = 4;
    	string str = to_string(x);
    	ifstream fin (str+".in");
    	ifstream oin (str+".out");
    	ofstream fout ("retrieve.out");
    	int N,mt;
    	int num;
    	fin >> N >> mt;
    	fout << N << " " << mt << endl;
    	for (int i = 0; i < N; i++) {
    		fin >> num;
    		fout << num << endl;
    	}
    	int ans;
    	oin >> ans;
    	cout << ans << endl;
    
    //}
    return 0;
}