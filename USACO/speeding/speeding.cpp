/*
ID: yuanmax1
PROG: CHANGE
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int M;
	int road[101];
	int seg;
	int spe;
	int counter = 0;
	int max = 0;
	int num;
    //for (int x = 1; x <= 10; x++) {
    	//string str = to_string(x);
    	//ifstream fin (str+".in");
    	ifstream fin ("speeding.in");
    	ofstream fout ("speeding.out");
    	fin >> N >> M;
    	for (int i = 0; i < N; i++) {
    		fin >> seg >> spe;
    		for (int j = counter; j < counter + seg; j++) {
    			road[j] = spe;
    			//cout << road[j] << " ";
    		}
    		counter += seg;
    	}
    	counter  = 0;
    	for (int i = 0; i < M; i++) {
    		fin >> seg >> spe;
    		for (int j = counter; j < counter + seg; j++) {
    			//cout << spe << " " << road[j] << endl;
    			if (spe > road[j]) {
    				
    				if ((spe-road[j]) > max) {
    					//cout << spe << " " << road[j] << " " << max << endl;
    					max = spe-road[j];
    				}
    			}
    			//cout << max << endl;
    		}
    		counter += seg;
    	}	
    	fout << max << endl;
    	/*cout << max << " ";
    	ifstream gin (str+".out");
    	gin >> num;
    	cout << num << endl;
    	counter = 0;
    	max = 0;*/

    return 0;
}