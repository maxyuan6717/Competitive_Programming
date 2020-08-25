/*
ID: yuanmax1
PROG: gift1
LANG: C++                
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string members[10];
int NG = 1;
int NP;
int money[10];
int moneyAmount;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> NP;
    for (int i=0; i<NP; i++) {
    	fin >> members[i];
    	money[i] = 0;
    }
    for (int i = NP; i>0; i--) {
    	string sender;
    	string reciever;
    	int senderNum;
    	int recieverNum;
    	fin >> sender;
    	for (int i = 0; i < NP; i++) {
    		if (sender == members[i]) {
    			senderNum = i;
    		}    	
    	}
    	fin >> moneyAmount;
    	fin >> NG;
    	for (int i = 0; i < NG; i++) {
    		fin >> reciever;
    		for (int i = 0; i < NP; i++) {
    			if (reciever == members[i]) {
    				recieverNum = i;
    			}
    		}    
    		money[senderNum] -= int(moneyAmount/NG);
    		money[recieverNum] += int(moneyAmount/NG);	
    	}
    	
    	
    }
    for (int i = 0; i<NP; i++) {
    	fout << members[i] << " " << money[i] << endl;
    }
    
    return 0;
}