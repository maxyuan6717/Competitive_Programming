/*
ID: yuanmax1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

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

bool check(int arr[], int N, int num) {
	for (int i = 0; i < N; i++) {
		if (num == arr[i]) {
			return true;
			break;
		}
	}
	return false;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int N;
    fin >> N;
    int digits[N];
    for (int i = 0; i < N; i++) {
    	fin >> digits[i];
    }
    int num1 = pow(N,3);
    int num2 = pow(N,2);
    int abc[num1];
    int de[num2];
    int counter = 0;
    int counter2 = 0;
    for (int a = 0; a < N; a++) {
    	for (int b = 0; b < N; b++) {
    		for (int c = 0; c < N; c++) {
    			abc[counter] = (100*digits[a]+10*digits[b]+digits[c]);
    			counter++;
    		}
    	}
    }
    for (int d = 0; d < N; d++) {
    	for (int e = 0; e < N; e++) {
    		de[counter2] = (10*digits[d]+digits[e]);
    		counter2++;
    	}
    }
    /*for (int i = 0; i< num2; i++) {
    	cout << de[i] << endl;
    }*/
    int p1;
    int p2;
    int p1d = 0;
    int p2d = 0;
    int total = 0;
    int check1 = 0;
    int check2 = 0;
    int digit1;
    int digit2;
    int digit3;
    int digit4;
    for (int i = 0; i < num1; i++) {
    	for (int j = 0; j < num2; j++) {
    		p1 = abc[i] * (de[j] % 10);
    		p2 = abc[i] * (de[j] / 10);
    		p1d = numDigits(p1);
    		p2d = numDigits(p2);
    		if (p1d == 3){
    			digit1 = p1%10;
    			digit2 = (p1/10)%10;
    			digit3 = p1/100;
    			if (check(digits,N,digit1) == 1 && check(digits,N,digit2) == 1 && check(digits,N,digit3) == 1){
    				check1 = 1;
    			}   			
    		}
    		if (p2d == 3) {
    			digit1 = p2%10;
    			digit2 = (p2/10)%10;
    			digit3 = p2/100;
    			if (check(digits,N,digit1) == 1 && check(digits,N,digit2) == 1 && check(digits,N,digit3) == 1){
    				check2 = 1;
    			}   
    		}
    		if (check1 == 1 && check2 == 1) {
    			int product = abc[i]*de[j];
    			digit1 = product%10;
    			digit2 = (product/10)%10;
    			digit3 = (product/100)%10;
    			digit4 = product/1000;
    			//cout << product << endl;
    			if (check(digits,N,digit1) == 1 && check(digits,N,digit2) == 1 && check(digits,N,digit3) == 1 && check(digits,N,digit4) == 1) {
    				total++;
    			}
    		}
    		check1 = 0;
    		check2 = 0;
    	}
    }
	fout << total << endl;
	
    
    
    return 0;
}