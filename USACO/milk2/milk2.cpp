/*
ID: yuanmax1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");       //CHANGE CHANGE
    int N;
    fin >> N;
    int start[N];
    int end[N];
    for (int i = 0; i < N; i++) {    	
    	fin >> start[i];
    	fin >> end[i];
	}
	for (int x = 0;x < N; x++) {
		for (int y = 0; y < N-1; y++) {
			if (start[y]>start[y+1])
            {
                int z=start[y];
                int z2 = end[y];
                start[y]=start[y+1];
                end[y] = end[y+1];
                start[y+1]=z;
                end[y+1] = z2;                
            }			
		}		
	}
    int idleT = 0;
    int maxT = 0;
    int counter1 = 0;
    int counter2 = 0;   
    if (N == 1) {
    	maxT = end[0] - start[0];
    }
    else {
    	int counter1 = start[0];
    	int counter2 = end[0];
    	for (int i = 0; i < N; i++) {
    		if (start[i] <= counter2) {
    			if (end[i]>counter2) {
    				counter2 = end[i];
    			}
				if (counter2 - counter1 > maxT) {
					maxT = counter2 - counter1;
				}
    		}
    		else {
    			counter1 = start[i];
    			if (counter1-counter2 > idleT) {
    				idleT = counter1-counter2;
    			}
    			counter2 = end[i];
    		}   		
    	}    	
    }   
    fout << maxT << " " << idleT << endl;
    //cout << maxT << " " << idleT << endl;    
    return 0;
}