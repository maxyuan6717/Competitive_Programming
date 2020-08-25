/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("square.out");
    ifstream fin ("square.in");
    int rect1[4];
    int rect2[4];
   	int left = 0;
   	int maxw = 0;
   	int minw = 11;
   	int maxh = 0;
   	int minh = 11;
   	int width;
   	int height;
   	
    
    for (int i = 0; i < 4; i++) {
    	fin >> rect1[i];
    	//cout << rect1[i] << " ";
    }
    //cout << endl;
    for (int i = 0; i < 4; i++) {
    	fin >> rect2[i];	
    	//cout << rect2[i] << " ";
    }
    //cout << endl;
    //cout << rect1[0] << " " << rect2[2] << endl;
    if (rect1[2] > maxw) {
    	maxw = rect1[2];
    }
    if (rect2[2] > maxw) {
    	maxw = rect2[2];
    }
    if (rect1[0] < minw) {
    	minw = rect1[0];
    }
    if (rect2[0] < minw) {
    	minw = rect2[0];
    }
    width = maxw - minw;
    
    if (rect1[3] > maxh) {
    	maxh = rect1[3];
    }
    if (rect2[3] > maxh) {
    	maxh = rect2[3];
    }
    if (rect1[1] < minh) {
    	minh = rect1[1];
    }
    if (rect2[1] < minh) {
    	minh = rect2[1];
    }
    height = maxh - minh;
    
    if (width >= height) {
    	fout << width*width << endl;
    }
    else {
    	fout << height*height << endl;
    }
    
    //cout << maxh << " " << minh << " " <<  height << endl;
    //cout << maxw << " " << minw << " " <<  width << endl;
    
    
    return 0;
}