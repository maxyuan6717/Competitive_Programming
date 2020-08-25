/*
ID: yuanmax1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int a , b;
//int ans[20000000];
bool prime(int num) {
	int root = sqrt(num);
	for (int i = 2; i <= root +1; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
/*void check(int num) {
	if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
}*/
int numDigits(int x)  
{  
    x = abs(x);  
    return (x < 10 ? 1 :   
    	(x < 100 ? 2 :   
    	(x < 1000 ? 3 :   
    	(x < 10000 ? 4 :   
    	(x < 100000 ? 5 :   
    	(x < 1000000 ? 6 :   
    	(x < 10000000 ? 7 :  
    	(x < 100000000 ? 8 :  
    	(x < 1000000000 ? 9 :  
    	10)))))))));  
}

void eight() {

	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				for (int d4 = 0; d4 <= 9; d4++) {
					int num = 10000000 * d1 + d1 + 1000000 * d2 + 10 * d2 + 100000 * d3 + 100 * d3 + 10000 * d4 + 1000 * d4;
					if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
				}
			}
		}
	}
}
void seven() {

	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				for (int d4 = 0; d4 <= 9; d4++) {
					int num =  1000000 * d1 + d1 + 100000 * d2 + 10 * d2 + 10000 * d3 + 100 * d3 + 1000 * d4;
					if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
				}
				
			}
		}
	}
}
void six() {

	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				
				int num =  100000 * d1 + d1 + 10000 * d2 + 10 * d2 + 1000 * d3 + 100 * d3;
				if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
				
			}
		}
	}
}
void five() {

	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				int num =  10000 * d1 + d1 + 1000 * d2 + 10 * d2 + 100 * d3;	
				if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
			}
		}
	}
}
void four() {

	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
				int num = 1000 * d1 + d1 + 100 * d2 + 10 * d2;
				if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
		}
	}
}
void three() {

	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
				int num = 100 * d1 + d1 + 10 * d2;	
				if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
		}
	}
}
void two() {

	for (int d1 = 1; d1 <= 9; d1+=2) {
		int num = 11 * d1;
		if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
	}
}
void one() {
	for (int i = 1; i <=9; i++) {
		int num = i;
		if (num >= a && num <= b && prime(num)) {
		cout << num << endl;
		
	}
	}
}

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
	
	fin >> a >> b;
	int digA = numDigits(a);
	int digB = numDigits(b);
	for (int i = digA; i <= digB; i++) {
		/*if (i == 1) one();
		else if (i == 2) two();
		else if (i == 3) three();
		else if (i == 4) four();
		else if (i == 5) five();
		else if (i == 6) six();
		else if (i == 7) seven();
		else if (i == 8) eight();*/
		if (i == 1) {
			for (int i = 1; i <=9; i++) {
		int num = i;
		if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
	}
		}
		else if (i == 2) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
		int num = 11 * d1;
		if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
	}
		}
		else if (i == 3) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
				int num = 100 * d1 + d1 + 10 * d2;	
				if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
		}
	}
		}
		else if (i == 4) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
				int num = 1000 * d1 + d1 + 100 * d2 + 10 * d2;
				if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
		}
	}
		}
		else if (i == 5) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				int num =  10000 * d1 + d1 + 1000 * d2 + 10 * d2 + 100 * d3;	
				if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
			}
		}
	}
		}
		else if (i == 6) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				
				int num =  100000 * d1 + d1 + 10000 * d2 + 10 * d2 + 1000 * d3 + 100 * d3;
				if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
				
			}
		}
	}
		}
		else if (i == 7) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				for (int d4 = 0; d4 <= 9; d4++) {
					int num =  1000000 * d1 + d1 + 100000 * d2 + 10 * d2 + 10000 * d3 + 100 * d3 + 1000 * d4;
					if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
				}
				
			}
		}
	}
		}
		else if (i == 8) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				for (int d4 = 0; d4 <= 9; d4++) {
					int num = 10000000 * d1 + d1 + 1000000 * d2 + 10 * d2 + 100000 * d3 + 100 * d3 + 10000 * d4 + 1000 * d4;
					if (num >= a && num <= b && prime(num)) {
		fout << num << endl;
		
	}
				}
			}
		}
	}
		}
	}
	/*for (int i = 0; i <= b; i++) { 
		
		if (ans[i] == 1) {
			fout << i << endl;
		}
	}
		*/
    return 0;
}