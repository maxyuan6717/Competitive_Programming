/*
ID: yuanmax1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int numdigits = 0;
int nums[10];
int check[10];
int num;
int stop = 0;
int ans = 0;
void numdig(int b) {
	numdigits = 0;
    while (b > 0) {
    	b/=10;
    	numdigits++;
    }
} 
void digits(int a) {
    for (int i = numdigits; i >= 1; i--) {
    	nums[i] = a%10;
    	a/=10;
    	check[i] = 0;
    }
}
int checkDig() {
	for (int i = 1; i <= numdigits; i++) {
		for (int j = i+1; j <= numdigits; j++) {
			if (nums[i] == nums[j]) {
				return 0;
			}
		}
	}
	return 1;
}
void reset() {
	for (int i = 1 ; i <= numdigits; i++) {
		nums[i] = 0;
		check[i] = 0;
	}
}	
void numCheck() {
	//cout << num << endl;
	//cout << num << endl;
    int curr = 1;
    //check[curr] = 0;
    int counter = 1;
    if (checkDig() == 0) {
    	reset();
    	num++;
    	digits(num);
    	numdig(num);
    }
    else {
    for (int i = 0; i < numdigits; i++) {
    	curr = (curr + nums[curr])%numdigits;
    	if (curr == 0) {
    		curr = numdigits;
    	}
    	//cout << num << " " << curr << endl;
    	if (check[curr] != 0) {
    		reset();
    		num++;
    		digits(num);
    		numdig(num);
    		counter = 1;
    		break;
    	}
    	else {
    		counter++;
    		check[curr] = 1;
    	}
    }
    if (counter == numdigits+1 && curr == 1) {
    	ans = num;
    	stop = 1;
    }
    }
}
int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    fin >> N;
    num = N + 1;
    digits(num);
    numdig(num);
    //cout << numdigits << endl;
    while (stop == 0) {
    	numCheck();
    }
    fout << ans << endl;
    /*cout << numdigits << endl;
    for (int i = 1; i <= numdigits; i++) {
    	cout << nums[i] << " ";
    }
    cout << endl;*/
    
    
    return 0;
}