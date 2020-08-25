/*
ID: yuanmax1
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");
    int P;
    int cow[52];
    int path[52][52];
    for (int i = 0; i < 52; i++) {
    	for (int j = 0; j < 52; j++) {
    		path[i][j] = 1000000;
    	}
    }
    //cout << INT_MAX << endl;
    int ans1 = 1000000;
    char ans2;
    int ans3;
    fin >> P;
    char c1, c2;
    int x,y;
    int dist;
    for (int i = 0; i < P; i++) {
    	fin >> c1 >> c2 >> dist;
    	//cout << int(c1) << endl;
    	if (isupper(c1) && c1 != 'Z') {
    		cow[int(c1)-65] = 1;	
    		x = int(c1)-65;
    		
        }
        else if (c1 == 'Z') {
        	x = int(c1)-65;
        }
        else if (!isupper(c1)){
        	//cout << c1 << endl;
        	x = int(c1) - 71;
        	//cout << x << endl;
        }
        if (isupper(c2) && c2 != 'Z') {
        	cow[int(c2)-65] = 1;
        	y = int(c2)-65;
        	
        }
        else if (c2 == 'Z') {
        	y = int(c2)-65;
        }
        else if (!isupper(c2)){
        	y = int(c2) - 71;
        	
        }
        //cout << x << " " << y << " " << path[x][y] << endl;
        if (dist <= path[x][y]) {
        	path[x][y] = dist;
        	path[y][x] = dist;
        }	
     }
     for (int i = 0; i < 52; i++) {
     	for (int j = 0; j < 52; j++) {
     		for (int k = 0; k < 52; k++) {
     			if (path[j][i] + path[i][k] < path[j][k]) {
     				path[j][k] = path[j][i] + path[i][k];
     			}
     		}
     	}
     }
     cout << path[0][25] << endl;
     for (int i = 0; i < 52; i++) {
     	//cout << path[i][25] << endl;
     	if (path[i][25] < ans1 && cow[i] == 1) {
     		
     		ans1 = path[i][25];
     		ans2 = i+65;
     	}
     }
     
     
     
     /*for (int i = 0; i < 52; i++) {
     	for (int j = 0; j < 52; j++) {
     		cout << path[i][j] << " ";
     	}
     	cout << endl;
     }  */ 
     /*for (int i = 0; i < 52; i++) {
     	cout << cow[i] << endl;
     }*/
     fout << ans2 << " " << ans1 << endl;
    
    return 0;
}