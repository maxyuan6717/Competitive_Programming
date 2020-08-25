/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
string cards[100][2];

int main() {
    ofstream fout ("blocks.out");
    ifstream fin ("blocks.in");
    fin >> N;
    char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int val[26] = {0};
    int temp[2][26] = {0};
    string str1;
    string str2;
    string str;
    for (int i = 0; i < N; i++) {
    	fin >> cards[i][0] >> cards[i][1];
    	//cout << cards[i][0] << " " << cards[i][1] << endl;
    }
    for (int i = 0; i < N; i++) {
    	str1 = cards[i][0];
    	str2 = cards[i][1];
    	for (int j = 0; j < 2; j++) {
    		str = cards[i][j];
    		for (int a = 0; a < str.size(); a++) {
    			temp[j][int(str[a])-97]++;
    		}
    	}	
    	for (int j = 0; j < 26; j++) {
    		if (temp[0][j] >= temp[1][j]) {
    			val[j] += temp[0][j];
    		}
    		else {
    			val[j] += temp[1][j];
    		}
    	}
    	for (int a = 0; a < 2; a++) {
    		for (int b = 0; b < 26; b++) {
    			temp[a][b] = 0;
    		}
    	}
    }
    for (int i = 0; i < 26; i++) {
    	fout << val[i] << endl;
    }
    //cout << int('b') << endl;    
    
    
    return 0;
}