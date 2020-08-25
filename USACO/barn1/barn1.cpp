/*
ID: yuanmax1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int m, s, c;
    fin >> m >> s >> c;
    int stall[c];
    int gap[c-1];   
    for (int i = 0; i < c; i++) {
    	fin >> stall[i];
    }
    for (int x = 0;x < c; x++) {
		for (int y = 0; y < c-1; y++) {
			if (stall[y]>stall[y+1])
            {
                int z=stall[y];;
                stall[y]=stall[y+1];
               	stall[y+1]=z;              
            }			
		}		
	}
	for (int i = 0; i < c-1; i++) {
		cout << stall[i] << endl;
	}
	for (int i = 0; i < c-1; i++) {
		gap[i] = stall[i+1] - stall[i];
	}
	
   	int max = 0;
   	for (int i = 0; i < m-1; i++) {
   		for (int j = 0; j < c-1; j++) {
   			if (gap[j] > gap[max]) {
   				max = j;
   			}
   		}
   		gap[max] = 0;
   		max = 0;
   	}
   	
   	
   	int result = 0;
	for (int i = 0; i < c-1; i++) {
 		result += gap[i];
	}
	result += m;
	if (m >= c) {
   		result = c;
   	}
	fout << result << endl;
   	
    
    return 0;
}