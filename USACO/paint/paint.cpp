/*
ID: yuanmax1
PROG: paint
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int fence[101] = {0};
	int start;
	int end;
	int count = 0;
	int num;
	ifstream fin ("paint.in");
    ofstream fout ("paint.out");
    //for (int x = 1; x <= 10; x++) {
    	//string str = to_string(x);
    	//ifstream fin (str+".in");
    	for (int i = 0 ; i < 2; i++) {
    		fin >> start;
    		//cout << start <<" ";
    		fin >> end;
    		//cout << end << endl;
    		for (int j = start; j < end; j++){
    			fence[j] = 1;
    		}
    	}
    	for (int i = 0; i <= 100; i++) {
    		if (fence[i] == 1) {
    			count++;
    		}
    		fence[i] = 0;
    	}
    	fout << count << endl;
    	/*cout << count << " ";
    	ifstream gin (str+".out");
    	gin >> num;
    	cout << num << endl;
    	count = 0;*/
    
    return 0;
}