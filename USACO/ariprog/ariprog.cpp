/*
ID: yuanmax1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    int N;
    int M;  
    fin >> N >> M;
	int list1[125001];
	for (int p = 0; p <= M; p++) {
		for (int q = 0; q <= M; q++) {
			list1[(p*p)+(q*q)]=1;
		}
	}
	//cout << list1[49] << endl;
	int check;
	int ans = 0;
 	for (int y = 1; y <= (2*pow(M,2))/(N-1) ; y++) {
 		for (int x = 0; x <= pow(M,2) ; x++) {
 			check = 1;
 			for (int z = 0; z < N; z++) {
 				if (list1[x+z*y] == 0) {
 					check = 0;
 					break;
 				}
 			}
 			if (check == 1) {
 				fout << x << " " << y << endl;
 				ans = 1;
 			}
 		}
 	}
 	
    if (ans == 0) {
    	cout << "NONE" << endl;
      	fout << "NONE" << endl;
    }
    	
    
    
    return 0;
}