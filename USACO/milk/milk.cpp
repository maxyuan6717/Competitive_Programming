/*
ID: yuanmax1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
	int need,farmers;
	fin >> need >> farmers;
	int price[farmers];
	int amt[farmers];
	int total = 0;
	int curr = 0;
	for (int i = 0; i < farmers; i++) {
		fin >> price[i];	
		fin >> amt[i];
	}
	for (int x = 0;x < farmers; x++) {
		for (int y = 0; y < farmers-1; y++) {
			if (price[y]>price[y+1])
            {
                int z=price[y];
                int z2 = amt[y];
                price[y]=price[y+1];
                amt[y] = amt[y+1];
                price[y+1]=z;
                amt[y+1] = z2;                
            }			
		}		
	}
	if (need == 0) {
		total = 0;
	}
	while (need > 0) {
		if (amt[curr] > need) {
			total += need * price[curr];
			need = 0;
		}
		else {
			total += amt[curr] * price[curr];
			need -= amt[curr];
			curr += 1;	
			
		}
	}
	
	fout << total << endl;
	
    return 0;
}