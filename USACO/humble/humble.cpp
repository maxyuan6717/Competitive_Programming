/*
ID: yuanmax1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
    int K, N;
    set<long int> h;
    set<long int>::iterator iter;
    int p[101];
    int done = 0;
    int num;
int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");	

    fin >> K >> N;
    for (int i = 0; i < K; i++) {
    	fin >> p[i];	
    		
    	h.insert(p[i]);
    }
    for (int i = 0; i < K; i++) {
    	iter = h.begin();
    	while(1) {
    		num = (*iter) * p[i];
    		if (num < 0) {
    			break;
    		}
    		if (h.size() > N) {
    			h.erase(--h.end());
    			if (num > (*(--h.end()))) {	
    				break;
    			}	
    				
    		}   		
    		h.insert(num);  	
    		iter++;	
    	}
    }
    /*for (iter = h.begin(); iter != h.end(); iter++) {
    	cout << *(iter) << " ";
    }
    cout << endl;*/
    fout << *(--h.end()) << endl;
    
    return 0;
}