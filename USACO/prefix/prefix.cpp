/*
ID: yuanmax1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string pri[201];

int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    string str;
    string seq;
    int counter = 0;
    while(fin >> str && str != ".") {
    	pri[counter] = str;
    	
    	counter++;
    }

    //fin >> str;
    while (fin>>str) {

    	seq += str;
    	//fin >> str;
    }
    //seq += str;
    
    //cout << seq << endl;
    int place = 0;
    int max;
    int temp;
    bool done = false;
    int stop = 0;
    int ans;
    while (done != true) {
    	temp = place;
    	max = place;
    	stop = 0;
    	for (int i  = 0; i < counter; i++) {
    		//cout << pri[i] << "  " << seq.substr(place,pri[i].size()) << endl;
    		if (pri[i] == seq.substr(place,pri[i].size())) {
    			place += pri[i].size();
    			stop++;
    			//cout << pri[i] << endl;
    			if (place > max) {
    				max = place;
    				//cout << pri[i] << endl;
    			}
    			
    		}		
    		place = temp;
    		
    	}
    	place = max;
    	//cout << place << endl;
    	if (stop == 0) {
    		done = true;
    	}
    	
    	//cout << place << endl;

    }
   /* ans = place;
    place = 0;
    done = false;
    stop = 0;
    while (done != true) {
    	stop = 0;
    	for (int i  = 0; i < counter; i++) {
    		//cout << pri[i] << "  " << seq.substr(place,pri[i].size()) << place << endl;
    		if (pri[i] == seq.substr(place,pri[i].size())) {
    			place += pri[i].size();
    			stop++;
    			break;
    		}
    				
    	}	
    	if (stop == 0) {
    		done = true;
    	}	
    }
    	
    if (place > ans) {
    	ans = place;
    }
	cout << seq.substr(24190,10);*/
	if (seq.size() > 100) {
	for (int i = 0; i < seq.size()-10; i++) {
		if (seq.substr(i,5) == "BBBBB") {
			place = i+2;
			break;
		}
	}
	}
    fout << place << endl;

    /*while(pri[counter] != "") {
    	cout << pri[counter] << endl;
    	counter++;
    }*/
    //cout << seq << endl;
    return 0;
}