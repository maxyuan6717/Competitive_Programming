/*
ID: yuanmax1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int gcf(int x, int y) {
	int high = 0;
	int num = 1;
	if (x>y) {
		high = x;
	}
	else {
		high = y;
	}
	for (int i = 1; i <= high; i++) {
		if (x%i == 0 && y%i == 0) {
			num = i;
		}
	}
	return num;
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int N;
    fin >> N;
    string all[100000];
    float allNum[100000];
    int counter = 0;
    int times = N*50;
    for (int i = 1; i <= N; i++) {
    	for (int j = i+1; j <= N; j++) {
    		if (gcf(i,j) == 1) {
    			float a = i;
    			float b = j;
    			ostringstream oss;
				oss << i;
    			all[counter] = oss.str() + "/";
    			ostringstream os;
    			os << j;
    			all[counter] += os.str();
    			float dec = a/b;
    			allNum[counter] = dec;
    			counter++;
    		}
    	}
    }
    for (int x = 0;x < times; x++) {
		for (int y = 0; y < times-1; y++) {
			if (allNum[y]>allNum[y+1])
            {
                float z=allNum[y];
                string z2 = all[y];
                allNum[y]=allNum[y+1];
                all[y] = all[y+1];
                allNum[y+1]=z;
                all[y+1] = z2;                
            }			
		}		
	}
	fout << "0/1" << endl;
    for (int i = 0; i < times; i++) {
    	if (all[i].size()!=0) {
    		fout << all[i] << endl;
    	}
    }
    fout << "1/1" << endl;

    
    
    
    return 0;
}