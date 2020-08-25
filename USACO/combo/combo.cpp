/*
ID: yuanmax1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int N;
    fin >> N;
    int farm[3];
    int master[3];
    fin >> farm[0] >> farm[1] >> farm[2];
    fin >> master[0] >> master[1] >> master[2];
    /*for (int i = 0; i < 3; i++) {
    	cout << master[i] << endl;
    }*/
    int lowf[3];
    int highf[3];
    int lowm[3];
    int highm[3];
    /*for (int i = 0; i< 3; i++) {
    	if (farm[i] > 2) {
    		lowf[i] = farm[i]-2;
   		 }
    	else {
    		lowf[i] = 50 + (farm[i]-2);
    	}
    	if (farm[i] < 49) {
    		highf[i] = farm[i] + 2;
    	}
    	else {
    		highf[i] = (farm[i] + 2) - 50;
    	}
    	if (master[i] > 2) {
    		lowm[i] = master[i]-2;
   		 }
    	else {
    		lowm[i] = 50 + (master[i]-2);
    	}
    	if (master[i] < 49) {
    		highm[i] = master[i] + 2;
    	}
    	else {
    		highm[i] = (master[i] + 2) - 50;
    	}
    }*/

    int total = 0;
    for (int x = 1; x <= N; x++) {
    	for (int y =1; y <= N; y++) {
    		for (int z = 1; z <= N; z++) {
    			if ((x >= farm[0] - 2 && x <= farm[0]+2) || (x >= farm[0] + N -2 || x <= farm[0]-N+2)){
    				if ((y >= farm[1] - 2 && y <= farm[1]+2)  || (y >= farm[1] + N -2 || y <= farm[1]-N+2)){
    					if ((z >= farm[2] - 2 && z <= farm[2]+2) || (z >= farm[2] + N -2 || z <= farm[2]-N+2)){
    						//cout << x << " " << y << " " << z << endl;
    						total++;
    						continue;
    					}
    				}
    			}
    			if ((x >= master[0] - 2 && x <= master[0]+2) || (x >= master[0] + N -2 || x <= master[0]-N+2)){
    				if ((y >= master[1] - 2 && y <= master[1]+2) || (y >= master[1] + N -2 || y <= master[1]-N+2)){
    					if ((z >= master[2] - 2 && z <= master[2]+2) || (z >= master[2] + N -2 || z <= master[2]-N+2)){
    						//cout << x << " " << y << " " << z << endl;
    						total++;
    						continue;
    					}
    				}
    			}
    			
    		}
    	}
    }
    
    fout << total << endl;
    return 0;
}