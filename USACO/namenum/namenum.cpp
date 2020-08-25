/*
ID: yuanmax1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict("dict.txt");
    string SerialNum;
    fin >> SerialNum;
    string name;
    string nameSerial = "";
    string output = "";
    int counter = 0;
    for (int i = 0; i < 4617; i++) {
    	dict >> name;
    	for (int j = 0; j < name.size(); j++) {
    		if ((name[j] == 'A') || (name[j] == 'B') || (name[j] == 'C')) {
    			nameSerial += "2";
    		}
    		else if ((name[j] == 'D') || (name[j] == 'E') || (name[j] == 'F')) {
    			nameSerial += "3";
    		}
    		else if ((name[j] == 'G') || (name[j] == 'H') || (name[j] == 'I')) {
    			nameSerial += "4";
    		}
    		else if ((name[j] == 'J') || (name[j] == 'K') || (name[j] == 'L')) {
    			nameSerial += "5";
    		}
    		else if ((name[j] == 'M') || (name[j] == 'N') || (name[j] == 'O')) {
    			nameSerial += "6";
    		}
    		else if ((name[j] == 'P') || (name[j] == 'R') || (name[j] == 'S')) {
    			nameSerial += "7";
    		}
    		else if ((name[j] == 'T') || (name[j] == 'U') || (name[j] == 'V')) {
    			nameSerial += "8";
    		}
    		else if ((name[j] == 'W') || (name[j] == 'X') || (name[j] == 'Y')) {
    			nameSerial += "9";
    		}
    		
    	}
    	if (nameSerial == SerialNum) {
    		fout << name << endl;
    		//cout << name << endl;
    	}
    	else {
    		counter++;
    	}
    	nameSerial = "";
    	
    }
    if (counter == 4617) {
    	fout << "NONE" << endl;
    }
    
    
    
    
    return 0;
}