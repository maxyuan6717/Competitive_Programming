/*
ID: yuanmax1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
int sums[25];
void reset() {
	for (int i = 0; i < 25; i++) {
		sums[i] = 0;
	}
}
int V;
int G;

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    fin >> V;
    int req[V];
    for (int i = 0; i < V; i++) {
    	fin >> req[i];
    }
    fin >> G;
    int feed[G][V];
    for (int i = 0; i < G; i++) {
    	for (int j = 0; j < V; j++) {
    		fin >> feed[i][j];
    	}
    }
    /*for (int i = 0; i < G; i++) {
    	for (int j = 0; j < V; j++) {
    		cout << feed[i][j] << endl;
    	}
    }*/
    int counter = 0;
    for (int i = 1; i <= G; i++) {
    int n = G;
    int r = i;
    int nums[r];
	int count = 0;
	vector<bool> v(n);
    fill(v.begin(), v.begin()+r, true);

   	do {
       	for (int i = 0; i < n; ++i) {
        	if (v[i]) {
            	//cout << (i + 1) << " ";
            	nums[count] = i;
            	count++;
     		}
     
    	}
    	count = 0;
    	
    	//cout << nums[0] << " " << nums[1] << " " << nums[2];
		//cout << "\n";
		for (int k = 0; k < V; k++) {
    		//sums[k] = feed[i][k] + feed[j][k];
    		for (int i = 0; i < r; i++) {
    			sums[k] += feed[nums[i]][k];
    		}
    		//cout << sums[k] << endl;
    		if (sums[k] >= req[k]) {
    			counter++;
			}
    	}
    	if (counter == V) {
    		//cout << r << " ";	
    		fout << r << " ";
    		for (int i = 0; i < r-1; i++) {
    			//cout << nums[i] + 1 << " ";
    			fout << nums[i] + 1 << " ";
    		}
    		//cout << nums[r-1]+1 << endl;
    		fout << nums[r-1]+1 << endl;
			return 0;
    	}
    	reset();
    	counter = 0;
		
    } while (prev_permutation(v.begin(), v.end()));
    }
    return 0;
    
}