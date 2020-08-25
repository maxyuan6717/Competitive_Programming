/*
ID: yuanmax1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int N;
    fin >> N;
    int nums[N];
    int one = 0;
    int two = 0;
    int three = 0;
    for (int i = 0; i < N; i++) {
    	fin >> nums[i];
    	if (nums[i] == 1) {
    		one++;
    	}
    	else if (nums[i] == 2) {
    		two++;
    	}
    	else {
    		three++;
    	}
    }
    int error21 = 0;
    int error31 = 0;
    int error12 = 0;
    int error32 = 0;
    int error13 = 0;
    int error23 = 0;
    for (int i = 0; i < one; i++) {
    	if (nums[i] == 2) {
    		error21++;
    	}
    	else if (nums[i] == 3) {
    		error31++;
    	}
    } 
    for (int i = one; i < one+two; i++) {
    	if (nums[i] == 1) {
    		error12++;
    	}
    	else if (nums[i] == 3) {
    		error32++;
    	}
    } 
    for (int i = one+two; i < N; i++) {
    	if (nums[i] == 2) {
    		error23++;
    	}
    	else if (nums[i] == 1) {
    		error13++;
    	}
    } 
    int counter = 0;
    if (error21 > 0) {
    	if (error21 <= error12) {
    		counter += error21;
    		error12 -= error21;
    		error21 = 0;		
    	}
    	else {
    		counter += error12;
    		error21 -= error12;
    		error12 = 0;
    	}
    	if (error21 > 0) {
    		counter += 2*error21;
    		error13 -= error21;
    		error32 -= error21;
    		error21 = 0;
    	}
    }
    if (error31 > 0) {
    	if (error31 <= error13) {
    		counter += error31;
    		error13 -= error31;
    		error31 = 0;
    	}
    	else {
    		counter += error13;
    		error31 -= error13;
    		error13 = 0;
    	}
    	if (error31 > 0) {
    		counter += 2*error31;
    		error12 -= error31;
    		error31 = 0;
    	}
    }
    if (error32 > 0) {
    	counter += error32;
    }
    fout << counter << endl;
    return 0;
}